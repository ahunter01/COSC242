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

int binary_search(int *a, int start, int end, int find){
    int mid;

    mid = a[end/2];

    if (mid == find){
        return 1;
    } else if (mid < find){
        binary_search(a, 0, end/2, find);
    } else if (mid > f){
        binary_search(a, (end/2)+1, end, find);
    }
    return 0;
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

    /* print out a + or - here */
    while(1 == scanf("%d", &query))
        printf("%s\n", binary_search(my_array, 0, num_items, query) ? "+" : "-");
    }
    
    return EXIT_SUCCESS;
}
