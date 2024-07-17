#include "algos/strings/naive.h"
#include "structs/linear/linked_list.h"
#include "unity.h"

struct linked_list_s* ll_naive;
void setUpNaive(void) {};

void tearDownNaive(void) {};

void test_naive(void) {
  setUpNaive();
  ll_naive = naive("hello test test apple test apple", "apple");
  TEST_ASSERT_EQUAL(ll_naive->length, 2);
  TEST_ASSERT_EQUAL(ll_naive->head->value, 16);
  TEST_ASSERT_EQUAL(ll_naive->tail->value, 27);
  ll_naive = naive("hello avocado test avocado test apple avocado", "avocado");
  TEST_ASSERT_EQUAL(ll_naive->length, 3);
  TEST_ASSERT_EQUAL(ll_naive->head->value, 6);
  TEST_ASSERT_EQUAL(ll_naive->head->next->value, 19);
  TEST_ASSERT_EQUAL(ll_naive->tail->value, 38);
  ll_naive = naive("hi hi hello hi hello hi hi hello", "hello");
  TEST_ASSERT_EQUAL(ll_naive->length, 3);
  TEST_ASSERT_EQUAL(ll_naive->head->value, 6);
  TEST_ASSERT_EQUAL(ll_naive->head->next->value, 15);
  TEST_ASSERT_EQUAL(ll_naive->tail->value, 27);
  tearDownNaive();
}
