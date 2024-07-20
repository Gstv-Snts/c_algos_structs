#include <stdlib.h>

#include "structs/linear/queue.h"
#include "unity.h"

void setUpQueue() {};
void tearDownUpQueue() {};

void test_queue(void) {
  struct queue_s q = new_queue();
  setUpQueue();
  TEST_ASSERT_EQUAL(0, q.length);
  enqueue(&q, (int*)10);
  TEST_ASSERT_EQUAL(1, q.length);
  TEST_ASSERT_EQUAL(10, q.head->value);
  TEST_ASSERT_EQUAL(10, q.tail->value);
  enqueue(&q, (int*)20);
  TEST_ASSERT_EQUAL(2, q.length);
  TEST_ASSERT_EQUAL(20, q.head->value);
  TEST_ASSERT_EQUAL(10, q.head->next->value);
  TEST_ASSERT_EQUAL(10, q.tail->value);
  enqueue(&q, (int*)30);
  TEST_ASSERT_EQUAL(3, q.length);
  TEST_ASSERT_EQUAL(30, q.head->value);
  TEST_ASSERT_EQUAL(20, q.head->next->value);
  TEST_ASSERT_EQUAL(10, q.head->next->next->value);
  TEST_ASSERT_EQUAL(10, q.tail->value);

  int* dq = dequeue(&q);
  TEST_ASSERT_EQUAL(2, q.length);
  TEST_ASSERT_EQUAL(10, dq);
  TEST_ASSERT_EQUAL(30, q.head->value);
  TEST_ASSERT_EQUAL(20, q.head->next->value);

  dq = dequeue(&q);
  TEST_ASSERT_EQUAL(1, q.length);
  TEST_ASSERT_EQUAL(20, dq);
  TEST_ASSERT_EQUAL(30, q.head->value);
  TEST_ASSERT_EQUAL(30, q.tail->value);

  dq = dequeue(&q);
  TEST_ASSERT_EQUAL(0, q.length);
  TEST_ASSERT_EQUAL(30, dq);
  TEST_ASSERT_EQUAL(NULL, q.head);
  TEST_ASSERT_EQUAL(NULL, q.tail);

  dq = dequeue(&q);
  TEST_ASSERT_EQUAL(NULL, dq);

  q = new_queue();
  TEST_ASSERT_EQUAL(0, q.length);
  enqueue(&q, (int*)10);
  TEST_ASSERT_EQUAL(1, q.length);
  TEST_ASSERT_EQUAL(10, q.head->value);
  TEST_ASSERT_EQUAL(10, q.tail->value);
  enqueue(&q, (int*)20);
  TEST_ASSERT_EQUAL(2, q.length);
  TEST_ASSERT_EQUAL(20, q.head->value);
  TEST_ASSERT_EQUAL(10, q.head->next->value);
  TEST_ASSERT_EQUAL(10, q.tail->value);
  enqueue(&q, (int*)30);
  TEST_ASSERT_EQUAL(3, q.length);
  TEST_ASSERT_EQUAL(30, q.head->value);
  TEST_ASSERT_EQUAL(20, q.head->next->value);
  TEST_ASSERT_EQUAL(10, q.head->next->next->value);
  TEST_ASSERT_EQUAL(10, q.tail->value);

  tearDownUpQueue();
}
