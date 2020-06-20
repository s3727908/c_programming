#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/* Max allowed input size for fgets */
#define LINELEN 80
#define EXTRACHARS 2
typedef enum {FALSE, TRUE} BOOLEAN;
void read_rest_of_line(void);

int main(void) {
/* Declare variables */
  char userInput[LINELEN + EXTRACHARS];
  int numbers = 0;
  int uppercase = 0;
  int lowercase = 0;
  int spaces = 0;
  BOOLEAN success = FALSE;
  /* Get user input */
  while(!success) {
     printf("Enter a string:\n");
     /* read in the line */
     fgets(userInput, LINELEN + EXTRACHARS, stdin);
     /* test if the newline character was stored - if not, its buffer
        overflow and therefore must clear the buffer */
     if(userInput[strlen(userInput) - 1] != '\n') {
        printf("buffer overflow!\n");
        read_rest_of_line();
        continue;
     }
     /* if we get here then we have successfully got valid input length
         so we set success to TRUE */
     success = TRUE;
     /* remove the newline character as it is no longer needed */
     userInput[strlen(userInput)-1] = 0;
  }
  printf("%s\n", userInput);
  int i;
  for (i=0; i <= strlen(userInput); i++) {
     if (isdigit(userInput[i])) {
        numbers += 1;
     }
     else if (isupper(userInput[i])) {
        uppercase += 1;
     }
     else if (islower(userInput[i])) {
        lowercase += 1;
     }
     else if (isblank(userInput[i])) {
        spaces += 1;
     }

  }
  printf("Input had numbers:\t%d\nupper case:\t%d\nlower case:\t%d\nspaces:\t\t%d\n", numbers, uppercase, lowercase, spaces);
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
