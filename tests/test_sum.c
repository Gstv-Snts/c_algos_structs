#include "algos/sum.h"
#include "assert.h"
#include <stdio.h>

void test_sum(void) {
  assert(sum(10, 20) == 30 && "10 + 20 = 30");
  assert(sum(-30, 10) == -20 && "-30 + 10 = -20");
  printf("sum_test passed...");
}

int main(void) {
  test_sum();
  return 0;
}
