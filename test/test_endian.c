#ifdef TEST

#include "unity.h"

#include "endian.h"

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
















#endif // TEST
