//
// Created by x on 2022/6/9.
//

#include "motion_proxy.h"
#include "gtest/gtest.h"

class DataAcquisitionTest : public ::testing::Test {
protected:
    void SetUp() override {
        mp = MotionProxy::getMotionProxy();
    }

    MotionProxy* mp;
    // void TearDown() override {}
};

TEST_F(DataAcquisitionTest, canConnect) {
    mp->setIp("192.168.13.13");
    EXPECT_EQ(mp->Connect(), 0);
}

TEST_F(DataAcquisitionTest, canDisconnect) {
    mp->setIp("192.168.13.13");
    EXPECT_EQ(mp->Disconnect(), 1);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}