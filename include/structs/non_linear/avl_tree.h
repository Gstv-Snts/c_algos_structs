#ifndef AVL_TREE_H
#define AVL_TREE_H
struct avl_tree_node_s {
  int* value;
  struct avl_tree_node_s* left;
  struct avl_tree_node_s* right;
};

struct avl_tree_s {
  struct avl_tree_node_s* root;
  int length;
};

struct avl_tree_s new_avl_tree();

struct avl_tree_node_s* new_avl_tree_node(int* node);

int height(struct avl_tree_node_s* avl_node);

int balance_factor(struct avl_tree_node_s* avl_node);

void balance_node(struct avl_tree_node_s* node, int balance_factor);

void avl_insert_recurse(struct avl_tree_node_s* avl_node, int* value);

void print_avl_tree(struct avl_tree_s* at);

void avl_insert(struct avl_tree_s* at, int* value);

#endif  // !AVL_TREE_H
