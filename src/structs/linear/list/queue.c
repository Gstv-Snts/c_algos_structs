#include "structs/linear/list/queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct queue_s new_queue() {
  struct queue_s q;
  q.length = 0;
  q.head = NULL;
  q.tail = NULL;
  return q;
}

void enqueue(struct queue_s *q, int *value) {
  struct queue_node_s *newNode = malloc(sizeof(struct queue_node_s));
  newNode->value = value;
  if (q->length == 0) {
    q->head = newNode;
    q->tail = newNode;
  } else if (q->length == 1) {
    newNode->next = q->tail;
    q->tail->previous = newNode;
    q->head = newNode;
  } else {
    newNode->next = q->head;
    q->head->previous = newNode;
    q->head = newNode;
  }
  q->length++;
};

int *dequeue(struct queue_s *q) {
  if (q->length == 0) {
    return NULL;
  } else if (q->length == 1) {
    int *tmp = q->tail->value;
    q->tail = NULL;
    q->head = NULL;
    q->length--;
    return tmp;
  } else if (q->length == 2) {
    int *tmp = q->tail->value;
    q->tail = q->head;
    q->length--;
    return tmp;
  } else {
    int *tmp = q->tail->value;
    q->tail = q->tail->previous;
    q->length--;
    return tmp;
  }
};

void print_queue(struct queue_s *q) {
  struct queue_node_s *curr = q->head;
  printf("Queue Head->Tail: [");
  while (curr) {
    printf("%d", curr->value);
    curr = curr->next;
  }
  printf("]\n");
}

void print_queue_backwards(struct queue_s *q) {
  struct queue_node_s *curr = q->tail;
  printf("Queue Tail->Head: [");
  while (curr) {
    printf("%d", curr->value);
    curr = curr->previous;
  }
  printf("]\n");
}
