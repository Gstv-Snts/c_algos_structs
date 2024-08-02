#ifndef B_TREE_H
#define B_TREE_H
struct b_tree_node_s {
  int *value;
  struct b_tree_node_s *left;
  struct b_tree_node_s *right;
};

struct b_tree_s {
  struct b_tree_node_s *root;
  int length;
};

void free_b_tree(struct b_tree_s *bt);

void insert(struct b_tree_s *bt, int *value);

int *delete(struct b_tree_s *bt, int *target);

void print_b_tree(struct b_tree_s *bt);

#endif  // !B_TREE_H
