#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "htable.h"

struct htablerec{
    int capacity;
    int num_keys;
    int *frequencies;
    char **key_array;
};

htable htable_new(int capacity){
    int i;
    htable result = emalloc(sizeof * result);
    result->capacity = capacity;
    result->num_keys = 0;
    result->frequencies = emalloc(result->capacity * sizeof
                                  result->frequencies[0]);
    result->key_array = emalloc(result->capacity * sizeof result->key_array[0]);
    
    for (i = capacity; i < capacity; i++){
        result->frequencies[i] = 0;
        result->key_array[i] = NULL;
    }
    return result;
}

void htable_free(htable h){
    int i;
    for (i = 0; i < h->capacity; i++){
        if (h->key_array[i] != NULL){
            free(h->key_array[i]);
        }
    }
    free(h->key_array);
    free(h->frequencies);
    free(h);
}

static unsigned int htable_word_to_int(char *word){
    unsigned int result = 0;

    while (*word != '\0'){
        result = (*word++ + 31 * result);
    }
    return result;
}

static unsigned int htable_step(htable h, unsigned int i_key){
    return 1 + (i_key % (h->capacity-1));
}

int htable_insert (htable h, char *str){
    unsigned int word, pos, i, opos;
    unsigned int step;

    word = htable_word_to_int(str);
    pos = word % h->capacity;
    step = htable_step(h, word);
    
    if (h->key_array[pos] != NULL && strcmp(h->key_array[pos], str) == 0){
        h->frequencies[pos]++;
        return h->frequencies[pos];
    } else {
        opos = pos;
        i = pos;
        do{
            if (h->key_array[i] == NULL){
                h->key_array[i] = emalloc((strlen(str)+1) * sizeof (char));
                strcpy(h->key_array[i], str);
                h->frequencies[i]++;
                h->num_keys++;
                return 1;
            } else if (strcmp(h->key_array[i], str) == 0){
                h->frequencies[i]++;
                return h->frequencies[i];
            }
            i = (i+step)%h->capacity;
        } while (i != opos);
        return 0;
    }
    return 0;
}


void htable_print(htable h, FILE *stream){
    int i;

    for (i = 0; i < h->capacity; i++){
        if (h->key_array != NULL){
            fprintf(stream, "%10d, %s\n", h->frequencies[i], h->key_array[i]);
        }
    }
}

int htable_search(htable h, char *str){
    unsigned int word, step;
    int cols = 0, pos;

    word = htable_word_to_int(str);
    pos = word % h->capacity;
    step = htable_step(h, word);

    while (h->key_array[pos] != NULL && strcmp(h->key_array[pos], str) != 0 &&
           cols != h->capacity){
        pos = pos + step;
        cols++;
    }
    
    if (cols == h->capacity){
        return 0;
    } else {
        return h->frequencies[pos];
    }
}
        

    
