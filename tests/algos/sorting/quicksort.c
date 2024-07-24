#include "algos/sorting/quicksort.h"

#include "unity.h"

void setUpQuickSort() {}
void tearDownQuickSort() {}

void test_quicksort(void) {
  setUpQuickSort();
  int *arr[10] = {
      (int *)110, (int *)130, (int *)115, (int *)105, (int *)90,
      (int *)135, (int *)10,  (int *)30,  (int *)15,  (int *)5,
  };
  quicksort((int **)arr, sizeof(arr) / sizeof(arr[0]));
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
