#include <stdlib.h>

#include "algos/greedy/greedy_knapsack.h"
#include "unity.h"

void setUpGreedyKnapsack(void) {};
void tearDownGreedyKnapsack(void) {};

void test_greedy_knapsack(void) {
  setUpGreedyKnapsack();
  struct item *items = malloc(sizeof(struct item) * 3);
  items[0].value = 60;
  items[0].weight = 10;
  items[1].value = 100;
  items[1].weight = 20;
  items[2].value = 120;
  items[2].weight = 30;
  TEST_ASSERT_EQUAL(220, greedy_knapsack(50, items, 3));
  tearDownGreedyKnapsack();
}
