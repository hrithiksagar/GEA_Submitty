#include "string_to_date.h"
#include "unity.h"

void setUp()
{
}
void tearDown()
{
}

void test_null_params(void)
{
    char* str_date = "23/11/2021";
    my_date_t converted_date = {0,0,0};

    TEST_ASSERT_EQUAL(NULL_PTR, string_to_date_converter(NULL, NULL));
    TEST_ASSERT_EQUAL(NULL_PTR, string_to_date_converter(str_date, NULL));
    TEST_ASSERT_EQUAL(NULL_PTR, string_to_date_converter(NULL, &converted_date));

}
void test_valid_params(void)
{
    char* str_date = calloc(MAX_STR_LEN, sizeof(char));
    strncpy(str_date, "23/11/1234", MAX_STR_LEN);

    my_date_t converted_date = {0,0,0};

    TEST_ASSERT_EQUAL(SUCCESS, string_to_date_converter(str_date, &converted_date));
    TEST_ASSERT_EQUAL(23, converted_date.date);
    TEST_ASSERT_EQUAL(11, converted_date.month);
    TEST_ASSERT_EQUAL(1234, converted_date.year);

    free(str_date);
    str_date = NULL;
}
void test_invalid_params(void)
{
    char* str_date = calloc(MAX_STR_LEN, sizeof(char));
    my_date_t converted_date = {0,0,0};

    strncpy(str_date, "-1/11/1234", MAX_STR_LEN);
    TEST_ASSERT_EQUAL(INCORRECT, string_to_date_converter(str_date, &converted_date));
    
    strncpy(str_date, "32/11/1234", MAX_STR_LEN);
    TEST_ASSERT_EQUAL(INCORRECT, string_to_date_converter(str_date, &converted_date));
    
    strncpy(str_date, "0/11/1234", MAX_STR_LEN);
    TEST_ASSERT_EQUAL(INCORRECT, string_to_date_converter(str_date, &converted_date));

    strncpy(str_date, "11/13/1234", MAX_STR_LEN);
    TEST_ASSERT_EQUAL(INCORRECT, string_to_date_converter(str_date, &converted_date));

    strncpy(str_date, "11/-1/1234", MAX_STR_LEN);
    TEST_ASSERT_EQUAL(INCORRECT, string_to_date_converter(str_date, &converted_date));
    
    strncpy(str_date, "11/0/1234", MAX_STR_LEN);
    TEST_ASSERT_EQUAL(INCORRECT, string_to_date_converter(str_date, &converted_date));

    strncpy(str_date, "11/10/-1234", MAX_STR_LEN);
    TEST_ASSERT_EQUAL(INCORRECT, string_to_date_converter(str_date, &converted_date));

    strncpy(str_date, "11/10/0", MAX_STR_LEN);
    TEST_ASSERT_EQUAL(INCORRECT, string_to_date_converter(str_date, &converted_date));
    free(str_date);
    str_date = NULL;
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_null_params);
    RUN_TEST(test_valid_params);
    RUN_TEST(test_invalid_params);
    return UNITY_END();
}
