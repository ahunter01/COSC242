#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include <string.h>
#include "flexarray.h"
#include "htable.h"
#include "rbt.h"
#include "container.h"

/* 
 * COSC242 Assignment 
 * Authors: Sophie Purdie, Amanda Veldman, Kiri Lenagh-Glue
 */


/* 
 * A container is comprised of:
 * type: Denotes whether the container will hold a flexarray or RBT
 * contents: A generic pointer able to be converted to another pointer
 *           type (i.e., flexarray or RBT)
 */
struct containerrec {
    container_t type;
    void *contents;
};

/*
 * This function creates a new container that holds either an empty RBT or
 * empty flexarray, depending on what container type is set.  
 *
 * @param type: Denotes whether the container will hold a flexarray or RBT
 *
 * @return c: the new container created 
 */
container container_new(container_t type){
    container c = emalloc(sizeof *c);
    c->type = type;
    if (c->type == RED_BLACK_TREE){
        c->contents = rbt_new();
    } else {
        c->contents = flexarray_new();
    }
    return c;
}

/*
 * This function adds a new string to an existing container, 
 *
 * @param c: the existing container we are adding the string to
 * @param str: the string being added to the existing container
 *
 * Does not return anything
 */
void container_add(container c, char *str){
    if (c->type == RED_BLACK_TREE){
        c->contents = rbt_insert(c->contents, str);
    } else {
        flexarray_append(c->contents, str);
    }
}

/*
 * This function prints the contents of a container on a single line. 
 *
 * @param c: the container we are printing the contents of
 *
 * Does not return anything 
 */
void container_print(container c){
    if (c->type == RED_BLACK_TREE){
        rbt_preorder(c->contents, print_word);
    } else {
        visit(c->contents, print_word);
    }
}

/*
 * This is a simple string printing function to be passed to the respective
 * rbt and flexarray traverse/visit functions in container_print.
 *
 * @param word: the string to be printed
 *
 * Does not return anything
 */
void print_word(char *word){
    printf("%s ", word);
}

/*
 * This function performs a search to find a specified word in a container.
 *
 * @param c: the container to be searched
 * @param str: the specified string to search for 
 *
 * @return: 1 if the word is found
 * @return: 0 if the word is not found
 */
int container_search(container c, char *str){
    if (c->type == RED_BLACK_TREE){
        return rbt_search(c->contents, str);
    } else {
        return is_present(c->contents, str);
    }
}

/*
 * This function frees all memory allocated to the data structure that is
 * held by the container, setting the container to null.
 * Note: the memory allocated to the container itself is freed in the class
 * htable.c.
 *
 * @param c: the container that's contents we are freeing the memory from
 *
 * @return c: a null (empty) container 
 */
container container_free(container c){
    if (c->type == RED_BLACK_TREE){
        rbt_free(c->contents);
    } else {
        flexarray_free(c->contents);
    }
    c = NULL;
    return c;
}


