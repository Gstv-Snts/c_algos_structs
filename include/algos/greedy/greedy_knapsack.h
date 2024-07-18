#ifndef GREEDY_KNAPSACK_H
#define GREEDY_KNAPSACK_H
struct item {
  float weight;
  float value;
};

float greedy_knapsack(float max_weight, struct item items[], int length);

#endif  // !GREEDY_KNAPSACK_H
