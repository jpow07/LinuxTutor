#include <gtest/gtest.h>
#include "../src/factorial.cpp"


TEST(factorial, Positive){
  EXPECT_EQ(120, factorial(5));
  EXPECT_EQ(6, factorial(3));
}

TEST(factorial, zero){
  EXPECT_EQ(1, factorial(0));
}

TEST(testTwo, addition){
  EXPECT_EQ(4, add(2, 2));
  EXPECT_EQ(100, add(50,50));
}

TEST(testThree, greatestCommonDenominator){
  EXPECT_EQ(0, gcd(0, 5));
  EXPECT_EQ(4, gcd(8, 12));
            
}

int main(int argc, char *argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
