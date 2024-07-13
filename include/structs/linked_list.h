#ifndef LINKED_LIST_H
#define LINKED_LIST_H
/*
 *@Brief: Struct for a Linked List Node.
 */
typedef struct {
  int value;
  struct LinkedListNode* next;
  struct LinkedListNode* previous;
} LinkedListNode;

/*
 * @Brief: Function for starting an Linked List Node.
 * @Param1: Pointer to the node
 * @Param2: Value of the node
 * @Param3: Pointer to the next node
 * @Param3: Pointer to the previous node
 */
void linked_list_node_init(LinkedListNode* node, int value, LinkedListNode* next,
                           LinkedListNode* previous);

typedef struct {
  LinkedListNode* head;
  LinkedListNode* tail;
} LinkedList;

#endif  // !LINKED_LIST_H
