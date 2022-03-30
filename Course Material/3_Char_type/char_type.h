/**
 * @file char_type.h
 * @author GEA
 * @brief Interface function for finding the type of character
 * @version 0.1
 * @date 2021-09-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef CHAR_TYPE_H_
#define CHAR_TYPE_H_

#include "stdio.h"
#include "stdbool.h"
#include <ctype.h>

/** @enum char_type_t
 *  @brief Definition of character types
 */
typedef enum char_type_t{
    NUMBER,                 /**< Character is a Number */
    SYMBOL,                 /**< Character is a Symbol */
    UPPER_CASE_VOWEL,       /**< Character is upper case and a vowel*/
    UPPER_CASE_CONSONANT,   /**< Character is upper case and consonant  */
    LOWER_CASE_VOWEL,       /**< Character is lower case and a vowel */
    LOWER_CASE_CONSONANT    /**< Character is is upper case and consonant */
}char_type_t;

/**
 * @brief Function to find the type of character
 * 
 * @param input_char input character whose type should be found
 * @return char_type_t returns char_type_t value based on the type of input_char
 * 
 */
char_type_t find_char_type(const char input_char);

#endif //#ifndef CHAR_TYPE_H_