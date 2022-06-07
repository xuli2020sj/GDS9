//
// Created by x on 2022/6/6.
//

#include "controller.h"

void controller::startReconstruction() {
    re->reconstruction_BiCGSTAB();
}
void controller::initReconstruction() {
//    re = new Reconstruction()
}
