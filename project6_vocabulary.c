// Xianqi Cao, U83561269. 
/* This program ask the user to input two files in the command prompt, the first file stores words and the program will run and reorganize the
words in alphabetical order and writes it in the second file and print the words out with no duplicates in order. 
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>


// command prompt argc length argv the inputs
int main(int argc, char *argv[]) {
    // Initialize array to store the words in the file and the index counter. 
    char words[2000][1000];  
    int i = 0;  
    // The file pointer fp is being created.
    FILE *fp;

//check for empty file, returns an error message if the file dont exist or empty. 
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }


/* 
This block of code changes all letters into uppercase. It will run as long as the words' index is not the end of line character.
Then another counter j is being initialized and as long as it is less than the length of the string with the string library function
it will change each word's characters into uppercase before moving on to the next. Once the first word's all characters have been turned
to upper, i is being incremented to go to the next word in the array "word" and the process continues until while ends. 
*/
    while (fscanf(fp, "%s", words[i]) != EOF) {
        for (int j = 0; j < strlen(words[i]); j++) {
            words[i][j] = toupper(words[i][j]);
        }
        i++;
    }

// closing the file as we are done reading from it since we stored the values in the words array. 
    fclose(fp);

// opens up the empty second file and write in it
    fp = fopen(argv[2], "w");


/*
This function will reorganize the variables in alphabetical order.
n is the first element of the array and m is the second element of the array. 
We use string compare to see if the second element is smaller than the first element which will return
a value that is negative, which is less than 10. If that is the case we perfrom the swap with string copy function and 
a tmp variable. 
Once n is less than i, meaning we reached all of the array and i is the total amount of elements in the previous while loop,
the list of words is going to be ordered in alphabetical order. 

*/
    for (int n = 0; n < i; n++){
        for (int m = n + 1; m < i; m++){
                if (strcmp(words[m], words[n]) < 0){
                char tmp[1000];
                strcpy(tmp, words[n]);
                strcpy(words[n], words[m]);
                strcpy(words[m], tmp);
            }
        }
    }

/*
This block of code is used to remove duplicates of the same string. Again, n is the first variable and m is the second variable and i is the length of array.
If the words in array "words" are the same, then it goes through a for loop with x being its index starting from value "m", which is the 
index of the duplicated variable. It uses the string copy function to replace the current duplicate word with the next word in the array
"m+1" and it continues until it reaches the end of the array, which means the duplicated word is now at the end of the array.
Then we remove the last element by decrementing the index of the array by 1 so the last element which is the duplicate no longer
exists in the array. We also decrease m because in the end of the second for loop m will be +1, but we need it to check the same index 
again since the value is now the next string in the array. Once n is the same size as the new array size, all duplicates will be removed. 

*/
    for (int n = 0; n < i; n++) {
        for (int m = n + 1; m < i; m++) {
            if (strcmp(words[n], words[m]) == 0) { 
                for (int x = m; x < i; x++) { 
                    strcpy(words[x], words[x+1]);
                }
                i--; 
                m--; 
            }
        }
    }


// This statement prints the values from the file that we wrote in as well as a Number showing its index starting with 1 beforehand. To prevent an 
// Extra number from being printed, we stop the print once it is equal to the index. Afterwards once every word has been printed we close the file. 
    for (int j = 0; j < i; j++) {
        if (j != i)
            fprintf(fp,"%d ", j+1);
        fprintf(fp,"%s\n", words[j]);
    }
      fclose(fp);

    return 0;
}
