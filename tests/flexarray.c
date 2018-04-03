#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

struct flexarrayrec{
    int capacity;
    int itemcount;
    int *items;
};

static void *emalloc(size_t s){
    void *d;
    d = malloc(s);
    if(NULL = d){
        fprintf("memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return d;
}

static void *erealloc(void *p, size_t s){
    void *d;
    d = realloc(p,s);
    if (NULL == d){
        fprintf("memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return d;
}

/* sort goes here */

flexarray flexarray_new(){
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}

void flexarray_append(flexarray f, int num){
    if (f->itemcount == f->capacity){
        f->capacity += f->capacity;
        f->items = erealloc(f->items, f->capacity *sizeof f->items[0]);
    }
    f->items[f->itemcount++] = num;
}

void flexarray_print(flexarray f){
    int i;
    for (i = 0; i < f->itemcount; i++){
        printf("d\n", f->items[i]);
    }
}

voif flexarray_sort(flexarray f){
    /*sort line here */
}

void flexarray_free(flexarray f){
    free(f->items);
    free(f);
}
