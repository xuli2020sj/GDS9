//
// Created by x on 2022/6/6.
//

#include "controller.h"

void controller::startReconstruction() const {
    spdlog::trace("start reconstruction");
    re->reconstruction_BiCGSTAB();
}
void controller::initReconstruction() {
    re = new Reconstruction({1,1,1,1,1}, {1,1,2,3}, {1,1,1},{0, -50, -100, -150});
    spdlog::trace("reconstruction object created");
}
