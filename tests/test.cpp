#include <gtest/gtest.h>

int factorial(int n){
  if(n < 0) return 0;
  if(n == 1)
    return 1;
  else
    return n * factorial(n-1);
}


TEST(testOne, factorial){
  EXPECT_EQ(120, factorial(5));

}


int main(int argc, char *argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  
}
