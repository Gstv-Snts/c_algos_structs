#include <stdlib.h>

#include "algos/strings/naive.h"
#include "structs/linear/list/linked_list.h"
#include "unity.h"

void setUpNaive(void) {};

void tearDownNaive(void) {};

void test_naive(void) {
  setUpNaive();
  struct linked_list_s* ll1 = malloc(sizeof(struct linked_list_s));
  ll1->length = 0;
  ll1->head = NULL;
  ll1->tail = NULL;
  naive(ll1, "hello test test apple test apple", "apple");
  TEST_ASSERT_EQUAL(ll1->length, 2);
  TEST_ASSERT_EQUAL(16, ll1->head->value);
  TEST_ASSERT_EQUAL(27, ll1->tail->value);
  free_linked_list(ll1);
  struct linked_list_s* ll2 = malloc(sizeof(struct linked_list_s));
  ll2->length = 0;
  ll2->head = NULL;
  ll2->tail = NULL;
  naive(ll2, "hello avocado test avocado test apple avocado", "avocado");
  TEST_ASSERT_EQUAL(ll2->length, 3);
  TEST_ASSERT_EQUAL(ll2->head->value, 6);
  TEST_ASSERT_EQUAL(ll2->head->next->value, 19);
  TEST_ASSERT_EQUAL(ll2->tail->value, 38);
  free_linked_list(ll2);
  struct linked_list_s* ll3 = malloc(sizeof(struct linked_list_s));
  ll3->length = 0;
  ll3->head = NULL;
  ll3->tail = NULL;
  naive(ll3, "hi hi hello hi hello hi hi hello", "hello");
  TEST_ASSERT_EQUAL(ll3->length, 3);
  TEST_ASSERT_EQUAL(ll3->head->value, 6);
  TEST_ASSERT_EQUAL(ll3->head->next->value, 15);
  TEST_ASSERT_EQUAL(ll3->tail->value, 27);
  free_linked_list(ll3);
  tearDownNaive();
}
