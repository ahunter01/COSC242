#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "htable.h"

int main (int argc, char**argv){

    int size;
    htable h;
    char word[256];

    if (argc <2){
        fprintf(stderr, "You entered: %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    size = atoi(argv[1]);
    h = htable_new(size);

    while (getword(word, sizeof word, stdin) != EOF){
        htable_insert(h, word);
    }

    htable_print(h, stdout);
    htable_free(h);

    return EXIT_SUCCESS;
}
