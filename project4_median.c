// Xianqi Cao U83561269
// This program contain two functions to find the amount of numbers that is the same as the median in a given array


#include <stdio.h>


// compute median function first arranges the array in descending order. 
int compute_median(int *a, int n){
    int *x;
    int *y;
    int temp;
    int halfed;
    int number;
    number = n;

//This arranges each number from highest to lowest by checking each number within the two for loops with pointer arithmetics.
    for (x = a; x < a+n; x++){    
        for (y = x + 1; y < a + n; y++){
            if (*x < *y){
                temp = *x;
                *x = *y;
                *y = temp;      
                }     
            }
        }

// A counter is set up  to keep in track of how many numbers is the same as the median number. If there are none counter will be 1.
    int median;
    int *p;
    int counter;
    counter = 0;
// This method is used to find the median for an even number input array like 4,6,8 etc
    if (number % 2 == 0){
        halfed = number / 2;
        median = (*(a+halfed) + *(a+halfed-1)) / 2;
        for (p = a; p < a + n; p++){
            if (median == *p)
                counter++;    
        }
        if (counter == 0)
            counter++;
        return counter;
    }
// This method is used to find the median for an odd number input array like 5,9,11 etc.
    if (number % 2 == 1){
        halfed = number / 2;
        median = *(a+halfed);
        for (p = a; p < a + n; p++){
            if (median == *p)
                counter++;    
        }
        if (counter == 0)
            counter++;  
        return counter;
    }
    


    return 0;
}    





// Main function ask for the array size and stores the elements in an array called median_array.



int main(){



    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    int median_array[size];

    printf("Enter array elements: ");
    int i;
    for (i=0; i < size; i++){
        scanf("%d", &median_array[i]);
    }
    
    int *p;
    p = median_array;                 

// Values are being passed to the compute median function above and it comes back to this print statement to output the value.
    printf("Output: %d\n" ,compute_median(p, size));

    return 0;
}


