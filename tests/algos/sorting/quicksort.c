#include "algos/sorting/quicksort.h"

#include "unity.h"

void setUpQuickSort() {}
void tearDownQuickSort() {}

void test_quicksort(void) {
  setUpQuickSort();
  int arr[10] = {
      110, 130, 115, 105, 90, 135, 10, 30, 15, 5,
  };
  quicksort(arr, sizeof(arr) / sizeof(arr[0]));
  TEST_ASSERT_EQUAL(5, arr[0]);
  TEST_ASSERT_EQUAL(10, arr[1]);
  TEST_ASSERT_EQUAL(15, arr[2]);
  TEST_ASSERT_EQUAL(30, arr[3]);
  TEST_ASSERT_EQUAL(90, arr[4]);
  TEST_ASSERT_EQUAL(105, arr[5]);
  TEST_ASSERT_EQUAL(110, arr[6]);
  TEST_ASSERT_EQUAL(115, arr[7]);
  TEST_ASSERT_EQUAL(130, arr[8]);
  TEST_ASSERT_EQUAL(135, arr[9]);
  tearDownQuickSort();
}
