#include "algos/sorting/quicksort.h"

#include <stdio.h>

#include "structs/linear/list/linked_list.h"

void print_arr(int *arr[], int length) {
  length += 1;
  printf("Array: [ ");
  for (int i = 0; i < length; i++) {
    printf("%d:%d, ", i, *(arr + i));
  }
  printf(" ]\n");
}

void quicksort_recurse(int *arr[], int start, int end) {
  int pivot = start;
  if (((end + 1) - start) < 2) {
    return;
  }
  for (int i = start; i <= end; i++) {
    if (*(arr + i) < *(arr + pivot)) {
      int *tmp = *(arr + (pivot + 1));
      *(arr + (pivot + 1)) = *(arr + i);
      *(arr + i) = tmp;

      tmp = *(arr + pivot);
      *(arr + pivot) = *(arr + (pivot + 1));
      *(arr + (pivot + 1)) = tmp;

      pivot++;
    }
  }
  quicksort_recurse((int **)arr, start, pivot - 1);
  quicksort_recurse((int **)arr, pivot + 1, end);
}

void quicksort(int **arr, int length) {
  if (length > 1) {
    quicksort_recurse((int **)arr, 0, length - 1);
  }
}
