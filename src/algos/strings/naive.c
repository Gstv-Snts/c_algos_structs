#include <stdlib.h>
#include <string.h>

#include "stdbool.h"
#include "structs/linear/list/linked_list.h"

struct linked_list_s* naive(char* text, char* target) {
  bool matches = true;
  struct linked_list_s* indexes = malloc(sizeof(struct linked_list_s));
  for (int i = 0; i < strlen(text) - strlen(target) + 1; i++) {
    for (int j = 0; j < strlen(target); j++) {
      if (*(text + (j + i)) != *(target + j)) {
        matches = false;
      }
    }
    if (matches) {
      push_tail(indexes, (int*)i);
    }
    matches = true;
  }
  return indexes;
};
