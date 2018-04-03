#ifndef MYLIB_H_
#define MYLIB_H_

#include <stddef.h>
/* 
 * COSC242 Assignment 
 * Authors: Sophie Purdie, Amanda Veldman, Kiri Lenagh-Glue
 */

/* functions to be implemented in mylib.c */
extern void *emalloc(size_t);
extern void *erealloc(void *, size_t);
extern void swap(int *, int *);
extern int getword(char *s, int limit, FILE *stream);

#endif
