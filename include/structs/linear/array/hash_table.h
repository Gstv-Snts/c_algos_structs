#ifndef HASH_H
#define HASH_H

#include "structs/linear/list/linked_list.h"

void initialize_hash_table(struct linked_list_s** ht, int size);

int division_method(int k, int m);

int multiplication_method(int k, int m, float A);

int djb2(char* key, int);

int* get_from_hash_table(struct linked_list_s** table, char* key, int* value, int length);

void insert_on_hash_table(struct linked_list_s** table, char* key, int* value, int length);

int* delete_on_hash_table(struct linked_list_s** table, char* key, int* target, int length);

int* update_on_hash_table(struct linked_list_s** table, char* key, int* target, int* new_value, int length);

#endif  // !HASH_H
