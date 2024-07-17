#include "algos/searching/linear_search.h"
#include "unity.h"

int bs_arr[] = {1, 3, 5, 8, 6, 2, 4, 9, 7, 0};

void setUpLinearSearch(void) {};
void tearDownLinearSearch(void) {};

void test_linear_search(void) {
  setUpLinearSearch();
  TEST_ASSERT_EQUAL(5, linear_search(bs_arr, sizeof(bs_arr) / sizeof(bs_arr[0]), 2));
  TEST_ASSERT_EQUAL(-1, linear_search(bs_arr, sizeof(bs_arr) / sizeof(bs_arr[0]), -1));
  tearDownLinearSearch();
};
