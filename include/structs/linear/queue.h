#ifndef QUEUE_H
#define QUEUE_H
struct queue_node_s {
  int* value;
  struct queue_node_s* next;
  struct queue_node_s* previous;
};

struct queue_s {
  struct queue_node_s* head;
  struct queue_node_s* tail;
  int length;
};

struct queue_s new_queue();

void enqueue(struct queue_s* q, int* value);

int* dequeue(struct queue_s* q);

void print_queue(struct queue_s* q);

void print_queue_backwards(struct queue_s* q);

#endif  // !QUEUE_H
