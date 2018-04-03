#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ARRAY_SIZE determines the max number of items we can search through */
#define ARRAY_SIZE 10000

/** searches an array of ints using binary search.
    @param int a* takes an array.
    @param start is the first position of the array to be searched.
    @param end is the last position of the array to be searched.
    @param find is the item we are trying to search for in the array.
*/

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

int binary_search(int *a, int find, int start, int end){
    int mid = (end+start)/2;
    if (a[mid] == find){
        return 1;
    }
    else if (end == start){
        return 0;
    }
    else if (a[mid] > find){
        return binary_search(a, find, start, mid);
    }
    return binary_search(a, find, mid+1, end);
}

/** main method takes no parameters and populates an array with the input
    from a scan and then calls selecion_sort on the array.
    times selection_sort and prints this out to stderr.
    @return 0 for unsuccessful and 1 for successful.
*/
int main(int argc, char **argv){
    FILE *infile;
    int num_items, query;
    int my_array[ARRAY_SIZE];
    int i = 0;
    if(argc < 2){
        /* Complain */
    }

    if(NULL == (infile = fopen(argv[1], "r"))){
        fprintf(stderr, "%s: can't find file %s\n", argv[0], argv[1]);
        return EXIT_FAILURE;
    }

    num_items = 0;
    while(num_items < ARRAY_SIZE &&
          1 == fscanf(infile, "%d", &my_array[num_items])){
        num_items++;
    }

    fclose(infile);

    insertion_sort(my_array, num_items);

    for(i = 0; i < num_items; i++){
        printf("%d\n", my_array[i]);
    }
    
    /* print out a + or - here */
    while(1 == scanf("%d", &query)){
        printf("%s\n",
               (binary_search(my_array, query, 0, num_items) == 1) ? "+" : "-");
    }
    
    return EXIT_SUCCESS;
}
