#include "Debug.h"
#include "iFloat.h"

/** @file iFloat.c
 *  @brief You will modify this file and implement nine functions
 *  @details Your implementation of the functions defined in iFloat.h.
 *  You may add other function if you find it helpful. Added function
 *  should be declared <b>static</b> to indicate they are only used
 *  within this file.
 *  <p>
 *  @author <b>Aidan Michalos</b> goes here
 */

/* declaration for useful function contained in testFloat.c */
const char* getBinary (iFloat_t value);

/*32 Bit IEEE
1 11111111 11111111111111111111111
One Eight     23
Sign Expo Fraction*/

/*16 bit IEEE
// 1 11111 1111111111
//One Five 10
Sign Expo Fraction*/

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatGetSign (iFloat_t x) {
  int mask = 1<<15;
    if ((x & mask)==mask) return 1;
  return 0; /* implement this */
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatGetExp (iFloat_t x) {
  int mask = 0, temp = 0;
  mask = 1 << 5;
  mask = mask - 1;
  temp = x >> 10;
  temp = temp & mask;
  return temp; 
  //return 0; /* implement this */
}

/** @todo Implement based on documentation contained in iFloat.h */
/*16 bit IEEE
// 1 11111 1111111111
//One Five 10
Sign Expo Fraction*/
iFloat_t floatGetVal (iFloat_t x) {
  int temp = 1;
  //-0.09375 sign: 1 exp: 11 val: 1111-1010-0000-0000
  temp <<= 10;

  temp = temp | (x & 0x03FF);

  if(floatGetSign(x) == 1)
    temp = ~(temp) + 1;

  return temp;
}

/** @todo Implement based on documentation contained in iFloat.h */
void floatGetAll(iFloat_t x, iFloat_t* sign, iFloat_t*exp, iFloat_t* val) {
  *sign = floatGetSign(x);
  *exp = floatGetExp(x);
  *val = floatGetVal(x);
}

/*32 Bit IEEE
1 11111111 11111111111111111111111
One Eight     23
Sign Expo Fraction*/

/*16 bit IEEE
// 1 11111 1111111111
//One Five 10
Sign Expo Fraction*/

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatLeftMost1 (iFloat_t bits) {
  
  for(int i = 15; i >= 0; i--){
    if((bits >> i) & 1)
      return i;
  }
  
  return -1;
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatAbs (iFloat_t x) {
  int mask = 0, temp = 0;
  mask = 1 << 15;
  mask = ~mask;
  temp = x & mask;

  return temp;
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatNegate (iFloat_t x) {
  if(x == 0){
    return floatAbs(x);}

    int xSign = floatGetSign(x);
    xSign = ~xSign;
    xSign = xSign << 15;
    int mask = 1 << 15;
    mask = ~mask;
    int temp = x & mask;
    temp |= xSign;
    return temp;
}

/*32 Bit IEEE
1 11111111 11111111111111111111111
One Eight     23
Sign Expo Fraction*/

/*16 bit IEEE
// 1 11111 1111111111
//One Five 10
Sign Expo Fraction*/

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatAdd (iFloat_t x, iFloat_t y) {
  debug("%s: bits of x (IEEE 754)", getBinary(x)); // example only
  debug("%s: bits of y (IEEE 754)", getBinary(y)); // example only
  
  /*

    -125.75 + 63.125 --> -62.625000
    
  */

  if(x == 0)
    return y;
  if(y == 0)
    return x;

  if((x < 0 || y < 0) && (floatAbs(x) == y ||  floatAbs(y) == x))
    return 0.0;

  //Step 1: Extract the exponent and value
  //x        Sign                    Exponent             Fraction/Value
  int  xExpo = floatGetExp(x), xVal = floatGetVal(x);
  //y        Sign                    Exponent             Fraction/Value
  int  yExpo = floatGetExp(y), yVal = floatGetVal(y);

  /*
  if(xSign == 1){
    xVal = ~xVal;
    xVal += 1;
  }
  if(ySign == 1){
    yVal = ~yVal;
    yVal += 1;
  }*/
  


  //Step 2: Equalize the exponents
  if(xExpo < yExpo){
    int temp = yExpo - xExpo;
    xVal = xVal >> temp;
    xExpo += temp;
  }

  if(yExpo < xExpo){
    int temp = xExpo - yExpo;
    yVal = yVal >> temp;
    yExpo += temp;
  }

  

  //Step 3: Integer addition
  int xy = xVal + yVal;
  //printf("Xy Val: %d", xy);

  /*16 bit IEEE
  // 1 11111 1111111111
  //One Five 10
  Sign Expo Fraction*/

  //Step 4: Convert the two's complement back to sign-magnitude
  int xySign = floatGetSign(xy);
  if(xySign == 1){
    xy = ~xy;
    xy += 1;
  }

//Step 5: Normalize the result

  int shift = 10 - floatLeftMost1(xy);

  xy = xy << shift;
  xExpo -= shift;

  

  //Step 6: Re-assemble all the components of the result into a 16-bit value
  int temp = 0;

  temp |= (xySign << 15);
  temp |= (xExpo << 10);
  temp |= (xy & 0x03FF);
  
  return temp;
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatSub (iFloat_t x, iFloat_t y) {
  return floatAdd(x, floatNegate(y));
}


/*
  xySign = xySign << 15;
  int starting = 10, mask = 0;
  for(int i = 15; i >= 0; i--){
    int temp = xy;
    temp = temp >> i;
    mask = 1;
    if((temp & mask) == 1){
      starting = i;
      break;
    }

  }
  
  
  while(starting > 10){
    xy = xy >> 1;
    xExpo += 1;
    starting -= 1;
  }
  while(starting<10){
    xy = xy << 1;
    xExpo -= 1;
    starting += 1;
  }

  xExpo = xExpo << 10;
  xy = floatGetVal(xy);
  mask = 0;
  mask = 1 << 10;
  xy ^= mask;*/