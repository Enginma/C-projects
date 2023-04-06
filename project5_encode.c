//Xianqi Cao U83561269
// This program work with terminal commands and it convert characters to other characters dedicated 
// by the formula given in the problem. If the output its just ./a.out it will give Invalid Input response.

#include <stdio.h>
#include <string.h>


//In the encode function, it receives the array of strings one at a time and a new_string of arrays called output and it will be 
//encoded based on the formulas given. In the end it adds a null character to the end of string and ends it. 


void encode(char *input, char *output){

    int len = strlen(input);

    for (int i = 0; i < len; i++) {

        if (input[i] <= '9' && input[i] >= '0') {
            output[i] = ((input[i] - '0' + 6) % 10) + '0';

        } else if (input[i] <= 'z' && input[i] >= 'a') {
            output[i] = ((input[i] - 'a' + 6) % 26) + 'a';

        } else if (input[i] <= 'Z' && input[i] >= 'A') {
            output[i] = ((input[i] - 'A' + 6) % 26) + 'A';

        } else {
            output[i] = '_';

        }
    }
    
    output[len] = '\0';
}



//In the main function we need argc and *argv to take terminal input.

int main(int argc, char *argv[]){

// create an array of strings.
    char string1[argc-1][1000];

//In this for loop we are copying the strings into an array of strings I declared called string1[][].
// In the if statement we are simply checking to see if the input is just ./a.out. 

    for (int i=1; i < argc; i++){
        strcpy(string1[i-1], argv[i]);
    }

    if (argc < 2){
        printf("Invalid input!");
        return 0;
    }


//create a blank string of arrays for the encode function and sending both 2D arrays to the function.
    char new_string[argc - 1][1000];
    
    for (int i = 0; i < argc - 1; i++){
        encode(string1[i], new_string[i]);
    }

/* To print the output, I simply just put "Output: " and a new line character at the end of the problem to make it what is expected.

The for loop is used to go through each string in the new array of strings and printing them out one at a time until it reaches
the number of strings we have. 

Different from previous loops, we don't have to go through each character in the string anymore since it is already all converted. 

*/

    printf("Output: ");

    for (int i =0; i < argc - 1; i++){
        printf("%s", new_string[i]);
    }

    printf("\n");

    return 0;
}