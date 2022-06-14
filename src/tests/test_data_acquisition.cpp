//
// Created by x on 2022/6/9.
//

#include <synchapi.h>
#include <thread>
#include "motion_proxy.h"
#include "command_queue.h"
#include "gtest/gtest.h"

/**
 * 数据采集系统测试
 */
class DataAcquisitionTest : public ::testing::Test {
protected:
    void SetUp() override {
        mp = MotionProxy::getMotionProxy();
    }
    MotionProxy* mp{};
    void TearDown() override {}
};

/**
 * 连接测试
 */
TEST_F(DataAcquisitionTest, connect_disconnect_test) {
    std::string ip = "192.168.13.17";
    mp->setIp(ip.c_str());
    EXPECT_EQ(mp->Connect(), 0) << "connecting failed ip:" << ip;
    EXPECT_EQ(mp->Disconnect(), 0) << "disconnecting failed ip:" << ip;
}

/**
 * 指令测试
 */
TEST_F(DataAcquisitionTest, command_test) {
    mp->setIp("192.168.13.17");
    mp->Connect();
    StartCommand sc;
    EXPECT_EQ(sc.doMotion(mp), 0) << "start axis failed";
}

/**
 * 指令测试
 */
TEST_F(DataAcquisitionTest, complex_command_test) {
    mp->setIp("192.168.13.17");
    mp->Connect();
    std::string s = "88.88";
    StartXYZCombo xyz(s,s,s,s,s,s);
    EXPECT_EQ(xyz.doMotion(mp), 0) << "start axis failed";
}

/**
 * 数据同步测试
 */
//TEST_F(DataAcquisitionTest, syn_axis_state_test) {
//    mp->setIp("192.168.13.17");
//    mp->Connect();
//    std::thread t1(&MotionProxy::synAxisState, mp);
//    Sleep(3000);
//    mp->termite_flag = true;
//}

/**
 * 命令队列测试
 */
TEST_F(DataAcquisitionTest, command_queue_test) {
    mp->setIp("192.168.13.17");
    mp->Connect();
    CommandQueue cmd_queue;
    cmd_queue.pushBack(new initYCommand());
    cmd_queue.pushBack(new initXCommand());
    cmd_queue.pushBack(new stopCommandR());

    while (cmd_queue.peekCommand()) {
        auto cmd = cmd_queue.getCommand();
        EXPECT_EQ(cmd->doMotion(mp), 0) << "command queue execute failed";
        Sleep(50);
    }
}

/**
 * 数据转换测试
 * 测试样本
 * IEEE754浮点数 十进制 88.88 十六进制 42 B1 C2 8F
 * 二进制 0100 0010 1011 0001 1100 0010 1000 1111
 */
TEST(DataAcquisitionUtilTest, data_conversion_binToFloat_test) {
    std::string str_float = "01000010101100011100001010001111";
    auto res = util::binToFloat(str_float);
    EXPECT_GE(res, 88.87);
    EXPECT_LE(res, 88.89);
}

/**
 * 数据转换测试 八位二进制数转字符串,高位补零
 * 测试样本
 * 十进制 255
 * 二进制 1111 1111
 */
TEST(DataAcquisitionUtilTest, data_conversion_convertToBase2_test) {
    uint8_t raw_data = 255;
    auto res = util::convertToBase2(raw_data);
    EXPECT_STREQ(res.c_str(), "11111111");
}

/**
 * 数据转换测试 浮点数字符串转IEEE754二进制
 * 测试样本
 * IEEE754浮点数 十进制 88.88 十六进制 42 B1 C2 8F
 * 二进制 0100 0010 1011 0001 1100 0010 1000 1111
 */
TEST(DataAcquisitionUtilTest, data_conversion_converFloatToBin_test) {
    std::string str_float_data = "88.88";
    longword buffer = util::converFloatToBin(str_float_data);
    longword criteria = 0x42B1C28F;
    EXPECT_EQ(buffer, criteria);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}