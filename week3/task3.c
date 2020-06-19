#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void read_rest_of_line(void);
int addCsvNumbersTogether(char string[]);
int getIntFromCharArrayWithAtoi(char string[]);

#define LINELEN 80
#define EXTRACHARS 2
typedef enum {FALSE, TRUE} BOOLEAN;

int main(void) {
  char userInput[LINELEN + EXTRACHARS];
  int sum;
  BOOLEAN success = FALSE;
  while(!success) {
     printf("Enter numbers separated by comma\n");
     /* read in the line */
     fgets(userInput, LINELEN + EXTRACHARS, stdin);
     /* test if the newline character was stored - if not, its buffer
 *       * overflow and therefore must clear the buffer */
     if(userInput[strlen(userInput) - 1] != '\n') {
        printf("buffer overflow!\n");
        read_rest_of_line();
        continue;
     }
     /* if we get here then we have successfully got valid input length
 *       * so we set success to TRUE */
     success = TRUE;
     /* remove the newline character as it is no longer needed */
     userInput[strlen(userInput)-1] = 0;
     sum = addCsvNumbersTogether(userInput);
     printf( "Sum of all numbers is %d\n", sum);
  }
  return EXIT_SUCCESS;
}
void read_rest_of_line(void)
{
        /* character to read from the buffer */
        int ch;
        /* keep reading the buffer until we run out of
 *          * leftover input
 *                   */
        while(ch=getchar(), ch!=EOF&&ch!='\n');
        /* clear out the error status of the file pointer */
        clearerr(stdin);
}
/* Function takes in a comma separated string of integers, adds them together
 *  *  * and returns this total to the calling code
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
/* Function returns integer from char array */
int getIntFromCharArrayWithAtoi(char string[]) {
  int intResult;
  intResult = atoi(string);
  return intResult;
}
