#include "algos/greedy/greedy_knapsack.h"

#include <stdio.h>

float greedy_knapsack(float max_weight, struct item* items, int length) {
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      if ((items[i].value / items[i].weight) <= (items[j].value / items[j].weight)) {
        struct item tmp = items[i];
        items[i] = items[j];
        items[j] = tmp;
      }
    }
  }
  float max_value = 0;
  float curr_weight = 0;
  for (int i = 0; i < length; i++) {
    if (curr_weight == max_weight) {
      break;
    }
    if (items[i].weight + curr_weight <= max_weight) {
      max_value += items[i].value;
      curr_weight += items[i].weight;
    }
  }
  return max_value;
};
