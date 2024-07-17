#include <stdint.h>
#include <sys/types.h>

#include "structs/linear/bit_array.h"
#include "unity.h"

u_int8_t ba[8];

void setUpBitArray(void) {
  for (u_int8_t i = 0; i < 8; i++) {
    *(ba + i) = 0;
  }
};

void tearDownBitArray(void) {};

void test_bit_array(void) {
  setUpBitArray();
  // or
  int i = or (ba, 2);
  TEST_ASSERT_EQUAL(i, 1);
  TEST_ASSERT_EQUAL(*(ba + 2), 1);
  i = or (ba, 6);
  TEST_ASSERT_EQUAL(i, 1);
  TEST_ASSERT_EQUAL(*(ba + 6), 1);
  i = or (ba, 2);
  TEST_ASSERT_EQUAL(i, 0);
  TEST_ASSERT_EQUAL(*(ba + 2), 1);

  // and
  i = and(ba, 2);
  TEST_ASSERT_EQUAL(i, 1);
  TEST_ASSERT_EQUAL(*(ba + 2), 0);
  i = and(ba, 6);
  TEST_ASSERT_EQUAL(i, 1);
  TEST_ASSERT_EQUAL(*(ba + 6), 0);
  i = and(ba, 2);
  TEST_ASSERT_EQUAL(i, 0);
  TEST_ASSERT_EQUAL(*(ba + 2), 0);

  // xor
  xor(ba, 2);
  TEST_ASSERT_EQUAL(*(ba + 2), 1);
  xor(ba, 6);
  TEST_ASSERT_EQUAL(*(ba + 6), 1);
  xor(ba, 2);
  TEST_ASSERT_EQUAL(*(ba + 2), 0);

  // not
  not(ba);
  TEST_ASSERT_EQUAL(*(ba + 0), 1);
  TEST_ASSERT_EQUAL(*(ba + 1), 1);
  TEST_ASSERT_EQUAL(*(ba + 2), 1);
  TEST_ASSERT_EQUAL(*(ba + 3), 1);
  TEST_ASSERT_EQUAL(*(ba + 4), 1);
  TEST_ASSERT_EQUAL(*(ba + 5), 1);
  TEST_ASSERT_EQUAL(*(ba + 6), 0);
  TEST_ASSERT_EQUAL(*(ba + 7), 1);
  not(ba);
  TEST_ASSERT_EQUAL(*(ba + 0), 0);
  TEST_ASSERT_EQUAL(*(ba + 1), 0);
  TEST_ASSERT_EQUAL(*(ba + 2), 0);
  TEST_ASSERT_EQUAL(*(ba + 3), 0);
  TEST_ASSERT_EQUAL(*(ba + 4), 0);
  TEST_ASSERT_EQUAL(*(ba + 5), 0);
  TEST_ASSERT_EQUAL(*(ba + 6), 1);
  TEST_ASSERT_EQUAL(*(ba + 7), 0);

  tearDownBitArray();
}
