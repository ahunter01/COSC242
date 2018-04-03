#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

void insertion_sort(int *a, int n){
    int p=0, key=0, left=0;

    /* keeps place in the array */
    for (p = 1; p < n; p++){
        key = a[p];
        left = p-1;

        /* checks comparison and swaps elements as necessary */
        while (left>=0 && a[left] > key){
            a[left+1] = a[left];
            left --;
        }  
        a[left+1]=key;
    }      
}

static void array_print(int *a, int n){
    int i;

    for (i = 0; i < n; i++){
        printf("%d\n", a[i]);
    }
}

int main (void){
    int capacity = 2;
    int itemcount = 0;
    int item;
    int *my_array = emalloc(capacity * sizeof my_array[0]);

    while (1 == scanf("%d", &item)){
        if (itemcount == capacity){
            capacity += capacity;
            my_array = erealloc(my_array, capacity * sizeof my_array[0]);
        }
        my_array[itemcount++] = item;
    }

    insertion_sort(my_array, itemcount);
    array_print(my_array, itemcount);
    free(my_array);

    return EXIT_SUCCESS;
}