#include "structs/linear/list/linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct linked_list_s* new_linked_list() {
  struct linked_list_s* ll = malloc(sizeof(struct linked_list_s));
  ll->length = 0;
  ll->head = NULL;
  ll->tail = NULL;
  return ll;
}

int* peak_head(struct linked_list_s* ll) {
  if (ll->head) {
    return ll->head->value;
  };
  return NULL;
};

int* peak_tail(struct linked_list_s* ll) {
  if (ll->tail) {
    return ll->tail->value;
  };
  return NULL;
};

int* find(struct linked_list_s* ll, int* target) {
  struct linked_list_node_s* curr = ll->head;
  for (int i = 0; i < ll->length; i++) {
    if (curr->value == target) {
      return curr->value;
    }
    curr = curr->next;
  }
  return NULL;
};

void push_head(struct linked_list_s* ll, int* value) {
  struct linked_list_node_s* new_node = malloc(sizeof(struct linked_list_node_s));
  new_node->value = value;
  if (ll->length == 0) {
    ll->head = new_node;
    ll->tail = new_node;
  } else if (ll->length == 1) {
    new_node->next = ll->tail;
    ll->tail->previous = new_node;
    ll->head = new_node;
  } else {
    new_node->next = ll->head;
    ll->head->previous = new_node;
    ll->head = new_node;
  };
  ll->length++;
};

void push_tail(struct linked_list_s* ll, int* value) {
  struct linked_list_node_s* new_node = malloc(sizeof(struct linked_list_node_s));
  new_node->value = value;
  if (ll->length == 0) {
    ll->head = new_node;
    ll->tail = new_node;
  } else if (ll->length == 1) {
    new_node->previous = ll->head;
    ll->head->next = new_node;
    ll->tail = new_node;
  } else {
    new_node->previous = ll->tail;
    ll->tail->next = new_node;
    ll->tail = new_node;
  }
  ll->length++;
};

int* pop_head(struct linked_list_s* ll) {
  if (ll->length == 0) {
    return NULL;
  } else if (ll->length == 1) {
    struct linked_list_node_s* tmp = ll->head;
    ll->head = NULL;
    ll->tail = NULL;
    ll->length--;
    return tmp->value;
  } else {
    struct linked_list_node_s* tmp = ll->head;
    ll->head = tmp->next;
    tmp->next = NULL;
    tmp->previous = NULL;
    ll->length--;
    return tmp->value;
  }
}

int* pop_tail(struct linked_list_s* ll) {
  if (ll->length == 0) {
    return NULL;
  } else if (ll->length == 1) {
    struct linked_list_node_s* tmp = ll->tail;
    tmp->next = NULL;
    tmp->previous = NULL;
    ll->head = NULL;
    ll->tail = NULL;
    ll->length--;
    return tmp->value;
  } else {
    struct linked_list_node_s* tmp = ll->tail;
    ll->tail = tmp->previous;
    tmp->next = NULL;
    tmp->previous = NULL;
    ll->length--;
    return tmp->value;
  }
}

int* find_and_delete_linked_list(struct linked_list_s* ll, int* target) {
  if (ll->head->value == target) {
    return pop_head(ll);
  }
  if (ll->tail->value == target) {
    return pop_tail(ll);
  }
  struct linked_list_node_s* curr = ll->head;
  for (int i = 0; i < ll->length; i++) {
    if (curr->next->value == target) {
      int* tmp = curr->next->value;
      curr->next = curr->next->next;
      ll->length--;
      return tmp;
    }
    curr = curr->next;
  }
  return NULL;
};

int* find_and_update_linked_list(struct linked_list_s* ll, int* target, int* new_value) {
  if (ll->head->value == target) {
    int* tmp = ll->head->value;
    ll->head->value = new_value;
    return tmp;
  }
  if (ll->tail->value == target) {
    int* tmp = ll->tail->value;
    ll->tail->value = new_value;
    return tmp;
  }
  struct linked_list_node_s* curr = ll->head;
  for (int i = 0; i < ll->length; i++) {
    if (curr->value == target) {
      int* tmp = curr->value;
      curr->value = new_value;
      return tmp;
    }
    curr = curr->next;
  }
  return NULL;
};
