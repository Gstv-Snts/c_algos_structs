#include "structs/arrays/array.h"

#include <stdlib.h>

#include "unity.h"

static int* arr;

void setUpArray(void) {
  arr = (int*)malloc(10 * sizeof(int));
  for (int i = 0; i < 10; i++) {
    arr[i] = i * 10;
  }
};

void tearDownArray(void) { free(arr); };

void test_array(void) {
  setUpArray();
  int i = findArrayValueIndex(arr, 30);
  int i2 = findArrayValueIndex(arr, 12);
  int i3 = findArrayValueIndex(arr, 120);
  TEST_ASSERT_EQUAL(3, i);
  TEST_ASSERT_EQUAL(-1, i2);
  TEST_ASSERT_EQUAL(-1, i3);
  tearDownArray();
}
