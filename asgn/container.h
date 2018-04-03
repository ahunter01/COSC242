#ifndef CONTAINER_H_
#define CONTAINER_H_
#include <stdio.h>

/* 
 * COSC242 Assignment 
 * Authors: Sophie Purdie, Amanda Veldman, Kiri Lenagh-Glue
 */

/* Defines container as a struct containerrec pointer */
typedef struct containerrec *container;

/* An enumerated type used to determine the type of data structure
 * held by a container.
 */
typedef enum container_e {FLEX_ARRAY, RED_BLACK_TREE} container_t;

/* Functions that are implemented in container.c */
extern container  container_new(container_t type);
extern void       container_add(container c, char *word);
extern void       container_print(container c);
extern void       print_word(char *word);
extern int        container_search(container c, char *word);
extern container  container_free(container c);

#endif
