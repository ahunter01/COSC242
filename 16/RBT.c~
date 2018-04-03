#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "RBT.h"

#define IS_BLACK(x) ((NULL == (x)) || (BLACK == (x)->colour))
#define IS_RED(x) ((NULL != (x)) && (RED == (x)->colour))

struct rbt_node{
    char *key;
    rbt_colour colour;
    rbt left;
    rbt right;
};

static rbt right_rotate(rbt r){
    rbt temp = r;
    r = r->left;
    temp->left = r->right;
    r->right = temp;
    return r;
}

static rbt left_rotate(rbt r){
    rbt temp = r;
    r = r->right;
    temp->right = r->left;
    r->left = temp;
    return r;
}

static rbt rbt_fix(rbt r){
    if (IS_RED(r->left) && IS_RED(r->left->left)){
        if (IS_RED(r->right)){
            r->colour = RED;
            r->left->colour = BLACK;
            r->right->colour = BLACK;
        } else {
            r = right_rotate(r);
            
            r->colour = BLACK;
            r->right->colour = RED;
        }
    } else if (IS_RED(r->left) && IS_RED(r->left->right)){
        if (IS_RED(r->right)){
            r->colour = RED;
            r->left->colour = BLACK;
            r->right->colour = BLACK;
        } else {
            r->left = left_rotate(r->left);
            r = right_rotate(r);
            
            r->colour = BLACK;
            r->right->colour = RED;
        }
    } else if (IS_RED(r->right) && IS_RED(r->right->left)){
        if (IS_RED(r->left)){
            r->colour = RED;
            r->left->colour = BLACK;
            r->right->colour = BLACK;
        } else {
            r->right = right_rotate(r->right);
            r = left_rotate(r);
            
            r->colour = BLACK;
            r->left->colour = RED;
        }
    } else if (IS_RED(r->right) && IS_RED(r->right->right)){
        if (IS_RED(r->left)){
            r->colour = RED;
            r->left->colour = BLACK;
            r->right->colour = BLACK;
        } else {
            r = left_rotate(r);
            
            r->colour = BLACK;
            r->left->colour = RED;
        }
    }
    return r;
}           

rbt rbt_delete(rbt r, char *str){
    if (r == NULL || rbt_search(r, str) == 0){
        return r;
    } else if (strcmp(str, r->key) < 0){
        r->left = rbt_delete(r->left, str);
    } else if (strcmp(str, r->key) > 0){
        r->right = rbt_delete(r->right, str);
    } else {
        if (r->left == NULL && r->right == NULL){
            free(r->key);
            free(r);
            r = NULL;
        } else if (r->left == NULL){
            free(r->key);
            free(r);
            r = r->right;;
        } else if (r->right == NULL){
            free(r->key);
            free(r);
            r = r->left;
        } else {
            rbt copy = r->right;
            char *temp;
            while(copy->left != NULL){
                copy = copy->left;
            }
            temp = r->key;
            r->key = copy->key;
            copy->key = temp;
            r->right = rbt_delete(r->right, temp);
        }
    }
    return r;
}

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

void rbt_inorder(rbt r, void f(char *str)){
    if (r == NULL){
        return;
    }
    rbt_inorder(r->left, f);
    f(r->key);
    rbt_inorder(r->right, f);
}

rbt rbt_insert(rbt r, char *key){
    if (r == NULL){
        r = emalloc(sizeof *r);
        r->key = emalloc(strlen(key)+1);
        r->colour = RED;
        r->right = NULL;
        r->left = NULL;
        strcpy(r->key, key);
    } else if (strcmp(r->key, key) < 0){
        r->right = rbt_insert(r->right, key);
    } else if (strcmp(r->key, key) > 0){
        r->left = rbt_insert(r->left, key);
    }
    r = rbt_fix(r);
    return r;
}

rbt rbt_new(){
    return NULL;
}

void rbt_preorder(rbt r, void f(char *str)){
    if (r == NULL){
        return;
    }
    f(r->key);
    rbt_preorder(r->left, f);
    rbt_preorder(r->right, f);
}

int rbt_search(rbt r, char *key){
    if (r->key == NULL){
        return 0;
    }
    if (strcmp(r->key, key) == 0){
        return 1;
    } else if (strcmp(r->key, key) < 0){
        return rbt_search(r->right, key);
    } else {
        return rbt_search(r->left, key);
    }
    return 0;
} 

