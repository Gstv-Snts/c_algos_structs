#include "structs/linear/queue.h"

#include <stdlib.h>
#include <time.h>

void enqueue(struct queue_s *q, int value) {
  struct queue_node_s *newNode = malloc(sizeof(struct queue_node_s));
  newNode->value = value;
  if (q->length == 0) {
    q->head = newNode;
    q->tail = newNode;
  } else if (q->length == 1) {
    newNode->next = q->head;
    q->tail->previous = newNode;
    q->head = newNode;
  } else {
    newNode->next = q->head;
    q->head = newNode;
  }
  q->length++;
};

struct queue_node_s *dequeue(struct queue_s *q) {
  if (q->length == 0) {
    return NULL;
  } else if (q->length == 1) {
    struct queue_node_s *tmp = q->tail;
    q->tail = NULL;
    q->head = NULL;
    q->length--;
    return tmp;
  } else if (q->length == 2) {
    struct queue_node_s *tmp = q->tail;
    q->tail = q->head;
    q->length--;
    return tmp;
  } else {
    struct queue_node_s *tmp = q->tail;
    q->tail = tmp->previous;
    q->tail->next = NULL;
    q->length--;
    return tmp;
  }
};
