#include "structs/non_linear/binary_tree.h"
#include "unity.h"

struct binary_tree_s bt;
void setUpBinaryTree() {};
void tearDownBinaryTree() {};

void test_binary_tree(void) {
  setUpBinaryTree();
  TEST_ASSERT_EQUAL(0, bt.length);
  insert(&bt, (int*)10);
  TEST_ASSERT_EQUAL(1, bt.length);
  TEST_ASSERT_EQUAL(10, bt.root->value);
  insert(&bt, (int*)20);
  TEST_ASSERT_EQUAL(2, bt.length);
  TEST_ASSERT_EQUAL(20, bt.root->left->value);
  insert(&bt, (int*)30);
  TEST_ASSERT_EQUAL(3, bt.length);
  TEST_ASSERT_EQUAL(30, bt.root->right->value);
  insert(&bt, (int*)40);
  TEST_ASSERT_EQUAL(4, bt.length);
  TEST_ASSERT_EQUAL(40, bt.root->left->left->value);
  insert(&bt, (int*)50);
  TEST_ASSERT_EQUAL(5, bt.length);
  TEST_ASSERT_EQUAL(50, bt.root->left->right->value);
  insert(&bt, (int*)60);
  TEST_ASSERT_EQUAL(6, bt.length);
  TEST_ASSERT_EQUAL(60, bt.root->right->left->value);
  insert(&bt, (int*)70);
  TEST_ASSERT_EQUAL(7, bt.length);
  TEST_ASSERT_EQUAL(70, bt.root->right->right->value);
  insert(&bt, (int*)80);
  TEST_ASSERT_EQUAL(8, bt.length);
  TEST_ASSERT_EQUAL(80, bt.root->left->left->left->value);

  int* del = delete (&bt, (int*)10);
  TEST_ASSERT_EQUAL(7, bt.length);
  TEST_ASSERT_EQUAL(10, del);
  TEST_ASSERT_EQUAL(70, bt.root->value);
  del = delete (&bt, (int*)80);
  TEST_ASSERT_EQUAL(6, bt.length);
  TEST_ASSERT_EQUAL(80, del);
  TEST_ASSERT_EQUAL(NULL, bt.root->left->left->left);
  del = delete (&bt, (int*)50);
  TEST_ASSERT_EQUAL(5, bt.length);
  TEST_ASSERT_EQUAL(50, del);
  TEST_ASSERT_EQUAL(NULL, bt.root->left->right);
  del = delete (&bt, (int*)20);
  TEST_ASSERT_EQUAL(4, bt.length);
  TEST_ASSERT_EQUAL(20, del);
  TEST_ASSERT_EQUAL(40, bt.root->left->value);
  del = delete (&bt, (int*)60);
  TEST_ASSERT_EQUAL(3, bt.length);
  TEST_ASSERT_EQUAL(60, del);
  TEST_ASSERT_EQUAL(NULL, bt.root->right->left);
  del = delete (&bt, (int*)30);
  TEST_ASSERT_EQUAL(2, bt.length);
  TEST_ASSERT_EQUAL(30, del);
  TEST_ASSERT_EQUAL(NULL, bt.root->right);
  TEST_ASSERT_EQUAL(40, bt.root->left->value);
  del = delete (&bt, (int*)40);
  TEST_ASSERT_EQUAL(1, bt.length);
  TEST_ASSERT_EQUAL(40, del);
  TEST_ASSERT_EQUAL(NULL, bt.root->left);
  TEST_ASSERT_EQUAL(NULL, bt.root->right);
  del = delete (&bt, (int*)70);
  TEST_ASSERT_EQUAL(0, bt.length);
  TEST_ASSERT_EQUAL(70, del);
  TEST_ASSERT_EQUAL(NULL, bt.root);

  tearDownBinaryTree();
};
