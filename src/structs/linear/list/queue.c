#include "structs/linear/list/queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void free_queue(struct queue_s *q) {
  if (q->length > 0) {
    struct queue_node_s *curr = q->head;
    for (int i = 0; i < q->length; i++) {
      struct queue_node_s *tmp = curr;
      curr = curr->next;
      free(tmp);
    }
  }
  free(q);
}

void enqueue(struct queue_s *q, int *value) {
  struct queue_node_s *new_node = malloc(sizeof(struct queue_node_s));
  new_node->value = value;
  if (q->length == 0) {
    q->head = new_node;
    q->tail = new_node;
  } else if (q->length == 1) {
    new_node->next = q->tail;
    q->tail->previous = new_node;
    q->head = new_node;
  } else {
    new_node->next = q->head;
    q->head->previous = new_node;
    q->head = new_node;
  }
  q->length++;
};

int *dequeue(struct queue_s *q) {
  if (q->length == 0) {
    return NULL;
  } else if (q->length == 1) {
    struct queue_node_s *tmp = q->tail;
    q->tail = NULL;
    q->head = NULL;
    q->length--;
    int *r = tmp->value;
    free(tmp);
    return r;
  } else if (q->length == 2) {
    struct queue_node_s *tmp = q->tail;
    q->tail = q->head;
    q->length--;
    int *r = tmp->value;
    free(tmp);
    return r;
  } else {
    struct queue_node_s *tmp = q->tail;
    q->tail = q->tail->previous;
    q->length--;
    int *r = tmp->value;
    free(tmp);
    return r;
  }
};
