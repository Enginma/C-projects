#include <stdio.h>
/*This program asks for a input and converts numbers and letters according to the given formula
The rest of the symbols are converted to '_'
Xianqi Cao U83561269*/

int main(){

    char x;
    printf("Enter input: ");
    while (x != '\n') {
        x = getchar();
        if (x <= '9' && x >= '0'){
            x = ((x - '0' + 6) % 10) + '0';
            printf("%c", x);
        }

        else if (x <= 'z' && x >= 'a'){
            x = ((x - 'a' + 6) % 26) + 'a';
            printf("%c", x);
        }

        else if (x <= 'Z' && x >= 'A'){
            x = ((x - 'A' + 6) % 26) + 'A';
            printf("%c", x);
        }

        else if (x <= '/' && x >= '!'){
            x = '_';
            printf("%c", x);
        }

        else if (x <= '@' && x >= ':'){
            x = '_';
            printf("%c", x);
        }

        else if (x <= '`' && x >= '['){
            x = '_';
            printf("%c", x);
        }

        else if (x <= '~' && x >= '{'){
            x = '_';
            printf("%c", x);
        }

        }
    return 0;

    }






