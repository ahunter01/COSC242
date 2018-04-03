#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "flexarray.h"

/* 
 * COSC242 Assignment 
 * Authors: Sophie Purdie, Amanda Veldman, Kiri Lenagh-Glue
 */


/*
 * The flexarray is comprised of:
 * capacity: the size of the flexarray
 * itemcount: the number of items stored in the flexarray
 * items: A pointer which will contain strings
 */
struct flexarrayrec {
    int capacity;
    int itemcount;
    char **items;
};

/*
 * This function creates a new flexarray and sets its initial elements to NULL.
 *
 * No parameters passed 
 *
 * @return result: The empty flexarray created
 */
flexarray flexarray_new(){
    int i; 
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    for (i=0; i < result->capacity; i++){
        result->items[i] = NULL;
    }
    return result;
}

/*
 * This function appends a word to the flexarray.
 *
 * @param f: the flexarray we are appending the word to
 * @param str: the word to be appended to the flexarray 
 *
 * Does not return anything
 */
void flexarray_append(flexarray f, char *str){
    if (f->itemcount == f->capacity){
        f->capacity += f->capacity;
        f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    }
    f->items[f->itemcount] = emalloc(sizeof(char) * strlen(str)+1);
    strcpy(f->items[f->itemcount++], str);
}

/*
 * This function frees all memory allocated to the flexarray.
 *
 * @param f: the flexarray we are freeing the memory from
 *
 * Does not return anything
 */
void flexarray_free(flexarray f){
    int i;
    for (i=0; i < f->itemcount; i++){
        free(f->items[i]);
    }
    free(f->items);
    free(f);
}

/*
 * This function performs a linear search on the flexarray to search for a
 * specified word.
 *
 * @param f: the flexarray to be searched
 * @param str: the word that we want to find
 *
 * @return: 1 if the word is found in the flexarray
 * @return: 0 if the word is not found in the flexarray
 */
int is_present(flexarray f, char *str){
    int i;
    for (i=0; i< f->itemcount; i++){
        if (strcmp(str, f->items[i]) == 0){
            return 1;
        }
    }
    return 0;
}

/*
 * This function accepts a function as one of its parameter and uses it to
 * print each word of the flexarray.
 * Note: if container type is flexarray, the function container_print will call
 * this method and pass it a simple string printing function. 
 *
 * @param f: the flexarray to be printed
 * @param g(char *str): the function being used a parameter
 *
 * Does not return anything
 */
void visit(flexarray f, void g(char *str)){
    int i;
    for (i=0; i < f->itemcount; i++){
        g(f->items[i]);
    }
}
    
    
        
