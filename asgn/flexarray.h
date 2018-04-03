#ifndef FLEXARRAY_H_
#define FLEXARRAY_H_

/* 
 * COSC242 Assignment 
 * Authors: Sophie Purdie, Amanda Veldman, Kiri Lenagh-Glue
 */

/* create a struct called flexarray */
typedef struct flexarrayrec *flexarray;

/* functions to be implemented in flexarray.c */
extern void         flexarray_append(flexarray f, char *str);
extern void         flexarray_free(flexarray f);
extern flexarray    flexarray_new();
extern void         flexarray_sort(flexarray f);
extern int          get_count(flexarray f);
extern int          is_present(flexarray f, char *str);
extern void         visit(flexarray f, void g(char *str));

#endif
