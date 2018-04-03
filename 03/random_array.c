#include <stdio.h>
#include <stdlib.h>

void display_repeats(int *a, int n){
    int i=0,j = 0;
    for (i = 0; i < n; i++){
        for (j= n-1; j >i; j--){
            if (a[i] == a[j]){
                printf("%d", a[i]);
            }
        }
    }
}

int main (void){
    int array_size = 0;
    int *my_dynamic_array;
    int i = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &array_size);

    my_dynamic_array = malloc(array_size * sizeof my_dynamic_array[0]);
    if (NULL == my_dynamic_array){
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    for (i = 0; i < array_size; i++){
        my_dynamic_array[i] = rand() % array_size;
    }
    printf("What's in the array:\n");
    for (i = 0; i < array_size; i++){
        printf("%d", my_dynamic_array[i]);
    }
    printf("\n");
    printf("Repeated values: ");
    display_repeats(my_dynamic_array, array_size);
    printf("\n");

    free(my_dynamic_array);

    return EXIT_SUCCESS;
}
