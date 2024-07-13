#include "algos/sum.h"
#include "assert.h"
#include "unity.h"
#include "unity_internals.h"

void setUp(void) {};
void tearDown(void) {};
void test_sum(void) { TEST_ASSERT_EQUAL(sum(10, 30), 40); }

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_sum);
  return UNITY_END();
}
