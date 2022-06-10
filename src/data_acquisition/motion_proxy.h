//
// Created by x on 2022/6/9.
//

#ifndef GDS9_MOTION_PROXY_H
#define GDS9_MOTION_PROXY_H

#include "snap7.h"

class MotionProxy {
private:
public:
    MotionProxy();
    ~MotionProxy();

    TS7Client* client;
};


#endif//GDS9_MOTION_PROXY_H
