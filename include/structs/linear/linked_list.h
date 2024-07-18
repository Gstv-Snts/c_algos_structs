#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/*
 * @brief: Struct for a linked list node.
 * @field1: The value of the node.
 * @field2: The next node on the list.
 * @field3: The previoues node on the list.
 */
struct linked_list_node_s {
  int value;
  struct linked_list_node_s* next;
  struct linked_list_node_s* previous;
};

/*
 * @brief: Struct for linked list.
 * @field1: The head of the list.
 * @field2: The tail of the list.
 * @field3: The length of the list.
 */
struct linked_list_s {
  struct linked_list_node_s* head;
  struct linked_list_node_s* tail;
  int length;
};

// get

// @return: Returns the heads pointer if exists, returns NULL if not.
struct linked_list_node_s* peak_head(struct linked_list_s* ll);
// @return: Returns the tails pointer if exists, returns NULL if not.
struct linked_list_node_s* peak_tail(struct linked_list_s* ll);
// @return: Returns the targets pointer if exists, returns NULL if not.
struct linked_list_node_s* find(struct linked_list_s* ll, int target);
// @brief: Prints all the nods on the list.
void print_all(struct linked_list_s ll);

// insert

// @brief: Inserts a node on the start of the list.
void push_head(struct linked_list_s* ll, int value);
// @brief: Inserts a node on the end of the list.
void push_tail(struct linked_list_s* ll, int value);

// delete

// @return: Returns the popped head if it exists, returns NULL if not.
struct linked_list_node_s* pop_head(struct linked_list_s* ll);
// @return: Returns the popped tail if it exists, returns NULL if not.
struct linked_list_node_s* pop_tail(struct linked_list_s* ll);

#endif  // DEBUG
