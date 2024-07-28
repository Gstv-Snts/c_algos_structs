#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H
#include <stdint.h>
#include <sys/types.h>

typedef u_int8_t bit_array[8];
/**
 * Set a bit the 1
 * @brief: 1,0,0,1,1,0,1,1 First bit array
 * @brief: 0,0,0,0,0,1,0,0 Second bit array
 * @brief: 1,0,0,1,1,1,1,1 Result bit array
 * @param1: Bit Array
 * @param2: Index of the bit to be changed
 * @return: 1 if the bit have been changed, 0 if the bit
 * already was set to 1
 */
int or (bit_array ba, int i);

/**
 * Set a bit to 0
 * @brief: 1,0,0,1,1,1,1,1 First bit array
 * @brief: 1,1,1,1,1,0,1,1 Second bit array
 * @brief: 1,0,0,1,1,0,1,1 Result bit array
 * @param1: Bit Array
 * @param2: Index of the bit to be changed
 * @return: 1 if the bit have been changed, 0 if the bit
 * already was set to 0
 */
int and (bit_array ba, int i);

/**
 * Inverts a bit
 * @brief: 1,0,0,1,1,1,1,1 First bit array
 * @brief: 0,0,0,0,1,0,0,0 Second bit array
 * @brief: 1,0,0,1,0,0,1,1 Result bit array
 * @brief: 1,0,0,1,1,1,1,1 First bit array
 * @brief: 0,0,1,0,0,0,0,0 Second bit array
 * @brief: 1,0,1,1,0,0,1,1 Result bit array
 * @param1: Bit Array
 * @param2: Index of the bit to be changed
 */
void xor (bit_array ba, int i);

/*
 * Inverts [ALL] bits
 * @brief: 1,0,0,1,1,1,1,1 [Before]
 * @brief: 0,1,1,0,0,0,0,0 [After]
 */
void not(bit_array ba);

#endif  // !BIT_ARRAY_H
