#include "algos/strings/naive.h"
#include "unity.h"

void setUpNaive(void) {};

void tearDownNaive(void) {};

void test_naive(void) {
  setUpNaive();
  TEST_ASSERT_EQUAL(naive("hello test test apple test", "apple"), 16);
  TEST_ASSERT_EQUAL(naive("hello avocado test apple test", "avocado"), 6);
  tearDownNaive();
}
