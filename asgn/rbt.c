#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "rbt.h"
#include <string.h>

/* 
 * COSC242 Assignment 
 * Authors: Sophie Purdie, Amanda Veldman, Kiri Lenagh-Glue
 */

/* If the node is black return 1, return 0 if the node is red */
#define IS_BLACK(x) ((NULL == (x)) || (BLACK == (x)->colour))
/* If the node is red return 1, return 0 if the node is black */
#define IS_RED(x) ((NULL != (x)) && (RED == (x)->colour))

/* 
 * A node in the red-black tree is comprised of:
 * key: The string stored in the node
 * colour: The colour of the node (red or black)
 * left: The pointer to left subtree
 * right: The pointer to right subtree
 */
struct rbt_node {
    char *key;
    rbt_colour colour;
    rbt left;
    rbt right;
};

/*
 * This function creates a new red-black tree.
 *
 * No parameters passed
 *
 * @return NULL: A newly initialised RBT
 */
rbt rbt_new(){
    return NULL;
}

/*
 * This function rotates the node to right.
 *
 * @param r: The node in the tree that needs to be rotated
 *
 * @return r: The arranged RBT
 */
static rbt right_rotate(rbt r){
    rbt temp = r;
    r = r->left;
    temp->left = r->right;
    r->right = temp;
    return r;
}

/*
 * This function rotates the node to the left.
 *
 * @param r: The node in the tree that needs to be rotated
 * 
 * @return r: The arranged RBT
 */
static rbt left_rotate(rbt r){
    rbt temp = r;
    r = r->right;
    temp->right = r->left;
    r->left = temp;
    return r;
}

/*
 * This function fixes the red-black tree structure so that it satisfies
 * the parameters of a RBT.
 * The parameters are that no red nodes are together and that the height
 * of the black nodes is consistent.
 *
 * @param r: The RBT to be fixed
 *
 * @return r: The fixed RBT
 */
static rbt rbt_fix(rbt r){
    /* red = left child (a) & a.left (c) (LINE)*/
    if(IS_RED(r->left) && IS_RED(r->left->left)){
        if (IS_RED(r->right)){
            r->colour = RED;
            r->left->colour = BLACK;
            r->right->colour = BLACK;
        } else {
            /*RIGHT ROTATE: root r */
            r = right_rotate(r);
            
            r->colour = BLACK;
            r->right->colour = RED; /*old root r, now new root a's right child*/
        }

        /* red = left child (a) & a.right (d) (TRIANGLE) */
    } else if (IS_RED(r->left) && IS_RED(r->left->right)){
        if (IS_RED(r->right)){
            r->colour = RED;
            r->left->colour = BLACK;
            r->right->colour = BLACK;
        } else {
            /*LEFT ROTATE: left child a; RIGHT ROTATE: root r */
            r->left = left_rotate(r->left);
            r = right_rotate(r);
            
            r->colour = BLACK;
            r->right->colour = RED; /*old root r, now new root d's right child*/
        }

        /* red = right child (b) &  b.left (e) (TRIANGLE) */  
    } else if (IS_RED(r->right) && IS_RED(r->right->left)){
        if (IS_RED(r->left)){
            r->colour = RED;
            r->left->colour = BLACK;
            r->right->colour = BLACK;
        } else {
            /*RIGHT ROTATE: right child b; LEFT ROTATE: root r*/
            r->right = right_rotate(r->right);
            r = left_rotate(r);

            r->colour = BLACK;
            r->left->colour = RED;/*old root r, now new root e's left child*/
        }

        /* red = right child (b) & b.right (f) (LINE) */
    } else if (IS_RED(r->right) && IS_RED(r->right->right)){
        if (IS_RED(r->left)){
            r->colour = RED;
            r->left->colour = BLACK;
            r->right->colour = BLACK;
        } else { 
            /*LEFT ROTATE: root r */
            r = left_rotate(r);
            r->colour = BLACK;
            r->left->colour = RED;/*old root r, now new root b's left child*/
        }
    }
    return r;
}

/*
 * This function inserts a string into the red-black tree. 
 *
 * @param r: The RBT that will have a string inserted into it
 * @param str: The string that will be inserted into the RBT
 *
 * @return r: The new RBT with the newly inserted string
 */
rbt rbt_insert(rbt r, char *str){
    if (r == NULL){
        r = emalloc(sizeof *r);
        r->key = emalloc(strlen(str)+ 1);
        r->colour = RED;
        r->left = NULL;
        r->right = NULL;
        strcpy(r->key, str);
    } else if (strcmp(r->key, str) < 0){
        r->right = rbt_insert(r->right, str);
    } else if (strcmp(r->key, str) >= 0){
        r->left = rbt_insert(r->left, str);
    }
    r = rbt_fix(r);
    return r;
}


/*
 * This function recursively traverses the red-black tree preorder.
 * (root, left, right)
 *
 * @param r: The RBT to traverse
 * @param f: An external function passed to this function on calling it
 *
 * @return: This is the exit case
 */
void rbt_preorder(rbt r, void f(char *str)){ /* Had to alter to not include colour */
    if (NULL == r){
        return;
    }
    f(r->key);
    rbt_preorder(r->left, f);
    rbt_preorder(r->right, f);
}


/*
 * This function recursively searches the red-black tree for a specified
 * string.
 *
 * @param r: The RBT to be searched
 * @param str: The string to be searched for in the RBT
 *
 * @return: 1 if the string is in the RBT, otherwise 0
 */
int rbt_search(rbt r, char *str){
    if (r->key == NULL){
        return 0;
    }
    if (strcmp(r->key, str) == 0){
        return 1 ;
    } else if (strcmp(r->key, str) < 0){
        return rbt_search(r->right, str);
    } else {
        return rbt_search(r->left, str);
    }
}


/*
 * This function frees the memory allocated for all the components of the
 * red-black tree struct.
 * 
 * @param r: The RBT that will be freed
 *
 * @return r: The pointer to the freed RBT
 */
rbt rbt_free(rbt r){
    if (r == NULL){
        return r;
    }
    rbt_free(r->right);
    rbt_free(r->left);
    free(r->key);
    free(r);
    return r;
}
