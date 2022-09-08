// P2 Assignment
// Author: Aidan Michalos
// Date:   8/30/2022
// Class:  CS270
// Email:  aidanmih@colostate.edu

//ERm missed this recitation and didn't have time to really finish it sadly

#include <stdio.h>

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
char int_to_char (int value, int radix) {
  if(value >= 0 && value <= 9)
    return '0'+value;
  
  if(value > radix-1 || value < 0)
    return '?';
  
  return 55 + value;
  //Check that value is single digit in base radix
  //get the ASCII char to digit
  //Return ASCII char
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
int char_to_int (char digit, int radix) {
  if(digit >= '0' && digit <= '9')
    return digit - '0';
  if(digit >= 'a' && digit <= 'z')
    return 10 + (digit - 'a');
  if(digit >= 'A' && digit <= 'Z'){
    digit += 32;
    return char_to_int(digit, radix);
  }



  return -1;
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
void div_rem (int numerator, int divisor, int* remainder, int* quotient) {
  *quotient = numerator / divisor;
  *remainder = numerator % divisor;
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
int ascii_to_int (int valueOfPrefix, int radix) {
  return -1;
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
void int_to_ascii (int value, int radix) {
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
double frac_to_double (int radix) {
  return -1.0;
}

