#include "algos/sorting/bubble_sort.h"
#include "unity.h"

int arr[] = {1, 3, 5, 8, 6, 2, 4, 9, 7, 0};
int sorted_arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void setUpBubbleSort(void) {};

void tearDownBubbleSort(void) {};

void test_bubble_sort(void) {
  setUpBubbleSort();
  bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));
  for (int i = 0; i < 10; i++) {
    TEST_ASSERT_EQUAL(*(sorted_arr + i), *(arr + i));
  }
  tearDownBubbleSort();
}
