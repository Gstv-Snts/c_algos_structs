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
void test_linked_list(void);
void test_greedy_knapsack(void);
void test_queue(void);
void test_binary_tree(void);
void test_avl_tree(void);
void test_quicksort(void);
void test_hash_table(void);

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_sum);
  RUN_TEST(test_array);
  RUN_TEST(test_bit_array);
  RUN_TEST(test_bubble_sort);
  RUN_TEST(test_linear_search);
  RUN_TEST(test_naive);
  RUN_TEST(test_linked_list);
  RUN_TEST(test_greedy_knapsack);
  RUN_TEST(test_queue);
  RUN_TEST(test_binary_tree);
  RUN_TEST(test_avl_tree);
  RUN_TEST(test_quicksort);
  RUN_TEST(test_hash_table);
  return UNITY_END();
}
