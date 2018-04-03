#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include <assert.h>
#include <ctype.h>


/* 
 * COSC242 Assignment 
 * Authors: Sophie Purdie, Amanda Veldman, Kiri Lenagh-Glue
 */

/*
 * This function reads in words from a file, word by word.
 * 
 * @param s: the word read in from the file
 * @param limit: keeps track of the character count for a word
 * @param stream: the file to get words from.
 * 
 * @return: an integer
 */
int getword(char *s, int limit, FILE *stream){
    int c;
    char *w = s;
    assert(limit > 0 && s != NULL && stream != NULL);

    /* skip to the start of the word */
    while (!isalnum(c = getc(stream)) && EOF != c)
        ;
    if (EOF == c){
        return EOF;
    } else if (--limit > 0) { /* reduce by 1 to allow for the \0 */
        *w++ = tolower(c);
    }
    while (--limit > 0){
        if (isalnum(c = getc(stream))){
            *w++ = tolower(c);
        } else if ('\'' == c){
            limit++;
        } else {
            break;
        }
    }
    *w = '\0';
    return w - s;
}


/*
 * This function allocates memory and handles errors associated with memory
 * allocation. 
 * 
 * @param s: the size of the memory to be allocated
 */
void *emalloc(size_t s){
    void *result = malloc(s);
    if (NULL == result){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

/*
 * This function extends existing memory allocation to create extra memory
 * when needed.
 *
 * @param p: a pointer of generic type
 * @param s: the size of the extra memory required
 */
void *erealloc(void *p, size_t s){
    void *result = realloc(p, s);
    if (NULL == result && s != 0){
        fprintf(stderr, "memory allocation failed!\n");
        exit(EXIT_SUCCESS);
    }
    return result;
}

