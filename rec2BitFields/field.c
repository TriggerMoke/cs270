#include "field.h"

/** @file field.c
 *  @brief You will modify this file and implement five functions
 *  @details Your implementation of the functions defined in field.h.
 *  You may add other function if you find it helpful. 
 * <p>
 * @author // Bitfield recitation
// Author: Aidan Michalos
// Date:   8/31/2022
// Class:  CS270
// Email:  aidanmih@colostate.edu
 */

/** @todo Implement in field.c based on documentation contained in field.h */
int getBit (int value, int position) {
    int mask = 1;
    return (value & (mask << position)) >> position;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int setBit (int value, int position) {
    int mask = 1;
    mask = mask << position;
    mask = value & mask;
    return value;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int clearBit (int value, int position) {
    return value;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int getField (int value, int hi, int lo, bool isSigned) {
    return 0;
}
