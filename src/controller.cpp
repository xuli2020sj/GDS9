//
// Created by x on 2022/6/6.
//

#include "controller.h"

void controller::startReconstruction() const {
    spdlog::trace("start reconstruction_model_");
    reconstruction_model_->reconstruction_BiCGSTAB();
}
void controller::initReconstruction() {
    reconstruction_model_ = new Reconstruction({1,1,1,1,1}, {1,1,2,3}, {1,1,1},{0, -50, -100, -150});
    spdlog::trace("reconstruction_model_ object created");
}
controller::~controller() {
    delete reconstruction_model_;
}
