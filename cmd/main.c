#include <stdint.h>
#include <stdlib.h>

#include "algos/strings/naive.h"
#include "structs/linear/list/linked_list.h"

int main() {
  struct linked_list_s* ll = malloc(sizeof(struct linked_list_s));
  push_head(ll, (int*)10);
  free_linked_list(ll);
  return 0;
}
