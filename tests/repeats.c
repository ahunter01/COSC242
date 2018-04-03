#include <stdio.h>
#include <stdlib.h>

void display_repeats(int *a, int n){
    int *array;
    int i;
    array = malloc(n * sizeof array[0]);
    if (NULL == array){
        fprintf("memory allocation failed!\n");
        return;
    }
    for (i = 0; i < n; i++){
        array[i] = 0;
    }
    for (i = 0; i < n; i++){
        array[a[i]]++;
    }
    for (i = 0; i < n; i++){
        if (array[i] > 1){
            printf("%d occurs %d times", i, array[i]);
        }
    }
    free(array);
    return;
}

