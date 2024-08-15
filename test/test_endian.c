
#include "unity.h"

#include "endian.h"
#include <stdio.h>


void setUp(void)
{
}

void tearDown(void)
{
}


void test_htonl(void)
{
    TEST_ASSERT_EQUAL_HEX(0x78563412, htonl(0x12345678));
}           

void test_htons(void)
{
    TEST_ASSERT_EQUAL_HEX(0x3412, htons(0x1234 ));

}        

void test_ntohl(void)
{
    TEST_ASSERT_EQUAL_HEX(0x12345678, ntohl(0x78563412));
}           

void test_ntohs(void)
{
    TEST_ASSERT_EQUAL_HEX(0x1234, ntohs(0x3412));
}        

// More general with specific sizes in names
void test_htobe16(void)
{
    TEST_ASSERT_EQUAL_HEX(0x1234, htobe16(0x3412));

}          

void test_htole16(void)
{
    TEST_ASSERT_EQUAL_HEX(0x1234, htole16(0x1234));

}         

void test_be16toh(void)
{
    TEST_ASSERT_EQUAL_HEX(0x3412, be16toh(0x1234));

}      

void test_le16toh(void)
{
    TEST_ASSERT_EQUAL_HEX(0x1234, le16toh(0x1234 ));

}      

void test_htobe32(void)
{
    TEST_ASSERT_EQUAL_HEX(0x78563412, htobe32(0x12345678 ));

}       
void test_htole32(void)
{
    TEST_ASSERT_EQUAL_HEX(0x12345678, htole32(0x12345678));

}    
void test_be32toh(void)
{
    TEST_ASSERT_EQUAL_HEX(0x12345678, be32toh(0x78563412  ));

}    
void test_le32toh(void)
{
    TEST_ASSERT_EQUAL_HEX(0x12345678, le32toh(0x12345678  ));

}        

void test_htobe64(void)
{
    TEST_ASSERT_EQUAL_HEX64(0xf0debc9a78563412, htobe64(0x123456789abcdef0 ));

}        
void test_htole64(void)
{
    TEST_ASSERT_EQUAL_HEX64(0x123456789abcdef0, htole64(0x123456789abcdef0));

}      
void test_be64toh(void)
{
    TEST_ASSERT_EQUAL_HEX64(0x123456789abcdef0, be64toh(0xf0debc9a78563412 ));
}       
void test_le64toh(void)
{
    TEST_ASSERT_EQUAL_HEX64(0xf0debc9a78563412, le64toh(0xf0debc9a78563412 ));
}          


void test_buffer_builder_le(void)
{
    uint8_t buffer[200];
    uint8_t *b = buffer;
    memcpy(b++, &(uint8_t){0x5a}, 1);
    store16_le(b, 0x1234);
    b += sizeof(uint16_t);
    store32_le(b, 0x12345678);
    b += sizeof(uint32_t);
    store64_le(b, 0x87654321ABCDEF0ULL);
    b = buffer;
    TEST_ASSERT_EQUAL_HEX(0x5a, *b++);
    TEST_ASSERT_EQUAL_HEX(0x1234, load16_le(b) );
    b += sizeof(uint16_t);
    TEST_ASSERT_EQUAL_HEX(0x12345678, load32_le(b) );
    b += sizeof(uint32_t);
    TEST_ASSERT_EQUAL_HEX64(0x87654321ABCDEF0ULL, load64_le(b) );
}

void test_buffer_builder_be(void)
{
    uint8_t buffer[200];
    uint8_t *b = buffer;
    memcpy(b++, &(uint8_t){0x5a}, 1);
    store16_be(b, 0x1234);
    b += sizeof(uint16_t);
    store32_be(b, 0x12345678);
    b += sizeof(uint32_t);
    store64_be(b, 0x87654321ABCDEF0ULL);
    b = buffer;
    TEST_ASSERT_EQUAL_HEX(0x5a, *b++);
    TEST_ASSERT_EQUAL_HEX(0x1234, load16_be(b) );
    b += sizeof(uint16_t);
    TEST_ASSERT_EQUAL_HEX(0x12345678, load32_be(b) );
    b += sizeof(uint32_t);
    TEST_ASSERT_EQUAL_HEX64(0x87654321ABCDEF0ULL, load64_be(b) );
}

void test_buffer_builder_le2(void)
{
    uint8_t buffer[200];
    uint8_t *b = buffer;
    memcpy(b++, &(uint8_t){0x5a}, 1);
    TEST_ASSERT_EQUAL_PTR(&buffer[1], b);    
    append16_le(b, 0x1234);
    TEST_ASSERT_EQUAL_PTR(&buffer[1+2], b);        
    append32_le(b, 0x12345678);
    TEST_ASSERT_EQUAL_PTR(&buffer[1+2+4], b);        
    append64_le(b, 0x87654321ABCDEF0ULL);
    TEST_ASSERT_EQUAL_PTR(&buffer[1+2+4+8], b);        
    b = buffer;
    TEST_ASSERT_EQUAL_HEX(0x5a, *b++);
    TEST_ASSERT_EQUAL_PTR(&buffer[1], b);
    TEST_ASSERT_EQUAL_HEX(0x1234, extract16_le(b) );
    TEST_ASSERT_EQUAL_PTR(&buffer[3], b);
    TEST_ASSERT_EQUAL_HEX(0x12345678, extract32_le(b) );
    TEST_ASSERT_EQUAL_PTR(&buffer[7], b);
    TEST_ASSERT_EQUAL_HEX64(0x87654321ABCDEF0ULL, extract64_le(b) );
    TEST_ASSERT_EQUAL_PTR(&buffer[1+2+4+8], b);
    printf("le->");
    for(int i=0; &buffer[i] < b; i++) 
    {
        printf("%02X", buffer[i]);
    }
    printf("\n");    
}

void test_buffer_builder_be2(void)
{
    uint8_t buffer[200];
    uint8_t *b = buffer;
    memcpy(b++, &(uint8_t){0x5a}, 1);
    append16_be(b, 0x1234);
    append32_be(b, 0x12345678);
    append64_be(b, 0x87654321ABCDEF0ULL);
    b = buffer;
    TEST_ASSERT_EQUAL_HEX(0x5a, *b++);
    TEST_ASSERT_EQUAL_PTR(&buffer[1], b);    
    TEST_ASSERT_EQUAL_HEX(0x1234, extract16_be(b) );
    TEST_ASSERT_EQUAL_PTR(&buffer[3], b);    
    TEST_ASSERT_EQUAL_HEX(0x12345678, extract32_be(b) );
    TEST_ASSERT_EQUAL_PTR(&buffer[7], b);    
    TEST_ASSERT_EQUAL_HEX64(0x87654321ABCDEF0ULL, extract64_be(b) );
    TEST_ASSERT_EQUAL_PTR(&buffer[1+2+4+8], b);   
    printf("be->");    
    for(int i=0; &buffer[i] < b; i++) 
    {
        printf("%02X", buffer[i]);
    }
    printf("\n");
}


















