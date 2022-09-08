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
    return mask;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int clearBit (int value, int position) {
    int mask = 1;
    mask = mask << position;
    mask = ~mask;
    mask = value&mask;
    return mask;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int getField (int value, int hi, int lo, bool isSigned) {
    isSigned = (value >> (hi-1)) & isSigned;
    int temp = value >> lo, mix = hi - lo;
    isSigned = isSigned & (mix != 0);
    mix = mix - isSigned;
    int ans = temp & ((1 << mix) - 1);

    if(isSigned){
        return -ans;
    }
    return ans;

    //return 0;
}
