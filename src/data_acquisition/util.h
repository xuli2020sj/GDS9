//
// Created by x on 2022/6/12.
//

#ifndef GDS9_UTIL_H
#define GDS9_UTIL_H

namespace util {
    /**
 * 联合体提供浮点数与二进制数据转换功能
 */
    typedef union data {
        float f_data;
        char c_data[4];
    } float_data;

}

#endif //GDS9_UTIL_H
