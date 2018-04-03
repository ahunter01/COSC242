#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

void *emalloc(size_t s){
    void *d;
    
    d = malloc (s);
    if (NULL == d){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return d;
}

void *erealloc(void *p, size_t s){
    void *d;
    d = realloc(p, s);
    
    if (NULL == d){
        fprintf(stderr, "Memory allocation failed!\n");
        exit (EXIT_FAILURE);
    }
    return d;
}
