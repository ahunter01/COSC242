#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "htable.h"
#include "container.h"

/* 
 * COSC242 Assignment 
 * Authors: Sophie Purdie, Amanda Veldman, Kiri Lenagh-Glue
 */


/* 
 * The htable is comprised of:
 * capacity: The size of the htable
 * containers: A pointer which will contain the specified data structure 
 *             (flexarray or RBT)
 * type: Denotes whether the container will hold a flexarray or RBT
 */
struct htablerec {
    int capacity;
    container *containers;
    container_t type;
};

/*
 * This function converts a string to an integer.
 * Using an unsigned int to prevent a negative result.
 * 
 * @param word: The string being converted
 * 
 * @return result: The int that was made by converting
 */
static unsigned int htable_word_to_int(char *word){
    unsigned int result = 0;
    while (*word != '\0'){
        result = (*word++ + 31 * result);
    }
    return result;
}

/*
 * This function creates a new htable, allocating the memory it
 * needs.
 * The default value of each container is set as NULL.
 * 
 * @param capacity: The size of the htable
 * @param type: Denotes whether the container will hold a flexarray or RBT
 * 
 * @return result: The htable created
 */
htable htable_new(int capacity, container_t type){
    int i;
    htable result = emalloc(sizeof *result);
    result->capacity = capacity;
    result->type = type;
    result->containers = emalloc(result->capacity * sizeof result->containers);
    
    for (i=0;i<capacity;i++){
        result->containers[i] = NULL;
    }
    return result;
}

/*
 * This function inserts a string into the htable.
 * 
 * @param h: The htable we are inserting into
 * @param str: The string being inserted
 *
 * @return: 1 if the string is successfully inserted into the htable
 */
int htable_insert(htable h, char *str){
    unsigned int i = htable_word_to_int(str) % h->capacity; 

    if (h->containers[i] == NULL){
        h->containers[i] = container_new(h->type); 
    }
    container_add(h->containers[i], str);
    return 1;
}

/*
 * This function searches the containers in the htable for a 
 * specific string.
 * 
 * @param h: The htable to be searched
 * @param str: The string that we want to find
 * 
 * @return: 0 if the string is not in the htable
 */
int htable_search(htable h, char *str){
    int i = htable_word_to_int(str) % h->capacity;
    
    if (h->containers[i] != NULL){
        return container_search(h->containers[i], str);
    }
    return 0;
}

/*
 * This function prints out all of the containers in the htable.
 * 
 * @param h: The htable being printed
 *
 * Does not return aything 
 */
void htable_print(htable h){
    int i = 0;
    for (i=0; i < h->capacity; i++){
        if (h->containers[i] != NULL){
            printf("%d ", i);
            container_print(h->containers[i]);
            printf("\n");
        }
    }
}

/*
 * This function frees all the memory allocated to the htable
 *
 * @param h: The htable we are freeing the memory from 
 *
 * Does not return anything
 */
void htable_free(htable h){
    int i;
    for (i=0;i< h->capacity; i++){
        if (h->containers[i] != NULL){
            container_free(h->containers[i]);
            free(h->containers[i]);
        }
    }
    free(h->containers);
    free(h);
}
