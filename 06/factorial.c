#include <stdio.h>
#include <stdlib.h>

int factorial(int num){
    int fact= num;
    if (num > 1){
        fact *= factorial(num-1);
    }
    return fact;
}

int main(){
    int num;

    while (1 == scanf("%d", &num)){
        printf("%d\n", factorial(num));
    }
    return EXIT_SUCCESS;
}
