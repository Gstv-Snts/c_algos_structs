#include "unity.h"
#include "unity_internals.h"

// Unity functions
void setUp() {};
void tearDown() {};

// Declarations of tests
void test_sum(void);
void test_array(void);
void test_bit_array(void);
void test_bubble_sort(void);
void test_linear_search(void);
void test_naive(void);

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_sum);
  RUN_TEST(test_array);
  RUN_TEST(test_bit_array);
  RUN_TEST(test_bubble_sort);
  RUN_TEST(test_linear_search);
  RUN_TEST(test_naive);
  return UNITY_END();
}
