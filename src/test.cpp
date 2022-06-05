#include "gtest/gtest.h"

// 此函数用于判断入参是否为正整数：如果是，则返回0；否则，返回-1
int Positive(int nNum)
{
  if (nNum > 0)
  {
    return 0;
  }
  else
  {
    return -1;
  }
}

// 测试入参2是否为正整数
TEST(PositiveTest, HandlesPositiveInput)
{
  EXPECT_EQ(Positive(2), 0);
}

// 测试入参0是否为正整数
TEST(PositiveTest, HandlesZeroInput)
{
  EXPECT_EQ(Positive(0), -1);
}

// 测试入参-2是否为正整数
TEST(PositiveTest, HandlesNegativeInput)
{
  EXPECT_EQ(Positive(-2), -1);
}

//int main(int argc, char **argv)
//{
//  // 分析gtest程序的命令行参数
//  testing::InitGoogleTest(&argc, argv);
//
//  // 调用RUN_ALL_TESTS()运行所有测试用例
//  // main函数返回RUN_ALL_TESTS()的运行结果
//  return RUN_ALL_TESTS();
//}