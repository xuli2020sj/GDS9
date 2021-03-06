#include <iostream>
#include "gtest/gtest.h"
#include "reconstruction.h"

class ReconstructionTest : public ::testing::Test {
protected:
    void SetUp() override {
        re = new Reconstruction({1,1,1,1,1}, {1,1,2,3}, {1,1,1},{0, -50, -100, -150});
    }

    // void TearDown() override {}
    Reconstruction* re;
};

TEST_F(ReconstructionTest, IsEmptyInitially) {

    EXPECT_EQ(re->reconstruction_BiCGSTAB(), 0);
}

int add(int a, int b) {
    return a + b;
}

TEST(add, zero) {
    EXPECT_EQ(0, add(0, 0)) << "yes";
}

TEST(add, positive_number) {
    EXPECT_EQ(3, add(1, 2));
}

TEST(add, negative_number) {
    EXPECT_EQ(-3, add(-1, -2));
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}