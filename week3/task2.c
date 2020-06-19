#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/* Function returns integer from char array */
int getIntFromCharArrayWithAtoi(char string[]) {
  int intResult;
  intResult = atoi(string);
  return intResult;
}
/* Function takes in a comma separated string of integers, adds them together
 *  * and returns this total to the calling code
 *  */
int addCsvNumbersTogether(char string[]) {
  int sum = 0;
  char* token = strtok(string, ","); /* Extract the first token */
  while(token != NULL) {           /* loop through the string to extract all other tokens */
     int intToken = getIntFromCharArrayWithAtoi(token); /* Get integer from token */
     sum = sum + intToken;
     token = strtok(NULL, ",");
  }
  return sum;
}

int main(void) {
  char strNumbers[] = "10,11,12,13,14";
  int sum;
  sum = addCsvNumbersTogether(strNumbers);
  printf( "Sum of all numbers is %d\n", sum);
  return EXIT_SUCCESS;
}
