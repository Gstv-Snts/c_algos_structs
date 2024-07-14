#include "algos/sum.h"
#include "assert.h"
#include "unity.h"

void setUpSum(void) {};

void tearDownSum(void) {};

void test_sum(void) {
  setUpSum();
  TEST_ASSERT_EQUAL(sum(10, 30), 40);
  tearDownSum();
}
