#include <stdio.h>
#include <stdlib.h>

int is_prime (int candidate){
    int n = 0;
    for (n = 2; n< candidate; n++){
        if (candidate%n == 0) return 0;
    }
    return 1;
}

int main (void){
    int candidate = 2;
    int num_printed = 0;
    while (num_printed <100){
        if (is_prime(candidate)){
            printf("%5d", candidate);
            num_printed++;
        }
        candidate++;
    }
    return EXIT_SUCCESS;
}
