#include <hal/HAL.h>

#include "gtest/gtest.h"

//cheese is good
int main(int argc, char** argv) {
  HAL_Initialize(500, 0);
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
