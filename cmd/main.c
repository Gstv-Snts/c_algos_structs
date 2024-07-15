#include <stdio.h>
#include <sys/types.h>

#include "algos/sorting/bubble_sort.h"

int arr[] = {1, 3, 5, 7, 6, 2, 4, 6, 7, 0};
int sorted_arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main() {
  bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));
  for (int i = 0; i < 10; i++) {
    printf("%d,%d\n", *(sorted_arr + i), *(arr + i));
  }
  return 0;
}
