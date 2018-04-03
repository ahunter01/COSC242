#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void) {
    /* variable declirations */
    int i = 0;
    double j = 1.0;

    /* for loop */
    for (i = 0; i < 10; i++){
        printf("%3d %8.3f %7.3f\n", i, j, sqrt(j));
        j*=2;
    }

    return EXIT_SUCCESS;
}
