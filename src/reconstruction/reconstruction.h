#include <string>
#include <Eigen/Dense>
#include <Eigen/Cholesky>
#include <Eigen/LU>
#include <Eigen/QR>
#include <Eigen/SVD>
#include <Eigen/IterativeLinearSolvers>
#include <utility>

#ifndef DETECTION_GRIDCAL_H
#define DETECTION_GRIDCAL_H

struct cell {
    size_t index;
    std::vector<int> index3d;
    double activity{0.};
    std::vector<double> pos3d;
    std::vector<double> len3d;
    cell(int _index, std::vector<int>  _index3d, std::vector<double> _pos3d, std::vector<double> _len3d)
    : index(_index), index3d(_index3d), len3d(_len3d), pos3d(_pos3d) {};
};

struct det {
    size_t index;
    std::vector<int> index3d;
    std::vector<double> pos3d;
    std::vector<double> detectionEfficiency;
    double countRate;
    det(int _index, std::vector<int> _index3d, std::vector<double> _pos3d, std::vector<double> _detectionEfficiency)
            : index(_index), index3d(_index3d), pos3d(_pos3d),
            detectionEfficiency(_detectionEfficiency), countRate(0) {}
};

class Reconstruction {
private:
    double totalActivity_BiCGSTAB = 0.;
//    double distanceFromPackage = 500;
    std::vector<double> pos = {0,500,0};
    double packageXLen = 2438;
    double packageYLen = 1926. / 2;
    double packageZLen = 1331;
    size_t gridNumOfX = 5, gridNumOfY = 4, gridNumOfZ = 3;
    size_t cellNum;
    std::vector<double> cellXLenList, cellYLenList, cellZLenList;
    std::vector<double> cellXPosList, cellYPosList, cellZPosList;
    std::vector<cell> cellList;

    void initCellList();
    void initCellPosList();
    static void initCellLenList(std::vector<double>& ratio, std::vector<double>& cellLenList, double sumLen);

    std::vector<det> detList;
    std::vector<std::vector<std::vector<double>>> effi;
    std::vector<int> indexto3d(int index);

public:
    Reconstruction();
    Reconstruction(std::vector<double> _splitX, std::vector<double> _splitY, std::vector<double> _splitZ, std::vector<double> detYPosList);
    Reconstruction(std::vector<double> _splitX, std::vector<double> _splitY, std::vector<double> _splitZ,
                   std::vector<double> detYPosList, std::vector<double> _pos, std::vector<double> _gridNum3d, std::vector<double> _packageLen3d);
    void initDetList(std::vector<double> detYPosList);
    void initDetEffi();
    double reconstruction_MLEM();
    double reconstruction_BiCGSTAB();
    void setDetEffi(std::vector<std::vector<std::vector<double>>>&& efficiency_list);
    void setDetActivity(std::vector<double>& CountRate_list);
    void showAllCell();
    void showAllDet();
    std::vector<std::vector<double>> generateMotionPath();
};

#endif //DETECTION_GRIDCAL_H
