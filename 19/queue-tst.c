#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "queue.h"

int main (void){

    queue q = queue_new();

    enqueue(q, 2);
    queue_print(q);
    printf("\n");
    enqueue(q, 4);
    queue_print(q);
    printf("\n");
    enqueue(q, 6);
    queue_print(q);
    printf("\n");
    enqueue(q, 8);
    queue_print(q);
    printf("\n");
    enqueue(q, 9);

    queue_print(q);
    printf("\n");

    free(q);

    return EXIT_SUCCESS;

}
