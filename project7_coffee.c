//XIANQI CAO U83561269


#include <stdio.h>
#include <string.h>


/*
This program sorts a file of coffees by the value they hold and creates a new file.
It involves one struct, a void function and a main function. 
*/


// This struct sets the five values that we will be using when writing to the new file as well as reading from input file. 
struct coffee {
    char country[1000];
    char region[1000];
    char owner[1000];
    char variety[1000]; 
    double score;
};


// A selection sort function that sorts the array based on value from highest to lowest. 

void selection_sort_coffee(struct coffee list[], int n){
    if (n == 1)
        return;
    int max = 0;
    for (int i=1; i < n; i++){
        if (list[i].score < list[max].score)
            max = i;
    }

    struct coffee coffee3 = list[n-1];
    list[n-1] = list[max];
    list[max] = coffee3;


// Instead of for loops a recursive function is used.
    selection_sort_coffee(list, n-1);
}


// Main function first declare the two arrays of the input file and the file that we will write to. 


int main() {
    char og_file[5000];
    char new_file[5000];

// Ask for user input and store it in og_file.
    printf("Enter the file name: ");
    scanf("%s", og_file); 

// Creates the file pointer fp to access files throughout the program.

    FILE *fp;
    fp = fopen(og_file, "r"); 

// This is just for personal use when testing the code, in this project this if statement is not needed. 

    if (fp == NULL) {
        printf("Error reading file. ");
        return 1;
    }


// Creates a struct variable and give it a big size so it can use the struct function we created above. Number variable is the counter for how many coffees. 
    struct coffee coffee2[1000];
    int number = 0;

// This while loop scans the input file and append each of the listed elements with a string or value. It will stop once it cannot appened all five elements. 

    while (fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%lf\n", 
        coffee2[number].country, 
        coffee2[number].region,
        coffee2[number].owner,
        coffee2[number].variety,
        &coffee2[number].score) == 5) {
        number++;
    }


// Calls the selection sort function above. 
    selection_sort_coffee(coffee2, number);
// Close the file.
    fclose(fp); 



// Creates the new file name with sorted_ infront of the input file. 
    strcpy(new_file, "sorted_");
    strcat(new_file, og_file);


// Opens the nonexisting file with "w" so it will create the file for us. 
    fp = fopen(new_file, "w");


// Writes the elements of the sorted to the new file
    for (int i = 0; i < number; i++){
        fprintf(fp, "%s,%s,%s,%s,%.2lf\n",
        coffee2[i].country, 
        coffee2[i].region,
        coffee2[i].owner,
        coffee2[i].variety,
        coffee2[i].score);
    }
    
// Close the file and print out the message. 
    fclose(fp);
    printf("Output file name:\nsorted_%s\n", og_file);
    return 0; 
}

