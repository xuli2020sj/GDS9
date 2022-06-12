//
// Created by x on 2022/6/9.
//

#ifndef GDS9_MOTION_PROXY_H
#define GDS9_MOTION_PROXY_H

#include "command_queue.h"
#include "axiscontrol.h"
#include "string"
#include "vector"

class MotionProxy : public TS7Client {
private:
    const char* ip_;
    MotionProxy();
    ~MotionProxy() override;
public:
    const char* getIp() const;
    void setIp(const char *ip);

    static MotionProxy* getMotionProxy() {
        static MotionProxy mp;
        return &mp;
    }
    int Connect() override;

    void executeCmdQueue(CommandQueue* cmd_queue);

public:
    xAxis x_axis_;
    yAxis y_axis_;
    zAxis z_axis_;
    byte read_buffer_[64];
    void synAxisState();
    void dataProcess(std::vector<std::string> db_data);
    static std::string convertToBase2(uint8_t num);
    static float binToFloat(const std::string& basicString);
};


#endif//GDS9_MOTION_PROXY_H
