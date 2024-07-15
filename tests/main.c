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

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_sum);
  RUN_TEST(test_array);
  RUN_TEST(test_bit_array);
  RUN_TEST(test_bubble_sort);
  return UNITY_END();
}
