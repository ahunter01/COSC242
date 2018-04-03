/* Lab 21 COSC242
   Amanda Veldman
   Graph test file/main method
*/
#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "graph.h"

/*main method
  takes no params
  @return exit success or exit failure
*/
int main(void) {
    graph g;
    int size, u, v;

    /*sets size of the graph based on the first number in input */
    if (1 == scanf("%d", &size)){
        g = graph_new(size);
    } else {
        exit(EXIT_FAILURE);
    }
    
    while (2 == scanf("%d%d", &u, &v)){
        graph_add_2edges(g, u, v);
    }
    graph_bfs(g, 1);
    
    graph_print(g);
    graph_free(g);
    return EXIT_SUCCESS;
}
