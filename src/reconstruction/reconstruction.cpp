#include "reconstruction.h"
#include "spdlog/spdlog.h"
#include <Eigen/IterativeLinearSolvers>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>

using namespace std;

Reconstruction::Reconstruction() {
    std::vector<double> splitX = {1,1,1,1,1};
    std::vector<double> splitY = {1,1,2,3};
    std::vector<double> splitZ = {1,1,1};
    gridNumOfX = splitX.size();
    gridNumOfY = splitY.size();
    gridNumOfZ = splitZ.size();
    cellNum = gridNumOfX * gridNumOfY * gridNumOfZ;
//    effi = vector<vector<double>>(4, vector<double>(gridNumOfY, 0));

    spdlog::info("Reconstruction are separated by : {0} {1} {2} ", gridNumOfX, gridNumOfY, gridNumOfZ);
    initCellLenList(splitX, cellXLenList, packageXLen);
    initCellLenList(splitY, cellYLenList, packageYLen);
    initCellLenList(splitZ, cellZLenList, packageZLen);
    spdlog::info("init cell len success");
    initCellPosList();
    spdlog::info("init cell pos success");
    initCellList();
    spdlog::info("init cell list success");

}

Reconstruction::Reconstruction(std::vector<double> splitX, std::vector<double> splitY, std::vector<double> splitZ, std::vector<double> detYPosList) {
    gridNumOfX = splitX.size();
    gridNumOfY = splitY.size();
    gridNumOfZ = splitZ.size();
    cellNum = gridNumOfX * gridNumOfY * gridNumOfZ;

    spdlog::info("Reconstruction are separated by : {0} {1} {2} ", gridNumOfX, gridNumOfY, gridNumOfZ);
    initCellLenList(splitX, cellXLenList, packageXLen);
    initCellLenList(splitY, cellYLenList, packageYLen);
    initCellLenList(splitZ, cellZLenList, packageZLen);
    spdlog::info("init cell len success");
    initCellPosList();
    spdlog::info("init cell pos success");
    initCellList();
    spdlog::info("init cell list success");
    initDetList(detYPosList);
    spdlog::info("init det list success");
}

void Reconstruction::initCellList() {
    int i = 0;
    for (int x = 0; x < gridNumOfX; x++) {
        for (int y = 0; y < gridNumOfY; y++) {
            for (int z = 0; z < gridNumOfZ; z++) {
                cellList.emplace_back(cell(i, {x,y,z},
                                           {cellXPosList[x], cellXPosList[y], cellXPosList[z]},
                                           {cellXLenList[x], cellYLenList[y], cellZLenList[z]}));
                ++i;
            }
        }
    }
}

void Reconstruction::initCellLenList(std::vector<double>& ratio, std::vector<double>& cellLenList, double sumLen) {
    size_t len = ratio.size();
    cellLenList.resize(len);
    double sum = accumulate(ratio.begin(), ratio.end(), 0.);
    for (int i = 0; i < len; i++) {
        cellLenList[i] = ratio[i] / sum * sumLen;
    }
}

void Reconstruction::initCellPosList() {
    cellXPosList.resize(gridNumOfX);
    cellYPosList.resize(gridNumOfY);
    cellZPosList.resize(gridNumOfZ);
    cellXPosList[0] = cellXLenList[0] / 2 + pos[0];
    cellYPosList[0] = cellYLenList[0] / 2 + pos[1];
    cellZPosList[0] = cellZLenList[0] / 2 + pos[2];

    for (int i = 1; i < gridNumOfX; i++) {
        cellXPosList[i] = cellXPosList[i-1] + cellXLenList[i];
    }
    for (int i = 1; i < gridNumOfY; i++) {
        cellYPosList[i] = cellYPosList[i-1] + cellYLenList[i];
    }
    for (int i = 1; i < gridNumOfZ; i++) {
        cellZPosList[i] = cellZPosList[i-1] + cellZLenList[i];
    }
}

void Reconstruction::initDetList(std::vector<double> detYPosList) {
//    detList.resize(cellNum);
    int i = 0;
    assert(detYPosList.size() == gridNumOfY);
    for (int x = 0; x < gridNumOfX; x++) {
        for (int y = 0; y < gridNumOfY; y++) {
            for (int z = 0; z < gridNumOfZ; z++) {
//              detList[i] = det(i, {x,y,z},
//                                     {cellXPosList[x], detYPosList[y], cellZPosList[z]},
//                                    vector<double>(cellNum, 0.));
              detList.push_back(det(i, {x,y,z},
                                    {cellXPosList[x], detYPosList[y], cellZPosList[z]},
                                    vector<double>(cellNum, 0.)));
//                detList[i] = temp;
                ++i;
            }
        }
    }
    spdlog::info("init DetList success");
}

double Reconstruction::reconstruction_BiCGSTAB() {
    Eigen::MatrixXd C = Eigen::MatrixXd::Zero(cellNum, 1);
    Eigen::MatrixXd A = Eigen::MatrixXd::Zero(cellNum, 1);
//    Eigen::MatrixXd E = Eigen::MatrixXd::Zero(cellNum, cellNum);
    Eigen::SparseMatrix<double> E(cellNum, cellNum);
    for (int i = 0; i < cellNum; i++) {
        C(i) = detList[i].countRate;
    }
    spdlog::trace("count rate init success");
    for (int i = 0; i < cellNum; i++) {
        for (int j = 0; j < cellNum; j++) {
            E.insert(i,j) = detList[i].detectionEfficiency[j];
        }
    }
    spdlog::trace("Detection Efficiency init success");
    Eigen::BiCGSTAB<Eigen::SparseMatrix<double>> solver;
    solver.compute(E);
    A = solver.solve(C);
    A.resize(1, cellNum);
    totalActivity_BiCGSTAB = A.sum();
    spdlog::info("#iterations:     {0}", solver.iterations());
    spdlog::info("estimated error:   {0}", solver.error());
    std::cout << "The activity matrix is:\n" << A << std::endl;
    spdlog::info("The total activity calculated by BiCGSTAB is: {0}",  A.sum());
    return A.sum();
}

void Reconstruction::showAllCell() {
    for (auto c : cellList) {
        spdlog::info("cell index {0}, 3d index {1} {2} {3} ", c.index, c.index3d[0], c.index3d[1], c.index3d[2]);
        spdlog::info("pos {:.4f} {:.4f} {:.4f}, len {:.4f} {:.4f} {:.4f}", c.pos3d[0], c.pos3d[1], c.pos3d[2], c.len3d[0], c.len3d[1], c.len3d[2]);
    }
}

void Reconstruction::showAllDet() {
    for (auto c : detList) {
        spdlog::info("dec index {0}, 3d index {1} {2} {3} ", c.index, c.index3d[0], c.index3d[1], c.index3d[2]);
        spdlog::info("pos {:.4f} {:.4f} {:.4f}", c.pos3d[0], c.pos3d[1], c.pos3d[2]);
    }
}

double Reconstruction::reconstruction_MLEM() {
    return 0.0;
}

void Reconstruction::initDetEffi() {
    for (auto det : detList) {
        auto det_index = det.index3d;
        auto& init_effiList = effi[det_index[1]];
        auto& effiList = det.detectionEfficiency;
        for (int i = 0; i <effiList.size(); i++) {
            auto eff_index = indexto3d(i);
            if (eff_index[0] == det_index[0]) {

            }
        }
    }
}

/**
 *
 * @param efficiency_list 第一维，探测器y方向
 */
void Reconstruction::setDetEffi(std::vector<std::vector<std::vector<double>>>&& efficiency_list) {
    assert(efficiency_list.size() == 4);
    assert(pow(efficiency_list[0].size(), 2)  == gridNumOfY);
    effi = std::move(efficiency_list);
    initDetEffi();
}

void Reconstruction::setDetActivity(vector<double> &CountRate_list) {
    assert(CountRate_list.size() == detList.size());
    for (int i = 0; i < CountRate_list.size(); i++) {
        detList[i].countRate = CountRate_list[i];
    }
}

std::vector<int> Reconstruction::indexto3d(int index) {
    int x = index % (gridNumOfY * gridNumOfZ);
    index /= x;
    int y = index % gridNumOfZ;
    index /= y;
    int z = index;
    return {x, y, z};
}
