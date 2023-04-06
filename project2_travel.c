#include <stdio.h>

/*
The program ask for the number of cases and base on the number entered will ask the user for speed a and b inputs 
until speed b is bigger than a, a while loop will multiply a by 2 and b by 3. In the end of the program for each case
the number of days for b to be faster than a is shown.
Xianqi Cao U83561269

*/



int main (){

    int speeda, speedb, cases;
    printf("Number of cases: ");
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++){
        printf("Speed of A: ");
        scanf("%d", &speeda);
        printf("Speed of B: ");
        scanf("%d", &speedb);
        int j = 0;
        while (speeda >= speedb){
            speeda *= 2;
            speedb *= 3;
            j += 1;
        }
        printf("Case #%d: %d day(s)\n", i, j);
    }


    return 0;
}