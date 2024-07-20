#ifndef BINARY_TREE_H
#define BINARY_TREE_H
struct binary_tree_node_s {
  int *value;
  struct binary_tree_node_s *left;
  struct binary_tree_node_s *right;
};

struct binary_tree_s {
  struct binary_tree_node_s *root;
  int length;
};

struct binary_tree_s new_binary_tree();

void insert(struct binary_tree_s *bt, int *value);

int *delete(struct binary_tree_s *bt, int *target);

void print_binary_tree(struct binary_tree_s *bt);

#endif  // !BINARY_TREE_H
