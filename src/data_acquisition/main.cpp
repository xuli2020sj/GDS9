//
// Created by x on 2022/6/9.
//

#include "motion_proxy.h"
#include <iostream>
#include "spdlog/spdlog.h"
using namespace std;

int main() {
    spdlog::set_level(spdlog::level::trace);
    auto mp = MotionProxy::getMotionProxy();

    mp->setIp("192.168.13.13");
    cout << mp->Connect();
//    mp->synAxisState();
    std::cout << "end";
}