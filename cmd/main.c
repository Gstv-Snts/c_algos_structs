#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include "structs/linear/queue.h"
#include "structs/non_linear/binary_tree.h"

int main() {
  struct binary_tree_s bt = new_binary_tree();
  insert(&bt, (int*)10);
  insert(&bt, (int*)20);
  insert(&bt, (int*)30);
  insert(&bt, (int*)40);
  insert(&bt, (int*)50);
  insert(&bt, (int*)60);
  insert(&bt, (int*)70);
  print_binary_tree(&bt);

  return 0;
}
