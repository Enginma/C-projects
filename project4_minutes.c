#include <stdio.h>
// Xianqi Cao U83561269
// This program contains 2 functions as the main function ask for input of interesting minutes and find_minute function to determine the average watch time


int find_minute(int *minutes, int n){

//for loop use arithmetics to check if any timer is above 7 

    for (int *x = minutes + 1; x < minutes + n; x++){
        if (*minutes > 7)
            return 7;
        else if (*(x) - *(x-1) > 7)
            return *(x-1) + 7;

    }
// if all minutes passed then the dummy variable is used to check if it goes above 45, which is the max time and if it does it will return 45. 
    int dummy;
    dummy = *(minutes + n - 1) + 7;
    if (dummy > 45)
        return 45;
    else
        return dummy;
   
}



int main(){

    int intMin;

// getting the amount of interesting numbers and the exact interesting minutes. 
    printf("Enter the number of interesting minutes: ");
    scanf("%d", &intMin);
    int min_array[intMin];


    printf("Enter the interesting minutes: ");
    int i;
// for loop to create the array
    for (i = 0; i < intMin; i++){
        scanf("%d", &min_array[i]);
    }

    int *p;
    p = min_array;

// printing out the result after calling the find_minute function and passing p which is a pointer and intMin which is the length of the array
    printf("Output: %d\n", find_minute(p, intMin));



    return 0;
}