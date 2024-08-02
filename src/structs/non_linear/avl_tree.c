#include "structs/non_linear/avl_tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "structs/linear/list/queue.h"

struct avl_tree_s new_avl_tree() {
  struct avl_tree_s avl;
  avl.length = 0;
  avl.root = NULL;
  return avl;
}

struct avl_tree_node_s *new_avl_tree_node(int *value) {
  struct avl_tree_node_s *avl_node = malloc(sizeof(struct avl_tree_node_s));
  avl_node->value = value;
  avl_node->left = NULL;
  avl_node->right = NULL;
  return avl_node;
}

void balance_node(struct avl_tree_node_s *node, int balance_factor) {
  if (balance_factor <= -2) {
    if (node->left->left && node->left->right) {
      struct avl_tree_node_s *new_node = new_avl_tree_node(node->value);
      new_node->right = node->right;
      new_node->left = node->left->right;
      node->value = node->left->value;
      node->right = new_node;
      node->left = node->left->left;
    } else if (node->left->left) {
      node->right = new_avl_tree_node(node->value);
      node->value = node->left->value;
      node->left = node->left->left;
    } else if (node->left->right) {
      node->right = new_avl_tree_node(node->value);
      node->value = node->left->right->value;
      node->left->right = NULL;
    }
  } else {
    if (node->right->right && node->right->left) {
      struct avl_tree_node_s *new_node = new_avl_tree_node(node->value);
      new_node->left = node->left;
      new_node->right = node->right->left;
      node->value = node->right->value;
      node->left = new_node;
      node->right = node->right->right;
    } else if (node->right->right) {
      node->left = new_avl_tree_node(node->value);
      node->value = node->right->value;
      node->right = node->right->right;
    } else if (node->right->left) {
      node->left = new_avl_tree_node(node->value);
      node->value = node->right->left->value;
      node->right->left = NULL;
    }
  }
}

int height(struct avl_tree_node_s *avl_node) {
  int height = 0;
  if (avl_node) {
    struct queue_s *q = malloc(sizeof(struct queue_s));
    q->length = 0;
    q->head = NULL;
    q->tail = NULL;
    enqueue(q, (int *)avl_node);
    while (q->length > 0) {
      int size = q->length;
      height++;
      while (size > 0) {
        struct avl_tree_node_s *dq = (struct avl_tree_node_s *)dequeue(q);
        if (dq->left) {
          enqueue(q, (int *)dq->left);
        }
        if (dq->right) {
          enqueue(q, (int *)dq->right);
        }
        size--;
      }
    }
  }
  return height;
};

int balance_factor(struct avl_tree_node_s *avl_node) {
  int left = height(avl_node->left);
  int right = height(avl_node->right);
  return right - left;
}

void avl_insert_recurse(struct avl_tree_node_s *avl_node, int *value) {
  if (value <= avl_node->value) {
    if (avl_node->left) {
      avl_insert_recurse(avl_node->left, value);
    } else {
      struct avl_tree_node_s *new_node = new_avl_tree_node(value);
      avl_node->left = new_node;
    }
  } else {
    if (avl_node->right) {
      avl_insert_recurse(avl_node->right, value);
    } else {
      struct avl_tree_node_s *new_node = new_avl_tree_node(value);
      avl_node->right = new_node;
    }
  }
  int bf = balance_factor(avl_node);
  if (bf < -1 || bf > 1) {
    balance_node(avl_node, bf);
  }
  return;
}

void avl_insert(struct avl_tree_s *at, int *value) {
  if (at->root) {
    avl_insert_recurse(at->root, value);
  } else {
    at->root = new_avl_tree_node(value);
  }
  at->length++;
}

void print_avl_tree(struct avl_tree_s *at) {
  struct queue_s *q = malloc(sizeof(struct queue_s));
  q->length = 0;
  q->head = NULL;
  q->tail = NULL;
  if (at->root) {
    enqueue(q, (int *)at->root);
    printf("Avl Bfs: [ ");
    while (q->length > 0) {
      struct avl_tree_node_s *dq = (struct avl_tree_node_s *)dequeue(q);
      printf("%d[", dq->value);
      if (dq->left) {
        printf("l:%d,", dq->left->value);
      } else {
        printf("l:NULL,");
      }
      if (dq->right) {
        printf("r:%d], ", dq->right->value);
      } else {
        printf("r:NULL], ");
      }
      if (dq->left) {
        enqueue(&q, (int *)dq->left);
      }
      if (dq->right) {
        enqueue(&q, (int *)dq->right);
      }
    }
    printf("]\n");
  } else {
    printf("Avl Bfs: []\n");
  }
}
