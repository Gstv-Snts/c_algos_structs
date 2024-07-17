#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

struct node_s {
  int value;
  struct node_s* next;
  struct node* previous;
};

struct linked_list_s {
  struct node* head;
  struct node* tail;
  int length;
};

int main() {
  struct node_s* head = (struct node_t*)malloc(sizeof(struct node_s));
  struct node_s* tail = (struct node_t*)malloc(sizeof(struct node_s));
  head->value = 10;
  head->next = tail;
  if (head->next) {
    printf("%d\n", head->value);
  } else {
    printf("empty");
  }
  return 0;
}
