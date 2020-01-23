#include "fun.h"

#include <assert.h>

int powerOf(int e, int power) {
  assert(power >= 0);
  if (power == 0)
    return 1;
  if (power == 1)
    return e;
  return e * powerOf(e, power - 1);
}

#ifndef NO_TESTING
#include "test/helpers.h"

namespace {
using namespace ::testing;

TEST(PrivateTest, easy) {
  EXPECT_EQ(powerOf(5, 2), 25);
};
}
#endif
