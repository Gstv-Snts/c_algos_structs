#include <stdio.h>

#include "structs/linear/array/hash_table.h"
#include "structs/linear/list/linked_list.h"
#include "unity.h"

void setUpHashTable(void) {};
void tearDownHashTable(void) {};

void test_hash_table(void) {
  setUpHashTable();
  const float A = 0.618033;
  struct linked_list_s *hash_table[10];
  int hash_table_length = (sizeof(hash_table) / sizeof(hash_table[0]));
  initialize_hash_table(hash_table, 10);

  TEST_ASSERT_EQUAL(10, hash_table_length);
  for (int i = 0; i < hash_table_length; i++) {
    TEST_ASSERT_EQUAL(0, hash_table[i]->length);
  }
  TEST_ASSERT_EQUAL(0, hash_table[0]->length);

  TEST_ASSERT_EQUAL(4, division_method(100, 12));
  TEST_ASSERT_EQUAL(0, division_method(10, 10));

  TEST_ASSERT_EQUAL(1, multiplication_method(123, 100, A));
  TEST_ASSERT_EQUAL(42, multiplication_method(12, 101, A));

  TEST_ASSERT_EQUAL(0, djb2("banana", 10));
  TEST_ASSERT_EQUAL(7, djb2("apple", 10));
  TEST_ASSERT_EQUAL(2, djb2("avocado", 10));
  TEST_ASSERT_EQUAL(7, djb2("pineapple", 10));

  insert_on_hash_table(hash_table, "banana", (int *)10, hash_table_length);
  insert_on_hash_table(hash_table, "banana", (int *)20, hash_table_length);
  insert_on_hash_table(hash_table, "apple", (int *)30, hash_table_length);
  insert_on_hash_table(hash_table, "apple", (int *)40, hash_table_length);
  insert_on_hash_table(hash_table, "avocado", (int *)50, hash_table_length);
  insert_on_hash_table(hash_table, "avocado", (int *)60, hash_table_length);
  insert_on_hash_table(hash_table, "pineapple", (int *)70, hash_table_length);
  insert_on_hash_table(hash_table, "pineapple", (int *)80, hash_table_length);

  TEST_ASSERT_EQUAL(2, hash_table[0]->length);
  TEST_ASSERT_EQUAL(4, hash_table[7]->length);
  TEST_ASSERT_EQUAL(2, hash_table[2]->length);

  TEST_ASSERT_EQUAL(NULL, get_from_hash_table(hash_table, "banana", (int *)30, hash_table_length));
  TEST_ASSERT_EQUAL(10, get_from_hash_table(hash_table, "banana", (int *)10, hash_table_length));
  TEST_ASSERT_EQUAL(20, get_from_hash_table(hash_table, "banana", (int *)20, hash_table_length));

  TEST_ASSERT_EQUAL(NULL, get_from_hash_table(hash_table, "apple", (int *)50, hash_table_length));
  TEST_ASSERT_EQUAL(30, get_from_hash_table(hash_table, "apple", (int *)30, hash_table_length));
  TEST_ASSERT_EQUAL(40, get_from_hash_table(hash_table, "apple", (int *)40, hash_table_length));

  TEST_ASSERT_EQUAL(NULL, get_from_hash_table(hash_table, "avocado", (int *)70, hash_table_length));
  TEST_ASSERT_EQUAL(50, get_from_hash_table(hash_table, "avocado", (int *)50, hash_table_length));
  TEST_ASSERT_EQUAL(60, get_from_hash_table(hash_table, "avocado", (int *)60, hash_table_length));

  TEST_ASSERT_EQUAL(NULL, get_from_hash_table(hash_table, "pineapple", (int *)90, hash_table_length));
  TEST_ASSERT_EQUAL(70, get_from_hash_table(hash_table, "pineapple", (int *)70, hash_table_length));
  TEST_ASSERT_EQUAL(80, get_from_hash_table(hash_table, "pineapple", (int *)80, hash_table_length));

  TEST_ASSERT_EQUAL(20, update_on_hash_table(hash_table, "banana", (int *)20, (int *)80, hash_table_length));
  TEST_ASSERT_EQUAL(80, hash_table[0]->head->value);

  TEST_ASSERT_EQUAL(70, update_on_hash_table(hash_table, "pineapple", (int *)70, (int *)10, hash_table_length));
  TEST_ASSERT_EQUAL(10, hash_table[7]->head->next->value);

  TEST_ASSERT_EQUAL(10, delete_on_hash_table(hash_table, "pineapple", (int *)10, hash_table_length));
  TEST_ASSERT_EQUAL(3, hash_table[7]->length);

  TEST_ASSERT_EQUAL(80, delete_on_hash_table(hash_table, "banana", (int *)80, hash_table_length));
  TEST_ASSERT_EQUAL(1, hash_table[0]->length);
  tearDownHashTable();
}
