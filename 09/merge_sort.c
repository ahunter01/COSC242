#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ARRAY_MAX determines the max number of items you can sort */
#define ARRAY_MAX 2000000

void merge(int *a, int *w, int len){
    int p=0, i=0, j=(len/2);

    while(i < (len/2) && j < len){
        if (a[i] < a[j]){
            *(w+p) = *(a+i);
            i++;
        } else {
            *(w+p) = *(a+j);
            j++;
        }
        p++;
    }

    while (i < (len/2)){
        w[p] = a[i];
        i++;
        p++;
    }

    while (j < len){
        w[p] = a[j];
        j++;
        p++;
    }
}

void merge_sort(int *a, int *w, int n){
    int i;

    /* stopping condition */
    if (n < 2){
        return;
    }
    merge_sort(a,w,(n/2));
    merge_sort(a+(n/2),w,n-(n/2));

    merge(a,w,n);

    for(i = 0; i < n; i++){
        *(a+i) = *(w+i);
    }
}

/** main method takes no parameters and populates an array with the input
    from a scan and then calls inserton_sort on the array.
    times insertion_sort and prints this out to stderr.
    @return 0 for unsuccessful and 1 for successful.
*/
int main(void){
    int *my_array;
    int *workspace;
    int i, count = 0;
    clock_t start, end;

    my_array = malloc(ARRAY_MAX*sizeof my_array[0]);
    
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])){
        count ++;
    } 

    workspace = malloc(count*sizeof workspace[0]);
    if (NULL == workspace){
        fprintf(stderr, "Memory allocatioon failed!\n");
        return EXIT_FAILURE;
    }

    start = clock();
    merge_sort(my_array, workspace, count);
    end = clock();
    
    for (i = 0; i < count; i++){
        printf("%d\n", my_array[i]);
    }

    fprintf(stderr, "%d %f\n", count, (end-start)/(double)CLOCKS_PER_SEC);

    free(workspace);
    free(my_array);

    return EXIT_SUCCESS;
}
