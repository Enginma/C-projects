#include <stdio.h>
/*
This program ask the user for a number input and it will check the sum of 
the number displayed. (for example 9999 if the input is 99, 
the sum of its digits is 18 (9+9). 


*/

// findDigit method using modolus to find the remainders and add them together
// until they are not bigger than 9
int findDigit(long int n){
        if (n>9){
        long int r;
        r = n % 10;
        n = n/10;
        n = r + n;
        n = findDigit(n);
}
        return n;
}


// main function asks the input and displays the checksum after calling the function findDigit
int main(){

        long int n;
        printf("Input: ");
        scanf("%ld", &n);
        printf("Checksum: %ld\n",findDigit(n));
        


        return 0;
}