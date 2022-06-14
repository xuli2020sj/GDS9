//
// Created by x on 2022/6/12.
//

#ifndef GDS9_UTIL_H
#define GDS9_UTIL_H


#include <winsock.h>
#include "algorithm"

/**
 * 提供可复用的函数功能
 */
namespace util {
    /**
     * 联合体提供浮点数与二进制数据转换功能
     */
    typedef union data {
        float f_data;
        char c_data[4];
        unsigned int i_data;
    } float_data;

    /**
     * 32位二进制转换为IEEE单精度浮点数数据
     * @param str
     * @return
     */
    static float binToFloat(const std::string& str) {
        if (str.size() != 32) return 0.0;
        util::float_data d;
        d.c_data[3] = stoi(str.substr(0, 8), nullptr, 2);
        d.c_data[2] = stoi(str.substr(8, 8), nullptr, 2);
        d.c_data[1] = stoi(str.substr(16, 8), nullptr, 2);
        d.c_data[0] = stoi(str.substr(24, 8), nullptr, 2);
        return d.f_data;
    }

    /**
     * @brief 八位二进制数转字符串,高位补零
     * @param num 无符号八位整数
     * @return 八位二进制数字符串
     */
    static std::string convertToBase2(uint8_t num) {
        if (num == 0) return "00000000";
        std::string res;
        while (num > 0) {
            res.push_back(num % 2 + '0');
            num /= 2;
        }
        while (res.size() < 8) {
            res.push_back('0');
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

    /**
     *
     * @param str_float 浮点数字符串
     * @return IEEE 754 32位浮点数表示
     */
     //TODO 验证字节序
    static longword converFloatToBin(const std::string& str_float) {
        util::float_data d;
        d.f_data = std::stof(str_float);
        longword buffer = d.i_data;
//        buffer = htonl(buffer);
        return buffer;
    };
}

#endif //GDS9_UTIL_H
