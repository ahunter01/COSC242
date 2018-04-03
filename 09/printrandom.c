#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char **argv){
    int i;

    if (argc<2){
        fprintf(stderr, "You forgot to chose a number\n");
    }
    
    for (i = 0; i < atoi(argv[1]); i++){
        printf("%d\n", rand());
    }
    
    return EXIT_SUCCESS;
}
