#include "packetiser.h"
#include "unity.h"

/* Required by the unity test framework */
void setUp()
{
}
/* Required by the unity test framework */
void tearDown()
{
}

void test_with_null()
{ 
    uint8_t input[7] = {START_BYTE, START_BYTE, 0x03, 0xAC, 0xBD, 0xEF, 0x00};
    uint8_t output[7] = {};
    uint8_t packet_len = 0;

    TEST_ASSERT_EQUAL(NULL_PTR, packet_finder(NULL, 0, NULL, NULL));
    TEST_ASSERT_EQUAL(NULL_PTR, packet_finder(input, 0, NULL, NULL));
    TEST_ASSERT_EQUAL(NULL_PTR, packet_finder(input, 7, output, NULL));
    TEST_ASSERT_EQUAL(NULL_PTR, packet_finder(input, 7, NULL, &packet_len));
    TEST_ASSERT_EQUAL(NULL_PTR, packet_finder(input, 0, NULL, &packet_len));
    TEST_ASSERT_EQUAL(NULL_PTR, packet_finder(input, 0, output, NULL));
}
void test_invalid_packet()
{
    uint8_t output[10] = {};
    uint8_t packet_len = 0;
    
    uint8_t input1[10] = {START_BYTE, START_BYTE, STOP_BYTE, 0xAC, 0xBD, 0xEF, 0x45, 0x51, 0xAA};
    TEST_ASSERT_EQUAL(INVALID_PACKET, packet_finder(input1, 0, output, &packet_len));
    TEST_ASSERT_EQUAL(INVALID_PACKET, packet_finder(input1, 10, output, &packet_len));

    uint8_t input2[10] = {0x01, 0xAC, 0xBD, 0xEF, 0x01, 0x45, 0x51, 0xAA};
    TEST_ASSERT_EQUAL(INVALID_PACKET, packet_finder(input2, 8, output, &packet_len));

    uint8_t input3[10] = {START_BYTE, 0xAC, 0xBD, 0xEF, 0x01, 0x45, 0x51, 0xAA};
    TEST_ASSERT_EQUAL(INVALID_PACKET, packet_finder(input3, 8, output, &packet_len));

    uint8_t input4[6] = {0xAC, 0xBD, 0xEF, 0x01, START_BYTE, START_BYTE};
    TEST_ASSERT_EQUAL(INVALID_PACKET, packet_finder(input4, 6, output, &packet_len));

    uint8_t input5[5] = {0xAC, 0xBD, 0xEF, 0x01, START_BYTE};
    TEST_ASSERT_EQUAL(INVALID_PACKET, packet_finder(input5, 5, output, &packet_len));

    uint8_t input6[7] = {0xAC, 0xBD, 0xEF, 0x01, START_BYTE, START_BYTE, 0x03};
    TEST_ASSERT_EQUAL(INVALID_PACKET, packet_finder(input6, 7, output, &packet_len));

    uint8_t input7[7] = {0x01, START_BYTE, START_BYTE, 0x03, 0x02, 0x01, 0x01};
    TEST_ASSERT_EQUAL(INVALID_PACKET, packet_finder(input7, 7, output, &packet_len));
}
void test_valid_packet()
{
    uint8_t input1[10] = {START_BYTE, START_BYTE, 0x03, 0xAC, 0xBD, 0xEF, STOP_BYTE, 0x45, 0x51, 0xAA};
    uint8_t output_packet1[10] = {};
    uint8_t packet_len1 = 0;
    uint8_t expected_packet1[10] = {START_BYTE, START_BYTE, 0x03, 0xAC, 0xBD, 0xEF, STOP_BYTE};
    
    TEST_ASSERT_EQUAL(SUCCESS, packet_finder(input1, 10, output_packet1, &packet_len1));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(expected_packet1, output_packet1, 7);
    TEST_ASSERT_EQUAL(7, packet_len1);

    uint8_t input2[10] = {0x01, 0xA0, START_BYTE, START_BYTE, 0x03, 0xAC, 0xBD, 0xEF, STOP_BYTE, 0xBC};
    uint8_t output_packet2[10] = {};
    uint8_t packet_len2 = 0;
    uint8_t expected_packet2[10] = {START_BYTE, START_BYTE, 0x03, 0xAC, 0xBD, 0xEF, STOP_BYTE};
    
    TEST_ASSERT_EQUAL(SUCCESS, packet_finder(input2, 10, output_packet2, &packet_len2));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(expected_packet2, output_packet2, 7);
    TEST_ASSERT_EQUAL(7, packet_len2);

    uint8_t input3[10] = {0x01, 0xA0, START_BYTE, START_BYTE, 0x01, 0xAC, STOP_BYTE, 0xBC};
    uint8_t output_packet3[10] = {};
    uint8_t packet_len3 = 0;
    uint8_t expected_packet3[10] = {START_BYTE, START_BYTE, 0x01, 0xAC, STOP_BYTE};
    
    TEST_ASSERT_EQUAL(SUCCESS, packet_finder(input3, 10, output_packet3, &packet_len3));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(expected_packet3, output_packet3, 5);
    TEST_ASSERT_EQUAL(5, packet_len3);
}
int main(void)
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();

    /* Run Test functions */
    RUN_TEST(test_with_null);
    RUN_TEST(test_invalid_packet);
    RUN_TEST(test_valid_packet);
  
    /* Close the Unity Test Framework */
    return UNITY_END();
}