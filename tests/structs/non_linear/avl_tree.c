#include "structs/non_linear/avl_tree.h"

#include <stdio.h>

#include "unity.h"

void setUpAVLTree(void) {};
void tearDownAVLTree(void) {};

void test_avl_tree(void) {
  setUpAVLTree();
  struct avl_tree_s at = new_avl_tree();
  print_avl_tree(&at);
  TEST_ASSERT_EQUAL(0, at.length);
  TEST_ASSERT_EQUAL(NULL, at.root);

  struct avl_tree_node_s* new_node = new_avl_tree_node((int*)10);
  TEST_ASSERT_EQUAL(10, new_node->value);
  TEST_ASSERT_EQUAL(NULL, new_node->left);
  TEST_ASSERT_EQUAL(NULL, new_node->right);

  TEST_ASSERT_EQUAL(0, height(at.root));
  at.root = new_avl_tree_node((int*)10);
  TEST_ASSERT_EQUAL(0, balance_factor(at.root));
  TEST_ASSERT_EQUAL(1, height(at.root));

  at.root->right = new_avl_tree_node((int*)20);
  TEST_ASSERT_EQUAL(1, balance_factor(at.root));
  TEST_ASSERT_EQUAL(2, height(at.root));

  at.root->right->right = new_avl_tree_node((int*)30);
  TEST_ASSERT_EQUAL(2, balance_factor(at.root));
  TEST_ASSERT_EQUAL(3, height(at.root));

  at = new_avl_tree();

  TEST_ASSERT_EQUAL(0, height(at.root));
  at.root = new_avl_tree_node((int*)10);
  TEST_ASSERT_EQUAL(0, balance_factor(at.root));
  TEST_ASSERT_EQUAL(1, height(at.root));

  at.root->left = new_avl_tree_node((int*)20);
  TEST_ASSERT_EQUAL(-1, balance_factor(at.root));
  TEST_ASSERT_EQUAL(2, height(at.root));

  at.root->left->left = new_avl_tree_node((int*)30);
  TEST_ASSERT_EQUAL(-2, balance_factor(at.root));
  TEST_ASSERT_EQUAL(3, height(at.root));

  // LL
  at = new_avl_tree();
  at.root = new_avl_tree_node((int*)10);
  at.root->left = new_avl_tree_node((int*)20);
  at.root->left->left = new_avl_tree_node((int*)30);
  TEST_ASSERT_EQUAL(10, at.root->value);
  TEST_ASSERT_EQUAL(20, at.root->left->value);
  TEST_ASSERT_EQUAL(30, at.root->left->left->value);
  int bf = balance_factor(at.root);
  balance_node(at.root, bf);
  TEST_ASSERT_EQUAL(20, at.root->value);
  TEST_ASSERT_EQUAL(10, at.root->right->value);
  TEST_ASSERT_EQUAL(30, at.root->left->value);

  // LR
  at = new_avl_tree();
  at.root = new_avl_tree_node((int*)20);
  at.root->left = new_avl_tree_node((int*)10);
  at.root->left->right = new_avl_tree_node((int*)15);
  TEST_ASSERT_EQUAL(20, at.root->value);
  TEST_ASSERT_EQUAL(10, at.root->left->value);
  TEST_ASSERT_EQUAL(15, at.root->left->right->value);
  bf = balance_factor(at.root);
  balance_node(at.root, bf);
  TEST_ASSERT_EQUAL(15, at.root->value);
  TEST_ASSERT_EQUAL(20, at.root->right->value);
  TEST_ASSERT_EQUAL(10, at.root->left->value);

  // RR
  at = new_avl_tree();
  at.root = new_avl_tree_node((int*)10);
  at.root->right = new_avl_tree_node((int*)20);
  at.root->right->right = new_avl_tree_node((int*)30);
  TEST_ASSERT_EQUAL(10, at.root->value);
  TEST_ASSERT_EQUAL(20, at.root->right->value);
  TEST_ASSERT_EQUAL(30, at.root->right->right->value);
  bf = balance_factor(at.root);
  balance_node(at.root, bf);
  TEST_ASSERT_EQUAL(20, at.root->value);
  TEST_ASSERT_EQUAL(10, at.root->left->value);
  TEST_ASSERT_EQUAL(30, at.root->right->value);

  // RL
  at = new_avl_tree();
  at.root = new_avl_tree_node((int*)20);
  at.root->right = new_avl_tree_node((int*)10);
  at.root->right->left = new_avl_tree_node((int*)15);
  TEST_ASSERT_EQUAL(20, at.root->value);
  TEST_ASSERT_EQUAL(10, at.root->right->value);
  TEST_ASSERT_EQUAL(15, at.root->right->left->value);
  bf = balance_factor(at.root);
  balance_node(at.root, bf);
  TEST_ASSERT_EQUAL(15, at.root->value);
  TEST_ASSERT_EQUAL(20, at.root->left->value);
  TEST_ASSERT_EQUAL(10, at.root->right->value);

  // LL
  at = new_avl_tree();
  avl_insert(&at, (int*)30);
  avl_insert(&at, (int*)20);
  avl_insert(&at, (int*)10);
  TEST_ASSERT_EQUAL(3, at.length);
  TEST_ASSERT_EQUAL(20, at.root->value);
  TEST_ASSERT_EQUAL(10, at.root->left->value);
  TEST_ASSERT_EQUAL(30, at.root->right->value);

  // LR
  at = new_avl_tree();
  avl_insert(&at, (int*)30);
  avl_insert(&at, (int*)20);
  avl_insert(&at, (int*)25);
  TEST_ASSERT_EQUAL(3, at.length);
  TEST_ASSERT_EQUAL(25, at.root->value);
  TEST_ASSERT_EQUAL(20, at.root->left->value);
  TEST_ASSERT_EQUAL(30, at.root->right->value);

  // RR
  at = new_avl_tree();
  avl_insert(&at, (int*)10);
  avl_insert(&at, (int*)20);
  avl_insert(&at, (int*)30);
  TEST_ASSERT_EQUAL(3, at.length);
  TEST_ASSERT_EQUAL(20, at.root->value);
  TEST_ASSERT_EQUAL(10, at.root->left->value);
  TEST_ASSERT_EQUAL(30, at.root->right->value);

  // RL
  at = new_avl_tree();
  avl_insert(&at, (int*)10);
  avl_insert(&at, (int*)20);
  avl_insert(&at, (int*)15);
  TEST_ASSERT_EQUAL(3, at.length);
  TEST_ASSERT_EQUAL(15, at.root->value);
  TEST_ASSERT_EQUAL(10, at.root->left->value);
  TEST_ASSERT_EQUAL(20, at.root->right->value);

  // LLL
  at = new_avl_tree();
  avl_insert(&at, (int*)30);
  avl_insert(&at, (int*)20);
  avl_insert(&at, (int*)40);
  avl_insert(&at, (int*)25);
  avl_insert(&at, (int*)10);
  TEST_ASSERT_EQUAL(5, at.length);
  TEST_ASSERT_EQUAL(30, at.root->value);
  TEST_ASSERT_EQUAL(20, at.root->left->value);
  TEST_ASSERT_EQUAL(40, at.root->right->value);
  TEST_ASSERT_EQUAL(10, at.root->left->left->value);
  TEST_ASSERT_EQUAL(25, at.root->left->right->value);
  avl_insert(&at, (int*)5);
  TEST_ASSERT_EQUAL(6, at.length);
  TEST_ASSERT_EQUAL(20, at.root->value);
  TEST_ASSERT_EQUAL(10, at.root->left->value);
  TEST_ASSERT_EQUAL(30, at.root->right->value);
  TEST_ASSERT_EQUAL(5, at.root->left->left->value);
  TEST_ASSERT_EQUAL(25, at.root->right->left->value);

  // RRR
  at = new_avl_tree();
  avl_insert(&at, (int*)30);
  avl_insert(&at, (int*)40);
  avl_insert(&at, (int*)20);
  avl_insert(&at, (int*)35);
  avl_insert(&at, (int*)50);
  TEST_ASSERT_EQUAL(5, at.length);
  TEST_ASSERT_EQUAL(30, at.root->value);
  TEST_ASSERT_EQUAL(20, at.root->left->value);
  TEST_ASSERT_EQUAL(40, at.root->right->value);
  TEST_ASSERT_EQUAL(35, at.root->right->left->value);
  TEST_ASSERT_EQUAL(50, at.root->right->right->value);
  avl_insert(&at, (int*)60);
  TEST_ASSERT_EQUAL(6, at.length);
  TEST_ASSERT_EQUAL(40, at.root->value);
  TEST_ASSERT_EQUAL(30, at.root->left->value);
  TEST_ASSERT_EQUAL(20, at.root->left->left->value);
  TEST_ASSERT_EQUAL(35, at.root->left->right->value);
  TEST_ASSERT_EQUAL(50, at.root->right->value);
  TEST_ASSERT_EQUAL(60, at.root->right->right->value);

  print_avl_tree(&at);

  tearDownAVLTree();
}
