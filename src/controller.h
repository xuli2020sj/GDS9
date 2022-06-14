//
// Created by x on 2022/6/6.
//

#ifndef GDS9_CONTROLLER_H
#define GDS9_CONTROLLER_H

#include "data_acquisition/motion_proxy.h"
#include "reconstruction/reconstruction.h"
#include "spdlog/spdlog.h"

enum {
    state_idle,
    state_data_acquisition,
    state_efficiency_calculation,
    state_reconstruction,
    state_finished
};

class controller {
private:
    controller()= default;
    ~controller();
public:
    controller(const controller&) = delete;
    controller& operator=(const controller&) = delete;
    static controller& getController() {
        static controller instance;
        return instance;
    }

    MotionProxy *mp_model_ = nullptr;

    Reconstruction *reconstruction_model_ = nullptr;
    void initReconstruction();
    void startReconstruction() const;
};

#endif //GDS9_CONTROLLER_H
