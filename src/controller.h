//
// Created by x on 2022/6/6.
//

#ifndef GDS9_CONTROLLER_H
#define GDS9_CONTROLLER_H

#include "reconstruction/reconstruction.h"
#include "spdlog/spdlog.h"

class controller {
private:
    controller()= default;
    ~controller() = default;
public:
    Reconstruction *re = nullptr;
    controller(const controller&) = delete;
    controller& operator=(const controller&) = delete;

    static controller& getController() {
        static controller instance;
        return instance;
    }

    void startReconstruction() const;
    void initReconstruction();

};


#endif //GDS9_CONTROLLER_H
