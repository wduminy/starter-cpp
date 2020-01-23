#include "domain/fun.h"
#include "test/helpers.h"

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
