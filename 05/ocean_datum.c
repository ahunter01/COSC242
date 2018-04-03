#include <stdio.h>
#include <stdlib.h>

#define OCEAN_MAX 41981

struct ocean_datum {
    int x;
    int y;
    double conc;
};

void print_ocean_datum(struct ocean_datum *o){
    printf("%d %d %.4f\n", o->x, o->y, o->conc);
}

int read_ocean_datum(struct ocean_datum *o){
    return 3 == scanf("%d %d %lg", &o->x, &o->y, &o->conc);
}

int main (void){
    struct ocean_datum ocean_data[OCEAN_MAX];
    int num_items;
    int i, p, key, smallest;
    struct ocean_datum temp;

    num_items = 0;
    while(num_items < OCEAN_MAX && read_ocean_datum(&ocean_data[num_items])){
        num_items++;
    }

    /* sort data here */
    for (p = 0; p < num_items; p++){
        smallest = p;

        for (key = p+1; key < num_items; key++){
            if ((ocean_data[key].conc) < (ocean_data[smallest].conc)){
                smallest = key;
            }
        }
        temp = ocean_data[smallest];
        ocean_data[smallest] = ocean_data[p];
        ocean_data[p] = temp;
    }

    for(i = 0; i < num_items; i++){
        print_ocean_datum(&ocean_data[i]);
    }

    return EXIT_SUCCESS;
}
