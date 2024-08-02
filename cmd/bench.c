#include <stdlib.h>

#include "algos/sorting/bubble_sort.h"
#include "algos/sorting/quicksort.h"
#include "structs/linear/array/hash_table.h"
#include "ubench.h"

UBENCH_EX(quick, sort) {
  int nums[1000000];
  for (int i = 0; i < (sizeof(nums) / sizeof(nums[0])); i++) {
    nums[i] = rand() % 100;
  }
  UBENCH_DO_BENCHMARK() { quicksort(nums, 100); };
}

UBENCH_EX(bubble, sort) {
  int nums[1000000];
  for (int i = 0; i < (sizeof(nums) / sizeof(nums[0])); i++) {
    nums[i] = rand() % 100;
  }
  UBENCH_DO_BENCHMARK() { bubble_sort(nums, 100); };
}

UBENCH_EX(division, method) {
  int num = rand() % 100;
  UBENCH_DO_BENCHMARK() { division_method(num, 100); };
}

UBENCH_EX(multiplication, method) {
  int num = rand() % 100;
  const float CON = rand() % 100 / 3.33;
  UBENCH_DO_BENCHMARK() { multiplication_method(num, 100, CON); };
}

UBENCH_EX(dj, b2) {
  char* arr[10] = {"tiger", "lion", "elephant", "zebra", "horse", "camel", "deer", "crocodile", "rabbit", "cat"};
  UBENCH_DO_BENCHMARK() { djb2(arr[rand() % 10], 100); };
}
UBENCH_MAIN();
