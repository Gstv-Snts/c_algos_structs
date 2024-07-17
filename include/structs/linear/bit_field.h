#ifndef BIT_FIELD_H
#define BIT_FIELD_H
#include <sys/types.h>

typedef struct __attribute__((packed)) {
  unsigned int day : 5;
  unsigned int month : 4;
  unsigned int year : 15;
} bit_field_date;

typedef struct __attribute__((packed)) {
  unsigned int red : 8;
  unsigned int green : 8;
  unsigned int blue : 8;
} bit_field_rgb;

#endif  // !BIT_FIELD_H
