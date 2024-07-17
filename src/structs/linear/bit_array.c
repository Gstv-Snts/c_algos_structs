#include "structs/linear/bit_array.h"

#include <sys/types.h>

int or (u_int8_t ba[], int i) {
  if (ba[i] == 0) {
    *(ba + i) = 1;
    return 1;
  } else {
    return 0;
  }
}

int and (bit_array ba, int i) {
  if (ba[i] == 1) {
    *(ba + i) = 0;
    return 1;
  } else {
    return 0;
  }
}

void xor (bit_array ba, int i) {
  if (ba[i] == 1) {
    *(ba + i) = 0;
  } else {
    *(ba + i) = 1;
  }
}

void not(bit_array ba) {
  for (int i = 0; i < 8; i++) {
    if (ba[i] == 1) {
      *(ba + i) = 0;
    } else {
      *(ba + i) = 1;
    }
  }
}
