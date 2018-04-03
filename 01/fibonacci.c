#include <stdio.h>
#include <stdlib.h>

int main (void) {
    /* variable declirations */
    int f = 0;
    int g = 1;
    int c = 1;
    int t = 0;
    

    /* for loop */
    for (c = 1; c < 41; c++){
        printf("%12d", g);
        t = g;
        g += f;
        f = t;
        if(c%5 ==0){
            printf("\n");
        }
    }

    return EXIT_SUCCESS;
}
