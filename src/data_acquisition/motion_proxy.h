//
// Created by x on 2022/6/9.
//

#ifndef GDS9_MOTION_PROXY_H
#define GDS9_MOTION_PROXY_H

#include "axiscontrol.h"
#include "string"
#include "vector"

/**
 * @details
 * 1.单例模式，提供全局访问接口
 * 2.解析并存储PLC数据到xAxis、yAxis、zAxis三个类中
 * 3.提供PLC IP设置接口
 */
class MotionProxy : public TS7Client {
private:
    MotionProxy();
    ~MotionProxy() override;

    const char* ip_;
public:
    const char* getIp() const;
    void setIp(const char *ip);

    static MotionProxy* getMotionProxy() {
        static MotionProxy mp;
        return &mp;
    }
    int Connect() override;

public:
    xAxis x_axis_;
    yAxis y_axis_;
    zAxis z_axis_;
    byte read_buffer_[64];
    void synAxisState();
    void dataProcess(std::vector<std::string> db_data);

    volatile bool termite_flag = false; // true 时终止同步
    unsigned int flush_time = 1; // 同步刷新时间，单位/秒
};


#endif//GDS9_MOTION_PROXY_H
