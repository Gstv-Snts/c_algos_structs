#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs/linear/list/queue.h"
#include "unity.h"

void setUpQueue() {};
void tearDownUpQueue() {};

void test_queue(void) {
  setUpQueue();
  struct queue_s* q = malloc(sizeof(struct queue_s));
  q->length = 0;
  q->head = NULL;
  q->tail = NULL;
  TEST_ASSERT_EQUAL(NULL, dequeue(q));
  enqueue(q, (int*)10);
  enqueue(q, (int*)20);
  enqueue(q, (int*)30);
  enqueue(q, (int*)40);
  enqueue(q, (int*)50);
  TEST_ASSERT_EQUAL(10, dequeue(q));
  TEST_ASSERT_EQUAL(20, dequeue(q));
  TEST_ASSERT_EQUAL(30, dequeue(q));
  TEST_ASSERT_EQUAL(40, dequeue(q));
  TEST_ASSERT_EQUAL(50, dequeue(q));
  free_queue(q);

  tearDownUpQueue();
}
