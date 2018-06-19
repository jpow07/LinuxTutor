#include <gtest/gtest.h>
#include "../src/factorial.cpp"

TEST(testOne, factorial){
  EXPECT_EQ(120, factorial(5));
  EXPECT_EQ(6, factorial(3));
}

TEST(testTwo, addition){
  EXPECT_EQ(4, add(2, 2));
  EXPECT_EQ(100, add(50,50));
}

int main(int argc, char *argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  
}
