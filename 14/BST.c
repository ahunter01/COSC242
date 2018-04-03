#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "BST.h"

struct bst_node{
    char *key;
    bst left;
    bst right;
};

bst bst_delete(bst b, char *str){
    if (b == NULL || bst_search(b, str) == 0){
        return b;
    } else if (strcmp(str, b->key) < 0){
        b->left = bst_delete(b->left, str);
    } else if (strcmp(str, b->key) > 0){
        b->right = bst_delete(b->right, str);
    } else {
        if (b->left == NULL && b->right == NULL){
            free(b->key);
            free(b);
            b = NULL;
        } else if (b->left == NULL){
            free(b->key);
            free(b);
            b = b->right;;
        } else if (b->right == NULL){
            free(b->key);
            free(b);
            b = b->left;
        } else {
            bst copy = b->right;
            char *temp;
            while(copy->left != NULL){
                copy = copy->left;
            }
            temp = b->key;
            b->key = copy->key;
            copy->key = temp;
            b->right = bst_delete(b->right, temp);
        }
    }
    return b;
}

bst bst_free(bst b){
    if (b == NULL){
        return b;
    }
    bst_free(b->right);
    bst_free(b->left);
    free(b->key);
    free(b);
    return b;
}

void bst_inorder(bst b, void f(char *str)){
    if (b == NULL){
        return;
    }
    bst_inorder(b->left, f);
    f(b->key);
    bst_inorder(b->right, f);
}

bst bst_insert(bst b, char *key){
    if (b == NULL){
        b = emalloc(sizeof *b);
        b->key = emalloc(strlen(key)+1);
        strcpy(b->key, key);
    } else if (strcmp(b->key, key) < 0){
        b->right = bst_insert(b->right, key);
    } else if (strcmp(b->key, key) > 0){
        b->left = bst_insert(b->left, key);
    }
    return b;
}

bst bst_new(){
    return NULL;
}

void bst_preorder(bst b, void f(char *str)){
    if (b == NULL){
        return;
    }
    f(b->key);
    bst_preorder(b->left, f);
    bst_preorder(b->right, f);
}

int bst_search(bst b, char *key){
    if (b->key == NULL){
        return 0;
    }
    if (strcmp(b->key, key) == 0){
        return 1;
    } else if (strcmp(b->key, key) < 0){
        return bst_search(b->right, key);
    } else {
        return bst_search(b->left, key);
    }
    return 0;
} 

