#include <stdio.h>
#include <stdlib.h>

#include "structs/linear/list/linked_list.h"
#include "unity.h"

struct linked_list_s ll;

void setUpLinkedList(void) {};
void tearDownLinkedList(void) {};

void test_linked_list(void) {
  setUpLinkedList();

  // head

  TEST_ASSERT_EQUAL(NULL, peak_head(&ll));
  TEST_ASSERT_EQUAL(NULL, peak_tail(&ll));

  TEST_ASSERT_EQUAL(NULL, ll.head);
  TEST_ASSERT_EQUAL(NULL, ll.tail);
  TEST_ASSERT_EQUAL(0, ll.length);
  push_head(&ll, (int *)10);
  TEST_ASSERT_EQUAL(1, ll.length);
  TEST_ASSERT_EQUAL(10, ll.head->value);
  TEST_ASSERT_EQUAL(10, ll.tail->value);
  push_head(&ll, (int *)20);
  TEST_ASSERT_EQUAL(2, ll.length);
  TEST_ASSERT_EQUAL(20, ll.head->value);
  TEST_ASSERT_EQUAL(10, ll.tail->value);
  push_head(&ll, (int *)30);
  TEST_ASSERT_EQUAL(3, ll.length);
  TEST_ASSERT_EQUAL(30, ll.head->value);
  TEST_ASSERT_EQUAL(10, ll.tail->value);

  TEST_ASSERT_EQUAL(30, peak_head(&ll));
  TEST_ASSERT_EQUAL(10, peak_tail(&ll));

  TEST_ASSERT_EQUAL(20, find(&ll, (int *)20));
  TEST_ASSERT_EQUAL(ll.head->value, find(&ll, (int *)30));
  TEST_ASSERT_EQUAL(ll.tail->value, find(&ll, (int *)10));
  TEST_ASSERT_EQUAL(NULL, find(&ll, (int *)40));

  TEST_ASSERT_EQUAL(30, pop_head(&ll));
  TEST_ASSERT_EQUAL(20, pop_head(&ll));
  TEST_ASSERT_EQUAL(10, pop_head(&ll));
  TEST_ASSERT_EQUAL(NULL, pop_head(&ll));

  // tail

  TEST_ASSERT_EQUAL(NULL, peak_head(&ll));
  TEST_ASSERT_EQUAL(NULL, peak_tail(&ll));

  TEST_ASSERT_EQUAL(NULL, ll.head);
  TEST_ASSERT_EQUAL(NULL, ll.tail);
  TEST_ASSERT_EQUAL(0, ll.length);
  push_tail(&ll, (int *)10);
  TEST_ASSERT_EQUAL(1, ll.length);
  TEST_ASSERT_EQUAL(10, ll.head->value);
  TEST_ASSERT_EQUAL(10, ll.tail->value);
  push_tail(&ll, (int *)20);
  TEST_ASSERT_EQUAL(2, ll.length);
  TEST_ASSERT_EQUAL(10, ll.head->value);
  TEST_ASSERT_EQUAL(20, ll.tail->value);
  push_tail(&ll, (int *)30);
  TEST_ASSERT_EQUAL(3, ll.length);
  TEST_ASSERT_EQUAL(10, ll.head->value);
  TEST_ASSERT_EQUAL(30, ll.tail->value);

  TEST_ASSERT_EQUAL(10, peak_head(&ll));
  TEST_ASSERT_EQUAL(30, peak_tail(&ll));

  TEST_ASSERT_EQUAL(20, find(&ll, (int *)20));
  TEST_ASSERT_EQUAL(ll.head->value, find(&ll, (int *)10));
  TEST_ASSERT_EQUAL(ll.tail->value, find(&ll, (int *)30));
  TEST_ASSERT_EQUAL(NULL, find(&ll, (int *)40));

  TEST_ASSERT_EQUAL(30, pop_tail(&ll));
  TEST_ASSERT_EQUAL(20, pop_tail(&ll));
  TEST_ASSERT_EQUAL(10, pop_tail(&ll));
  TEST_ASSERT_EQUAL(NULL, pop_tail(&ll));

  struct linked_list_s *ll = new_linked_list();
  push_head(ll, (int *)10);
  push_head(ll, (int *)20);
  push_head(ll, (int *)30);
  push_head(ll, (int *)40);
  push_head(ll, (int *)50);
  TEST_ASSERT_EQUAL(30, find_and_delete_linked_list(ll, (int *)30));
  TEST_ASSERT_EQUAL(50, find_and_delete_linked_list(ll, (int *)50));
  TEST_ASSERT_EQUAL(10, find_and_delete_linked_list(ll, (int *)10));
  TEST_ASSERT_EQUAL(NULL, find_and_delete_linked_list(ll, (int *)60));

  ll = new_linked_list();
  push_head(ll, (int *)10);
  push_head(ll, (int *)20);
  push_head(ll, (int *)30);
  push_head(ll, (int *)40);
  push_head(ll, (int *)50);
  TEST_ASSERT_EQUAL(30, find_and_update_linked_list(ll, (int *)30, (int *)5));
  TEST_ASSERT_EQUAL(10, find_and_update_linked_list(ll, (int *)10, (int *)2));
  TEST_ASSERT_EQUAL(NULL, find_and_update_linked_list(ll, (int *)3, (int *)2));
  TEST_ASSERT_EQUAL(5, ll->head->next->next->value);
  TEST_ASSERT_EQUAL(2, ll->tail->value);

  tearDownLinkedList();
}
