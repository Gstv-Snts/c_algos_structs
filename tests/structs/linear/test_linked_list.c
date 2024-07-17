#include <stdio.h>
#include <stdlib.h>

#include "structs/linear/linked_list.h"
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
  push_head(&ll, 10);
  TEST_ASSERT_EQUAL(1, ll.length);
  TEST_ASSERT_EQUAL(10, ll.head->value);
  TEST_ASSERT_EQUAL(10, ll.tail->value);
  push_head(&ll, 20);
  TEST_ASSERT_EQUAL(2, ll.length);
  TEST_ASSERT_EQUAL(20, ll.head->value);
  TEST_ASSERT_EQUAL(10, ll.tail->value);
  push_head(&ll, 30);
  TEST_ASSERT_EQUAL(3, ll.length);
  TEST_ASSERT_EQUAL(30, ll.head->value);
  TEST_ASSERT_EQUAL(10, ll.tail->value);

  TEST_ASSERT_EQUAL(30, peak_head(&ll)->value);
  TEST_ASSERT_EQUAL(10, peak_tail(&ll)->value);

  TEST_ASSERT_EQUAL(20, find(&ll, 20)->value);
  TEST_ASSERT_EQUAL(ll.head, find(&ll, 30));
  TEST_ASSERT_EQUAL(ll.tail, find(&ll, 10));
  TEST_ASSERT_EQUAL(NULL, find(&ll, 40));

  TEST_ASSERT_EQUAL(30, pop_head(&ll)->value);
  TEST_ASSERT_EQUAL(20, pop_head(&ll)->value);
  TEST_ASSERT_EQUAL(10, pop_head(&ll)->value);
  TEST_ASSERT_EQUAL(NULL, pop_head(&ll));

  // tail

  TEST_ASSERT_EQUAL(NULL, peak_head(&ll));
  TEST_ASSERT_EQUAL(NULL, peak_tail(&ll));

  TEST_ASSERT_EQUAL(NULL, ll.head);
  TEST_ASSERT_EQUAL(NULL, ll.tail);
  TEST_ASSERT_EQUAL(0, ll.length);
  push_tail(&ll, 10);
  TEST_ASSERT_EQUAL(1, ll.length);
  TEST_ASSERT_EQUAL(10, ll.head->value);
  TEST_ASSERT_EQUAL(10, ll.tail->value);
  push_tail(&ll, 20);
  TEST_ASSERT_EQUAL(2, ll.length);
  TEST_ASSERT_EQUAL(10, ll.head->value);
  TEST_ASSERT_EQUAL(20, ll.tail->value);
  push_tail(&ll, 30);
  TEST_ASSERT_EQUAL(3, ll.length);
  TEST_ASSERT_EQUAL(10, ll.head->value);
  TEST_ASSERT_EQUAL(30, ll.tail->value);

  TEST_ASSERT_EQUAL(10, peak_head(&ll)->value);
  TEST_ASSERT_EQUAL(30, peak_tail(&ll)->value);

  TEST_ASSERT_EQUAL(20, find(&ll, 20)->value);
  TEST_ASSERT_EQUAL(ll.head, find(&ll, 10));
  TEST_ASSERT_EQUAL(ll.tail, find(&ll, 30));
  TEST_ASSERT_EQUAL(NULL, find(&ll, 40));

  TEST_ASSERT_EQUAL(30, pop_tail(&ll)->value);
  TEST_ASSERT_EQUAL(20, pop_tail(&ll)->value);
  TEST_ASSERT_EQUAL(10, pop_tail(&ll)->value);
  TEST_ASSERT_EQUAL(NULL, pop_tail(&ll));

  tearDownLinkedList();
}
