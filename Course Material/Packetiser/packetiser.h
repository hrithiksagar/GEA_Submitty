/**
 * @file packetiser.h
 * @author GEA
 * @brief Functions to find and extract valid packets from a given data
 * @version 0.1
 * @date 2021-10-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef PACKETISER_H_
#define PACKETISER_H_

#include "stddef.h"
#include "stdint.h"
#include "string.h"

#define START_BYTE      (0xFF)
#define STOP_BYTE       (0x00)
#define HEADER_COUNT    (0x04)

#define START_BYET1_OFFSET  (0)
#define START_BYET2_OFFSET  (1)
#define LENGTH_BYTE_OFFSET  (2)
#define DATA_START_OFFSET   (3)
/** 
 * @enum error_t
 * @brief enum values for returning from functions
 */
typedef enum error_t
{
    SUCCESS,                    /**< Function call is successful */
    INVALID_PACKET,             /**< No valid packet found */
    NON_PERMITTED_OPERATION,    /**< Non permitted operation  */
    NULL_PTR                    /**< Function is given NULL pointers to work with */
}error_t;

/**
 * @brief Function to find and extract valid packets from input array
 * 
 * @param input_packet Input data cantaining raw data
 * @param input_packet_len Length of raw data
 * @param extracted_packet Extracted packet data
 * @param extracted_packet_len Length of the extracted packet including headers
 * @return error_t SUCCESS if valid packet is found, error_t otherwise
 * @note Function assumes that extracted_packet varible has enough memory to hold the extracted valid packet.
 */
error_t packet_finder(uint8_t* input_packet, size_t input_packet_len, uint8_t* extracted_packet, uint8_t* extracted_packet_len);


#endif /* PACKETISER_H_ */