//
// Created by x on 2022/6/9.
//

#include "motion_proxy.h"

MotionProxy::MotionProxy() {
    client = new TS7Client();
}

MotionProxy::~MotionProxy() {
    delete client;
}
