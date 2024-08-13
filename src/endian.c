/**
 * @file endian.c
 * @author Bryce Deary (bryce.deary@litegear.com)
 * @brief Implementation of endian.h and converters in arpa/inet.h
 * @date 2024-08-13
 * 
 * @copyright Copyright LightGear (2024)
 * 
 */
#include <stdlib.h>
#include "endian.h"

#ifdef HOST_IS_LE

uint32_t htonl(uint32_t hostlong)
{
  return (uint32_t){ hostlong >> 24 | 
                    ((hostlong & 0x00ff0000) >> 8) |
                    ((hostlong & 0x0000ff00) << 8) |
                    (hostlong << 24) };
}

uint16_t htons(uint16_t hostshort)
{
  return (uint16_t){ hostshort >> 8 | 
                     hostshort << 8 }; 
}

uint32_t ntohl(uint32_t netlong)
{
  return (uint32_t){ netlong >> 24 | 
                    ((netlong & 0x00ff0000) >> 8) |
                    ((netlong & 0x0000ff00) << 8) |
                    (netlong << 24) };
}

uint16_t ntohs(uint16_t netshort)
{
  return (uint16_t){ netshort >> 8 | 
                     netshort << 8 }; 
}

uint16_t htobe16(uint16_t host_16bits)
{
  return (uint16_t){ host_16bits >> 8 | 
                     host_16bits << 8 }; 
}

uint16_t htole16(uint16_t host_16bits)
{
  return host_16bits;
}

uint16_t be16toh(uint16_t big_endian_16bits)
{
  return (uint16_t){ big_endian_16bits >> 8 | 
                     big_endian_16bits << 8 }; 
}

uint16_t le16toh(uint16_t little_endian_16bits)
{
  return little_endian_16bits;
}

uint32_t htobe32(uint32_t host_32bits)
{
  return (uint32_t){ host_32bits >> 24 | 
                    ((host_32bits & 0x00ff0000) >> 8) |
                    ((host_32bits & 0x0000ff00) << 8) |
                    (host_32bits << 24) };
}

uint32_t htole32(uint32_t host_32bits)
{
  return host_32bits;
}

uint32_t be32toh(uint32_t big_endian_32bits)
{
  return (uint32_t){ big_endian_32bits >> 24 | 
                    ((big_endian_32bits & 0x00ff0000) >> 8) |
                    ((big_endian_32bits & 0x0000ff00) << 8) |
                    (big_endian_32bits << 24) };
}

uint32_t le32toh(uint32_t little_endian_32bits)
{
  return little_endian_32bits;
}

uint64_t htobe64(uint64_t host_64bits)
{
  return (uint64_t){ host_64bits >> 56 | 
                    ((host_64bits & 0x00FF000000000000ULL) >> 40) |
                    ((host_64bits & 0x0000FF0000000000ULL) >> 24) |
                    ((host_64bits & 0x000000FF00000000ULL) >> 8) |
                    ((host_64bits & 0x00000000FF000000ULL) << 8) |
                    ((host_64bits & 0x0000000000FF0000ULL) << 24) |
                    ((host_64bits & 0x000000000000FF00ULL) << 40) |
                    (host_64bits << 56) };
}

uint64_t htole64(uint64_t host_64bits)
{
  return host_64bits;
}

uint64_t be64toh(uint64_t big_endian_64bits)
{
  return (uint64_t){ big_endian_64bits >> 56 | 
                    ((big_endian_64bits & 0x00FF000000000000ULL) >> 40) |
                    ((big_endian_64bits & 0x0000FF0000000000ULL) >> 24) |
                    ((big_endian_64bits & 0x000000FF00000000ULL) >> 8) |
                    ((big_endian_64bits & 0x00000000FF000000ULL) << 8) |
                    ((big_endian_64bits & 0x0000000000FF0000ULL) << 24) |
                    ((big_endian_64bits & 0x000000000000FF00ULL) << 40) |
                    (big_endian_64bits << 56) };
}

uint64_t le64toh(uint64_t little_endian_64bits)
{
  return little_endian_64bits;
}

#else // host is Big Endian
#error "Need BE version of endian.h"

#endif
