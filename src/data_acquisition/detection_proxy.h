//
// Created by x on 2022/6/11.
//

#ifndef GDS9_DETECTION_PROXY_H
#define GDS9_DETECTION_PROXY_H


class DetectionProxy {
private:
    DetectionProxy();
    ~DetectionProxy();
public:
    static DetectionProxy* getMotionProxy() {
        static DetectionProxy mp;
        return &mp;
    }
};


#endif//GDS9_DETECTION_PROXY_H
