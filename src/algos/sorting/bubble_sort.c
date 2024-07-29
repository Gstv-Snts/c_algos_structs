#include "algos/sorting/bubble_sort.h"

void bubble_sort(int arr[], int length) {
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      if (arr[i] <= arr[j]) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
      }
    }
  }
}
