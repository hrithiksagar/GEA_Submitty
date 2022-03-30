/**
 * @file string_to_date.h
 * @author Bharath G (Bharath.g@ltts.com)
 * @brief Interface function for converting string of the format DD/MM/YYYY to Date structure
 * @version 0.1
 * @date 2021-11-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef STRING_TO_DATE_H__
#define STRING_TO_DATE_H__

#include "stdlib.h"
#include "string.h"

#define MAX_STR_LEN     (20)   /**< Maximum String length */
#define DELIMITER       ("/")   /**< Delimiter used in the string format */

/** 
 * @enum error_t
 * @brief enum values for returning from functions
 */
typedef enum error_t
{
    SUCCESS,                    /**< Function call is successful */
    NULL_PTR,                   /**< Function is given NULL pointers to work with */
    INCORRECT                   /**< Incorrect values for date or month or year */
}error_t;

/**
 * @brief Structure definition for date
 * 
 */
typedef struct my_date_t
{
    int date;       /*<<< date */
    int month;      /*<<< month */
    int year;       /*<<< year   */
}my_date_t;


/**
 * @brief Function to convert string of the format DD/MM/YYYY to my_date_t structure
 * 
 * @param input_string String which needs to be converted
 * @param result_time Resultant structure to hold the converted string
 * @return error_t SUCCESS if conversion is done, error_t code otherwise.
 */
error_t string_to_date_converter(char* input_string, my_date_t* result_date);

#endif
