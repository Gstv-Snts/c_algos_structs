
#include <stdlib.h>

#include "structs/non_linear/b_tree.h"
#include "unity.h"

void setUpBTree() {};
void tearDownBTree() {};

void test_b_tree(void) {
  setUpBTree();
  struct b_tree_s bt;
  bt.length = 0;
  bt.root = NULL;
  bt.root = malloc(sizeof(struct b_tree_node_s));
  bt.root->left = NULL;
  bt.root->right = NULL;
  bt.root->value = (int*)10;
  bt.length++;
  bt.root->left = malloc(sizeof(struct b_tree_node_s));
  bt.root->left->left = NULL;
  bt.root->left->right = NULL;
  bt.root->left->value = (int*)20;
  bt.length++;
  bt.root->right = malloc(sizeof(struct b_tree_node_s));
  bt.root->right->left = NULL;
  bt.root->right->right = NULL;
  bt.root->right->value = (int*)30;
  bt.length++;
  bt.root->left->left = malloc(sizeof(struct b_tree_node_s));
  bt.root->left->left->left = NULL;
  bt.root->left->left->right = NULL;
  bt.root->left->left->value = (int*)40;
  bt.length++;
  bt.root->left->right = malloc(sizeof(struct b_tree_node_s));
  bt.root->left->right->left = NULL;
  bt.root->left->right->right = NULL;
  bt.root->left->right->value = (int*)50;
  bt.length++;
  free_b_tree(&bt);
  bt.root = NULL;
  TEST_ASSERT_EQUAL(0, bt.length);

  insert(&bt, (int*)10);
  TEST_ASSERT_EQUAL(10, bt.root->value);
  insert(&bt, (int*)20);
  TEST_ASSERT_EQUAL(20, bt.root->left->value);
  insert(&bt, (int*)30);
  TEST_ASSERT_EQUAL(30, bt.root->right->value);
  insert(&bt, (int*)40);
  TEST_ASSERT_EQUAL(40, bt.root->left->left->value);
  insert(&bt, (int*)50);
  TEST_ASSERT_EQUAL(50, bt.root->left->right->value);
  free_b_tree(&bt);
  tearDownBTree();
};
