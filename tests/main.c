#include "unity.h"
#include "unity_internals.h"

// Unity functions
void setUp() {};
void tearDown() {};

// Declarations of tests
void test_sum(void);
void test_array(void);
void test_bit_array(void);

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_sum);
  RUN_TEST(test_array);
  RUN_TEST(test_bit_array);
  return UNITY_END();
}
