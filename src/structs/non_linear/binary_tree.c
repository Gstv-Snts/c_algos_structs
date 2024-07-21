#include "structs/non_linear/binary_tree.h"

#include <stdio.h>
#include <stdlib.h>

#include "structs/linear/queue.h"

struct binary_tree_s new_binary_tree() {
  struct binary_tree_s bt;
  bt.length = 0;
  bt.root = NULL;
  return bt;
};

void insert(struct binary_tree_s* bt, int* value) {
  if (bt->length == 0) {
    struct binary_tree_node_s* newNode = malloc(sizeof(struct binary_tree_node_s));
    newNode->value = value;
    bt->root = newNode;
  } else {
    struct queue_s q = new_queue();
    enqueue(&q, (int*)bt->root);
    while (q.length > 0) {
      struct binary_tree_node_s* dq = (struct binary_tree_node_s*)dequeue(&q);
      if (!dq->left) {
        struct binary_tree_node_s* newNode = malloc(sizeof(struct binary_tree_node_s));
        newNode->value = value;
        dq->left = newNode;
        break;
      } else if (!dq->right) {
        struct binary_tree_node_s* newNode = malloc(sizeof(struct binary_tree_node_s));
        newNode->value = value;
        dq->right = newNode;
        break;
      } else {
        enqueue(&q, (int*)dq->left);
        enqueue(&q, (int*)dq->right);
      }
    }
  }
  bt->length++;
  printf("Length: %d\n", bt->length);
}

int* delete_node(struct binary_tree_s* bt, struct binary_tree_node_s* btn) {
  if (btn->right) {
    struct binary_tree_node_s* prev = NULL;
    struct binary_tree_node_s* curr = btn;
    while (curr->right) {
      prev = curr;
      curr = curr->right;
    }
    int* tmp = btn->value;
    btn->value = curr->value;
    prev->right = NULL;
    bt->length--;
    return tmp;
  } else {
    int* tmp = btn->value;
    btn->value = btn->left->value;
    btn->left = NULL;
    bt->length--;
    return tmp;
  }
}
int* delete(struct binary_tree_s* bt, int* target) {
  if (!bt->root) {
    return NULL;
  }
  if (bt->root->value == target) {
    if (!bt->root->left && !bt->root->right) {
      int* tmp = bt->root->value;
      bt->root = NULL;
      bt->length--;
      return tmp;
    }
    return delete_node(bt, bt->root);
  }
  struct queue_s q = new_queue();
  enqueue(&q, (int*)bt->root);
  while (q.length > 0) {
    struct binary_tree_node_s* dq = (struct binary_tree_node_s*)dequeue(&q);
    if (dq->left) {
      if (dq->left->value == target) {
        if (!dq->left->left && !dq->left->right) {
          int* tmp = dq->left->value;
          dq->left = NULL;
          bt->length--;
          return tmp;
        }
        return delete_node(bt, dq->left);
      }
    }
    if (dq->right) {
      if (dq->right->value == target) {
        if (!dq->right->left && !dq->right->right) {
          int* tmp = dq->right->value;
          dq->right = NULL;
          bt->length--;
          return tmp;
        }
        return delete_node(bt, dq->right);
      }
    }
    if (dq->left) {
      enqueue(&q, (int*)dq->left);
    }
    if (dq->right) {
      enqueue(&q, (int*)dq->right);
    }
  }
  return NULL;
}

void print_binary_tree(struct binary_tree_s* bt) {
  struct queue_s q = new_queue();
  if (bt->root) {
    enqueue(&q, (int*)bt->root);
    printf("Bfs: [");
    while (q.length > 0) {
      struct binary_tree_node_s* dq = (struct binary_tree_node_s*)dequeue(&q);
      printf("%d,", dq->value);
      if (dq->left) {
        enqueue(&q, (int*)dq->left);
      }
      if (dq->right) {
        enqueue(&q, (int*)dq->right);
      }
    }
    printf("]\n");
  }
}
