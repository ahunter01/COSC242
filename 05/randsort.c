#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LEN 80
#define ARRAY_LEN 10000

void *emalloc(size_t s){
    void *result = malloc(s);
    if (NULL == result){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void selection_sort(char *a[], int n){
    int p, key;
    char *temp;
    int smallest;

    for (p = 0; p < n-1; p++){
        smallest = p;
        
        for (key = p+1; key < n; key++){
            if (strcmp(a[smallest], a[key]) >= 0){
                smallest = key;
            }
        }
        temp = a[smallest];
        a[smallest] = a[p];
        a[p] = temp;
    }
}
            

int main(void){
    char word[STRING_LEN];
    char *wordlist [ARRAY_LEN];
    int num_words, i;

    num_words = 0;
    while(num_words < ARRAY_LEN && 1 == scanf("%79s", word)){
        wordlist[num_words] = emalloc((strlen(word)+1)* sizeof wordlist[0][0]);
        strcpy(wordlist[num_words], word);
        num_words++;
    }
    printf("%d\n", num_words);
    selection_sort(wordlist, num_words);

    for (i = 0; i < num_words; i++){
        printf("%s\n", wordlist[i]);
        free(wordlist[i]);
    }

    return EXIT_SUCCESS;
}
