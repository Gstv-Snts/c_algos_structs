#include <stdio.h>
#include <sys/types.h>
u_int8_t ba[8];
int main() {
  for (u_int8_t i = 0; i < 8; i++) {
    *(ba + i) = 0;
  }
  *(ba + 3) = 1;
  for (u_int8_t i = 0; i < 8; i++) {
    printf("%d\n", *(ba + i));
  }
  return 0;
}
