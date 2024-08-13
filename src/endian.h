/**
 * @file endian.h
 * @author Bryce Deary (bryce.deary@litegear.com)
 * @brief Implementation of the endian.h lib available in some linux and BSD
 *  distributions.  Also includes the TCP/IP version of the functions 
 *  typically available in <arpa/inet.h>
 * @date 2024-08-13
 * 
 * @copyright Copyright LightGear (2024)
 * 
 */

#ifndef ENDIAN_H
#define ENDIAN_H

#include <stdint.h> 

#define HOST_IS_LE

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

#endif // ENDIAN_H
