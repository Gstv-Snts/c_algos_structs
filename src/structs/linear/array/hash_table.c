#include "structs/linear/array/hash_table.h"

#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "structs/linear/list/linked_list.h"

void initialize_hash_table(struct linked_list_s** ht, int size) {
  for (int i = 0; i < size; i++) {
    struct linked_list_s* ll = malloc(sizeof(struct linked_list_s));
    ll->length = 0;
    ll->head = NULL;
    ll->tail = NULL;
    *(ht + i) = ll;
  }
};

int division_method(int value, int length) { return value % length; };

int multiplication_method(int value, int length, float CONS) { return length * fmod((double)(value * CONS), (double)1); };

int djb2(char* key, int length) {
  unsigned long hash = 5381;
  int c;
  while ((c = *key++)) {
    hash = ((hash << 5) + hash) + c;
  }
  return hash % length;
}

int* get_from_hash_table(struct linked_list_s** table, char* key, int* target, int length) { return find(*(table + djb2(key, length)), target); }

void insert_on_hash_table(struct linked_list_s** table, char* key, int* value, int length) {
  int i = djb2(key, length);
  push_head(*(table + i), value);
}

int* delete_on_hash_table(struct linked_list_s** table, char* key, int* target, int length) { return find_and_delete_linked_list(*(table + djb2(key, length)), target); }

int* update_on_hash_table(struct linked_list_s** table, char* key, int* target, int* new_value, int length) { return find_and_update_linked_list(*(table + djb2(key, length)), target, new_value); }
