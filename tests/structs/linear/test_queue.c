#include "structs/linear/queue.h"
#include "unity.h"

struct queue_s q;
void setUpQueue() {};
void tearDownUpQueue() {};

void test_queue(void) {
  setUpQueue();
  enqueue(&q, 10);
  TEST_ASSERT_EQUAL(1, q.length);
  TEST_ASSERT_EQUAL(10, q.head->value);
  TEST_ASSERT_EQUAL(10, q.tail->value);
  enqueue(&q, 20);
  TEST_ASSERT_EQUAL(2, q.length);
  TEST_ASSERT_EQUAL(20, q.head->value);
  TEST_ASSERT_EQUAL(10, q.head->next->value);
  TEST_ASSERT_EQUAL(10, q.tail->value);
  enqueue(&q, 30);
  TEST_ASSERT_EQUAL(3, q.length);
  TEST_ASSERT_EQUAL(30, q.head->value);
  TEST_ASSERT_EQUAL(20, q.head->next->value);
  TEST_ASSERT_EQUAL(10, q.head->next->next->value);
  TEST_ASSERT_EQUAL(10, q.tail->value);

  struct queue_node_s* dq = dequeue(&q);
  TEST_ASSERT_EQUAL(2, q.length);
  TEST_ASSERT_EQUAL(10, dq->value);
  TEST_ASSERT_EQUAL(30, q.head->value);
  TEST_ASSERT_EQUAL(20, q.head->next->value);

  dq = dequeue(&q);
  TEST_ASSERT_EQUAL(1, q.length);
  TEST_ASSERT_EQUAL(20, dq->value);
  TEST_ASSERT_EQUAL(30, q.head->value);
  TEST_ASSERT_EQUAL(30, q.tail->value);

  dq = dequeue(&q);
  TEST_ASSERT_EQUAL(0, q.length);
  TEST_ASSERT_EQUAL(30, dq->value);
  TEST_ASSERT_EQUAL(NULL, q.head);
  TEST_ASSERT_EQUAL(NULL, q.tail);

  dq = dequeue(&q);
  TEST_ASSERT_EQUAL(NULL, dq);

  tearDownUpQueue();
}
