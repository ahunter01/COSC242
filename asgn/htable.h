#ifndef HTABLE_H
#define HTABLE_H

#include <stdio.h>
#include "container.h"

/*
 * COSC242 Assignment
 * Authors: Sophie Purdie, Amanda Veldman, Kiri Lenagh-Glue
 */

/* Defines htable as a struct htablerec pointer */
typedef struct htablerec *htable;

/* Functions that are implemented in htable.c */
extern void    htable_free(htable h);
extern int     htable_insert(htable h, char *str);
extern htable  htable_new(int capacity, container_t type);
extern void    htable_print(htable h);
extern int     htable_search(htable h, char *str);

#endif
