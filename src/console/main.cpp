#include <iostream>

int powerOf(int e, int power) {
  assert(power >= 0);
  if (power == 0)
    return 1;
  if (power == 1)
    return e;
  return e * powerOf(e, power - 1);
}

#ifndef TESTING
int main(int, char**) {
  std::cout << "2^8 = " << powerOf(2, 8) << std::endl;
}
#endif

#ifdef TESTING
#include "gtest/gtest.h"

namespace {
using namespace ::testing;

TEST(PowerTest, easy) {
  EXPECT_EQ(powerOf(5, 3), 125);
};

TEST(PowerTest, one) {
  EXPECT_EQ(powerOf(5, 0), 1);
};

TEST(PowerTest, id) {
  EXPECT_EQ(powerOf(5, 1), 5);
};

}
#endif
