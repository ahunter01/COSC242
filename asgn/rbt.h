#ifndef RBT_H_
#define RBT_H_

/* 
 * COSC242 Assignment 
 * Authors: Sophie Purdie, Amanda Veldman, Kiri Lenagh-Glue
 */

/* Defines red-black tree as a struct rbt_node pointer */
typedef struct rbt_node *rbt;

/* An enumerated type used to determine the colours of the nodes */
typedef enum { RED, BLACK } rbt_colour;

/* Functions that are implemented in rbt.c */
extern rbt    rbt_new();
extern rbt    rbt_insert(rbt r, char *str);
extern void   rbt_preorder(rbt r, void f(char *str));
extern int    rbt_search(rbt r, char *str);
extern rbt    rbt_free(rbt r);

#endif
