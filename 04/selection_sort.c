#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ARRAY_MAX determines the max number of items we can sort */
#define ARRAY_MAX 30000

/** sorts an array using selection sort.
    @param int a* takes an array.
    @param n is the length of the array.
*/
void selection_sort(int *a, int n){
    int p=0, key=0, smallest=0, temp=0;

    /* keeps place in the array to be sorted */
    for (p = 0; p < n-1; p++){
        smallest = p;

        /* checks smallest isnt greater than the next element in the array */
        for (key=p+1; key < n; key++){
            if (a[smallest] > a[key]){
                smallest = key;
            }
        }
        /* swaps elements as necessary */
        temp = a[smallest];
        a[smallest] = a[p];
        a[p] = temp;
    }
}

/** main method takes no parameters and populates an array with the input
    from a scan and then calls selecion_sort on the array.
    times selection_sort and prints this out to stderr.
    @return 0 for unsuccessful and 1 for successful.
*/
int main(void){
    int my_array[ARRAY_MAX];
    int i, count = 0;
    clock_t start, end;

    /* populates array with input from scan */
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])){
        count ++;
    }
    start = clock();
    selection_sort(my_array, count);
    end = clock();

    /* prints out the sorted array */
    for (i = 0; i < count; i++){
        printf("%d\n", my_array[i]);
    }
    /* prints out the time selection sort took to stderr */
    fprintf(stderr, "%d %f\n", count, (end-start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
