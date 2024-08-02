#include "structs/non_linear/b_tree.h"

#include <stdio.h>
#include <stdlib.h>

#include "structs/linear/list/linked_list.h"
#include "structs/linear/list/queue.h"

void free_b_tree(struct b_tree_s* bt) {
  if (bt->length > 0) {
    struct linked_list_s q;
    q.length = 0;
    q.head = NULL;
    q.tail = NULL;
    push_head(&q, (int*)bt->root);
    struct b_tree_node_s* dq = NULL;
    while (q.length > 0) {
      dq = (struct b_tree_node_s*)pop_tail(&q);
      if (dq->left != NULL) {
        push_head(&q, (int*)dq->left);
      }
      if (dq->right != NULL) {
        push_head(&q, (int*)dq->right);
      }
      free(dq);
      bt->length--;
    }
  }
};

void recurse_insert(struct b_tree_node_s* node, int* value) {
  if (node->left == NULL) {
    node->left = malloc(sizeof(struct b_tree_node_s));
    node->left->value = value;
    node->left->left = NULL;
    node->left->right = NULL;
    return;
  }
  if (node->right == NULL) {
    node->right = malloc(sizeof(struct b_tree_node_s));
    node->right->value = value;
    node->right->left = NULL;
    node->right->right = NULL;
    return;
  }
  recurse_insert(node->left, value);
  recurse_insert(node->right, value);
}
void insert(struct b_tree_s* bt, int* value) {
  if (bt->length == 0) {
    struct b_tree_node_s* new_node = malloc(sizeof(struct b_tree_node_s));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    bt->root = new_node;
    bt->length++;
    return;
  }
  recurse_insert(bt->root, value);
  bt->length++;
}

int* delete_node(struct b_tree_s* bt, struct b_tree_node_s* btn) {
  if (btn->right) {
    struct b_tree_node_s* prev = NULL;
    struct b_tree_node_s* curr = btn;
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
int* delete(struct b_tree_s* bt, int* target) {
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
  struct queue_s* q = malloc(sizeof(struct queue_s));
  q->length = 0;
  q->head = NULL;
  q->tail = NULL;
  enqueue(q, (int*)bt->root);
  while (q->length > 0) {
    struct b_tree_node_s* dq = (struct b_tree_node_s*)dequeue(q);
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
      enqueue(q, (int*)dq->left);
    }
    if (dq->right) {
      enqueue(q, (int*)dq->right);
    }
  }
  return NULL;
}

void print_b_tree(struct b_tree_s* bt) {
  struct queue_s* q = malloc(sizeof(struct queue_s));
  q->length = 0;
  q->head = NULL;
  q->tail = NULL;
  if (bt->root) {
    enqueue(q, (int*)bt->root);
    printf("b Tree Bfs: [");
    while (q->length > 0) {
      struct b_tree_node_s* dq = (struct b_tree_node_s*)dequeue(q);
      printf("%d,", dq->value);
      if (dq->left) {
        enqueue(q, (int*)dq->left);
      }
      if (dq->right) {
        enqueue(q, (int*)dq->right);
      }
    }
    printf("]\n");
  }
}
