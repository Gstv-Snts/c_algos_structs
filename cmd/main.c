#include <stdio.h>
#include <sys/types.h>

#include "algos/strings/naive.h"

int main() {
  int i = naive("hello my name is", "name");
  printf("%d\n", i);
  return 0;
}
