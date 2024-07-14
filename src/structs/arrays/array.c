#include "structs/arrays/array.h"

int findArrayValueIndex(int *arr, int value) {
  for (int i = 0; i < sizeof(arr); i++) {
    if (arr[i] == value) {
      return i;
    }
  }
  return -1;
}
