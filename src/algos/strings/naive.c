#include "algos/strings/naive.h"

#include <string.h>

#include "stdbool.h"
#include "structs/linear/list/linked_list.h"

void naive(struct linked_list_s* indexes, char* text, char* target) {
  bool matches = true;
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
};
