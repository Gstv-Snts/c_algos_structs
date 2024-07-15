#include "algos/strings/naive.h"

#include <string.h>

#include "stdbool.h"

int naive(char* text, char* target) {
  bool matches = true;
  char* indexes;
  for (int i = 0; i < strlen(text) - strlen(target) + 1; i++) {
    for (int j = 0; j < strlen(target); j++) {
      if (*(text + (j + i)) != *(target + j)) {
        matches = false;
      }
    }
    if (matches) {
      return i;
    }
    matches = true;
  }
  return -1;
};
