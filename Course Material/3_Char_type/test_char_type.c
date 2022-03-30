#include "unity.h"
#include "char_type.h"
void setUp()
{
}
void tearDown()
{
}

void test_upper_case_vowel(void)
{
  TEST_ASSERT_EQUAL(UPPER_CASE_VOWEL, find_char_type('A'));
  TEST_ASSERT_EQUAL(UPPER_CASE_VOWEL, find_char_type('E'));
  TEST_ASSERT_EQUAL(UPPER_CASE_VOWEL, find_char_type('I'));
  TEST_ASSERT_EQUAL(UPPER_CASE_VOWEL, find_char_type('O'));
  TEST_ASSERT_EQUAL(UPPER_CASE_VOWEL, find_char_type('U'));
}
void test_upper_case_consonant(void)
{
  TEST_ASSERT_EQUAL(UPPER_CASE_CONSONANT, find_char_type('B'));
  TEST_ASSERT_EQUAL(UPPER_CASE_CONSONANT, find_char_type('C'));
  TEST_ASSERT_EQUAL(UPPER_CASE_CONSONANT, find_char_type('D'));
  TEST_ASSERT_EQUAL(UPPER_CASE_CONSONANT, find_char_type('X'));
  TEST_ASSERT_EQUAL(UPPER_CASE_CONSONANT, find_char_type('Y'));
  TEST_ASSERT_EQUAL(UPPER_CASE_CONSONANT, find_char_type('Z'));
}
void test_lower_case_vowel(void)
{
  TEST_ASSERT_EQUAL(LOWER_CASE_VOWEL, find_char_type('a'));
  TEST_ASSERT_EQUAL(LOWER_CASE_VOWEL, find_char_type('e'));
  TEST_ASSERT_EQUAL(LOWER_CASE_VOWEL, find_char_type('i'));
  TEST_ASSERT_EQUAL(LOWER_CASE_VOWEL, find_char_type('o'));
  TEST_ASSERT_EQUAL(LOWER_CASE_VOWEL, find_char_type('u'));
}
void test_lower_case_consonant(void)
{
  TEST_ASSERT_EQUAL(LOWER_CASE_CONSONANT, find_char_type('b'));
  TEST_ASSERT_EQUAL(LOWER_CASE_CONSONANT, find_char_type('c'));
  TEST_ASSERT_EQUAL(LOWER_CASE_CONSONANT, find_char_type('d'));
  TEST_ASSERT_EQUAL(LOWER_CASE_CONSONANT, find_char_type('x'));
  TEST_ASSERT_EQUAL(LOWER_CASE_CONSONANT, find_char_type('y'));
  TEST_ASSERT_EQUAL(LOWER_CASE_CONSONANT, find_char_type('z'));
}
void test_number(void)
{
  TEST_ASSERT_EQUAL(NUMBER, find_char_type('0'));
  TEST_ASSERT_EQUAL(NUMBER, find_char_type('1'));
  TEST_ASSERT_EQUAL(NUMBER, find_char_type('4'));
  TEST_ASSERT_EQUAL(NUMBER, find_char_type('7'));
  TEST_ASSERT_EQUAL(NUMBER, find_char_type('9'));
}
void test_symbol(void)
{
  TEST_ASSERT_EQUAL(SYMBOL, find_char_type('*'));
  TEST_ASSERT_EQUAL(SYMBOL, find_char_type('['));
  TEST_ASSERT_EQUAL(SYMBOL, find_char_type('?'));
  TEST_ASSERT_EQUAL(SYMBOL, find_char_type('.'));
  TEST_ASSERT_EQUAL(SYMBOL, find_char_type('/'));
  TEST_ASSERT_EQUAL(SYMBOL, find_char_type('~'));
  TEST_ASSERT_EQUAL(SYMBOL, find_char_type('!'));

  TEST_ASSERT_EQUAL(SYMBOL, find_char_type(0xFF));
  TEST_ASSERT_EQUAL(SYMBOL, find_char_type(-120));
  TEST_ASSERT_EQUAL(SYMBOL, find_char_type(0));
  TEST_ASSERT_EQUAL(SYMBOL, find_char_type('\0'));
}


int main(void)
{
  UNITY_BEGIN();

  RUN_TEST(test_upper_case_vowel);
  RUN_TEST(test_upper_case_consonant);
  RUN_TEST(test_lower_case_vowel);
  RUN_TEST(test_lower_case_consonant);
  RUN_TEST(test_number);
  RUN_TEST(test_symbol);

  return UNITY_END();
}
