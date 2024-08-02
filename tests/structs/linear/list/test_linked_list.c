#include <stdio.h>
#include <stdlib.h>

#include "structs/linear/list/linked_list.h"
#include "unity.h"

void setUpLinkedList(void) {};
void tearDownLinkedList(void) {};

void test_linked_list(void) {
  setUpLinkedList();
  struct linked_list_s *ll = malloc(sizeof(struct linked_list_s));
  ll->length = 0;
  ll->head = NULL;
  ll->tail = NULL;

  TEST_ASSERT_EQUAL(NULL, find(ll, (int *)10));
  TEST_ASSERT_EQUAL(NULL, peak_head(ll));
  TEST_ASSERT_EQUAL(NULL, peak_tail(ll));
  TEST_ASSERT_EQUAL(NULL, pop_head(ll));
  TEST_ASSERT_EQUAL(NULL, pop_tail(ll));
  TEST_ASSERT_EQUAL(NULL, find_and_delete_linked_list(ll, (int *)10));
  TEST_ASSERT_EQUAL(NULL, find_and_update_linked_list(ll, (int *)10, (int *)20));

  push_head(ll, (int *)60);
  push_head(ll, (int *)20);
  push_head(ll, (int *)40);
  push_head(ll, (int *)30);
  push_head(ll, (int *)50);
  push_head(ll, (int *)10);

  TEST_ASSERT_EQUAL(10, peak_head(ll));
  TEST_ASSERT_EQUAL(60, peak_tail(ll));

  TEST_ASSERT_EQUAL(60, find_and_update_linked_list(ll, (int *)60, (int *)10));
  TEST_ASSERT_EQUAL(10, find_and_update_linked_list(ll, (int *)10, (int *)60));
  TEST_ASSERT_EQUAL(30, find_and_update_linked_list(ll, (int *)30, (int *)40));
  TEST_ASSERT_EQUAL(40, find_and_update_linked_list(ll, (int *)40, (int *)30));

  TEST_ASSERT_EQUAL(30, find(ll, (int *)30));

  TEST_ASSERT_EQUAL(10, find_and_delete_linked_list(ll, (int *)10));
  TEST_ASSERT_EQUAL(60, find_and_delete_linked_list(ll, (int *)60));
  TEST_ASSERT_EQUAL(30, find_and_delete_linked_list(ll, (int *)30));
  TEST_ASSERT_EQUAL(NULL, find_and_delete_linked_list(ll, (int *)70));
  TEST_ASSERT_EQUAL(50, pop_head(ll));
  TEST_ASSERT_EQUAL(40, pop_head(ll));
  TEST_ASSERT_EQUAL(20, pop_head(ll));
  push_head(ll, (int *)10);
  TEST_ASSERT_EQUAL(10, pop_tail(ll));

  free_linked_list(ll);
  tearDownLinkedList();
}
