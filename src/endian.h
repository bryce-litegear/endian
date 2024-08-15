/**
 * @file endian.h
 * @author Bryce Deary (bryce.deary@litegear.com)
 * @brief Implementation of the endian.h lib available in some linux and BSD
 *  distributions.  Also includes the TCP/IP version of the functions 
 *  typically available in <arpa/inet.h>, and finally includes macros to
 *  read and write sized values into and out of message buffers given a pointer.
 * @date 2024-08-13
 * 
 * @copyright Copyright LightGear (2024)
 * 
 */

#ifndef ENDIAN_H
#define ENDIAN_H

#include <stdint.h> 
#include <string.h>

#define HOST_IS_LE  // ARM processors have host as little endian

// host to Big Endian and Big Endian to host
uint32_t htonl(uint32_t hostlong);
uint16_t htons(uint16_t hostshort);

uint32_t ntohl(uint32_t netlong);
uint16_t ntohs(uint16_t netshort);

// More general with specific sizes in names
uint16_t htobe16(uint16_t host_16bits);
uint16_t htole16(uint16_t host_16bits);
uint16_t be16toh(uint16_t big_endian_16bits);
uint16_t le16toh(uint16_t little_endian_16bits);

uint32_t htobe32(uint32_t host_32bits);
uint32_t htole32(uint32_t host_32bits);
uint32_t be32toh(uint32_t big_endian_32bits);
uint32_t le32toh(uint32_t little_endian_32bits);

uint64_t htobe64(uint64_t host_64bits);
uint64_t htole64(uint64_t host_64bits);
uint64_t be64toh(uint64_t big_endian_64bits);
uint64_t le64toh(uint64_t little_endian_64bits);

// helper functions to just copy specified number of bytes
// at pointer location to sized type
inline static uint16_t load16(uint8_t *b) {
  uint16_t x;
  memcpy(&x, b, 2);
  return x;
}

inline static uint32_t load32(uint8_t *b) {
  uint32_t x;
  memcpy(&x, b, 4);
  return x;
}

inline static uint64_t load64(uint8_t *b) {
  uint64_t x;
  memcpy(&x, b, 8);
  return x;
}

// helper function to move sized type into buffer at pointer b
inline static void store16(uint8_t *b, uint16_t i) {
  memcpy(b, &i, 2);
}

inline static void store32(uint8_t *b, uint32_t i) {
  memcpy(b, &i, 4);
}

inline static void store64(uint8_t *b, uint64_t i) {
  memcpy(b, &i, 8);
}

// helper function to copy sized type into buffer using pointer
// b and updating pointer b to point beyond the written data
inline static void append16(uint8_t **b, uint16_t i) {
  memcpy(*b, &i, 2);
  *b+=2;
}

inline static void append32(uint8_t **b, uint32_t i) {
  memcpy(*b, &i, 4);
  *b+=4;
}

inline static void append64(uint8_t **b, uint64_t i) {
  memcpy(*b, &i, 8);
  *b+=8;
}

// helper function to extract sized type from buffer using pointer b
// and updating the pointer to point to next read point.
inline static uint16_t extract16(uint8_t **b) {
  uint16_t x;
  memcpy(&x, *b, 2);
  *b+=2;
  return x;
}

inline static uint32_t extract32(uint8_t **b) {
  uint32_t x;
  memcpy(&x, *b, 4);
  *b+=4;
  return x;
}

inline static uint64_t extract64(uint8_t **b) {
  uint64_t x;
  memcpy(&x, *b, 8);
  *b+=8;
  return x;
}

// Using the helper functions above, define macros to adjust sized types
// into and out of buffer at using pointer b with the selected byte ordering.

// functions that do not modify the pointer
#define load16_le(b) (le16toh(load16(b)))
#define store16_le(b, i) (store16(b, htole16(i)))
#define load16_be(b) (be16toh(load16(b)))
#define store16_be(b, i) (store16(b, htobe16(i)))
#define load32_le(b) (le32toh(load32(b)))
#define store32_le(b, i) (store32(b, htole32(i)))
#define load32_be(b) (be32toh(load32(b)))
#define store32_be(b, i) (store32(b, htobe32(i)))
#define load64_le(b) (le64toh(load64(b)))
#define store64_le(b, i) (store64(b, htole64(i)))
#define load64_be(b) (be64toh(load64(b)))
#define store64_be(b, i) (store64(b, htobe64(i)))

// functions that advance the pointer to the next field
#define extract16_le(b) (le16toh(extract16(&b)))
#define append16_le(b, i) (append16(&b, htole16(i)))
#define extract16_be(b) (be16toh(extract16(&b)))
#define append16_be(b, i) (append16(&b, htobe16(i)))
#define extract32_le(b) (le32toh(extract32(&b)))
#define append32_le(b, i) (append32(&b, htole32(i)))
#define extract32_be(b) (be32toh(extract32(&b)))
#define append32_be(b, i) (append32(&b, htobe32(i)))
#define extract64_le(b) (le64toh(extract64(&b)))
#define append64_le(b, i) (append64(&b, htole64(i)))
#define extract64_be(b) (be64toh(extract64(&b)))
#define append64_be(b, i) (append64(&b, htobe64(i)))






















#endif // ENDIAN_H
