#include <stdio.h>
#include <stdlib.h>
/* Function returns integer from char array */
int getIntFromCharArrayWithAtoi(char string[]) {
  int intResult;
  intResult = atoi(string);
  return intResult;
}
/* Function returns long from char array */
long getLongfromCharArrayWithStrTol(char string[]) {
  long lngResult;
  int base = 10; /* base can  be between 2 and 36 */
  char* endPtr; /* used by the strtol function to indicate where the conversion stopped */
  /* strtol function skips all white-space characters at the beginning of the string, converts
 *    * the subsequent characters as part of the number, and then stops when it encounters the
 *       * first character that isn't a number. */
  lngResult = strtol(string, &endPtr, base);
  return lngResult;
}

int main(void) {
  char string1[] = "34blabla";
  char string2[] = "bla34abla";
  char string3[] = "1450909999333340";
  int result;
  long resultLongInt;
  result = getIntFromCharArrayWithAtoi(string1);
  printf("String'%s' to int using atoi() result: %d\n", string1, result);
  result = getIntFromCharArrayWithAtoi(string2);
  printf("String'%s' to int using atoi() result: %d\n", string2, result);
  /* In most compilers this will result in most significant bit truncation
 *    * because the number is too large for integer.
 *       * 1450909999333340 signed int  is 0000000000000101001001111001100001001111000111000111111111011100
 *          * 00000000000001010010011110011000 significant buts are truncated which results
 *             * in 01001111000111000111111111011100
 *                */
  result = getIntFromCharArrayWithAtoi(string3);
  printf("String'%s' to int using atoi() result: %d truncated after 32 bits\n", string3, result);
  resultLongInt = getLongfromCharArrayWithStrTol(string1);
  printf("String'%s' to int using strtol() result: %ld\n", string1, resultLongInt);
  resultLongInt = getLongfromCharArrayWithStrTol(string2);
  printf("String'%s' to int using strtol() result: %ld\n", string2, resultLongInt);
  resultLongInt = getLongfromCharArrayWithStrTol(string3);
  printf("String'%s' to int using strtol() result: %ld\n", string3, resultLongInt);
  return EXIT_SUCCESS;
}
