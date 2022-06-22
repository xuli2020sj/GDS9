//
// Created by x on 2022/6/21.
//

#include "reconstruction.h"
#include "spdlog/spdlog.h"

int main() {
    spdlog::info("Welcome to Calculation!");
//    auto grid = Reconstruction();
    auto grid = Reconstruction({1,1,1,1,1}, {1,1,2,3}, {1,1,1},{-150, -100, -50, 0});
    grid.showAllDet();
//    grid.showAllCell();
//    grid.reconstruction_BiCGSTAB();
    spdlog::info("Calculation finished");
}
