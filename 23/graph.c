/* Lab 23 COSC242
   Amanda Veldman
   graph implementation
*/

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "mylib.h"
#include "queue.h"

/* struct to create a graph made of verticies */
struct graphrec{
    int capacity;
    struct vertexrec *verticies;
    int **edges;
};

/*struct to make verticies */
struct vertexrec{
    int predecessor;
    int distance;
    state_t state;
    int finish;
};

/* makes a new graph and allocated memory
   @param v is the capacity of the graph
   @return an empty graph
*/
graph graph_new(int v){
    int i, j;
    graph result = emalloc(sizeof * result);
    result->capacity = v;
    result->verticies = emalloc(result->capacity * sizeof result->verticies[0]);
    
    /*emalloc the number of rows in edges */
    result->edges = emalloc(result->capacity * sizeof result->edges[0]);
    
    /* emalloc the actual rows in edges */
    for (i = 0; i < result->capacity; i++){
        result->edges[i] = emalloc(result->capacity *
                                   sizeof result->edges[i][0]);
        for (j = 0; j < result->capacity; j++){
            result->edges[i][j] = 0;
        }
    }
    for (i = 0; i < result->capacity; i++){
        result->verticies[i].state = UNVISITED;
    }
    return result;
}

/*frees memory allocated to graph g
  @param graph g
  @return void
*/
void graph_free(graph g){
    int i;
    for (i = 0; i < g->capacity; i++){
        free(g->edges[i]);
    }
    free(g->edges);
    free(g->verticies);
    free(g);
    return;
}

/*adds a unidirectional edge between verticies v and u
  @param graph g, vertex v and vertex u
  @return graph
*/
graph graph_add_edge(graph g, int u, int v){
    g->edges[u][v] = 1;
    return g;
}

/*adds bi-directional edges between verticies v and u
  @param graph g, vertex v and vertex u
  @return graph
*/
graph graph_add_2edges(graph g, int u, int v){
    g->edges[v][u] = 1;
    g->edges[u][v] = 1;
    return g;
}

/*prints out an adjacancy list and vertex info
  @param graph
*/
void graph_print(graph g){
    /* print the verticies and edges */
    int i, e, count;
    printf("adjacency list:\n");
    for (i = 0; i < g->capacity; i++){
        printf("%d | ", i);
        count = 0;
        for (e = 0; e < g->capacity; e++){
            if (g->edges[i][e] == 1){
                if (count >0){
                    printf(", %d", e);
                    count++;
                } else {
                    printf("%d", e);
                    count++;
                }
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("vertex distance pred finish\n");
    for (i = 0; i < g->capacity; i++){
        printf("%d\t%d\t%d\t%d\n", i, g->verticies[i].distance,
               g->verticies[i].predecessor, g->verticies[i].finish);
    }
}

/* performs a bredth first graph on the graph paramater
   @param graph
   @return the graph
*/
graph graph_bfs(graph g, int source){
    int i, u, v;
    queue q = queue_new(g->capacity);

    for (i = 0; i < g->capacity; i++){
        g->verticies[i].distance = -1;
        g->verticies[i].predecessor = -1;
    }
    g->verticies[source].state = VISITED_SELF;
    g->verticies[source].distance = 0;
    enqueue(q, source);
    while (queue_size(q) != 0){
        u = dequeue(q);
        for (v = 0; v < g->capacity; v++){
            if (g->edges[v][u] == 1 && g->verticies[v].state == UNVISITED){
                g->verticies[v].state = VISITED_DESCENDANTS;
                g->verticies[v].distance = 1 + g->verticies[u].distance;
                g->verticies[v].predecessor = u;
                enqueue(q, v);
            }
        
        }
        g->verticies[u].state = VISITED_DESCENDANTS;
    }
    queue_free(q);
    return g;
}

static int step;

/*performs a depth first search on the graph parameter
  @param graph
  @return the graph
*/
graph graph_dfs(graph g){
    int i, v;
    for (i = 0; i < g->capacity; i++){
        g->verticies[i].state = UNVISITED;
        g->verticies[i].predecessor = -1;
    }
    step = 0;
    for (v = 0; v < g->capacity; v++){
        if (g->verticies[v].state == UNVISITED){
            visit(g, v);
        }
    }
    return g;
}

/*recursively visit the vertexes from the graph that are on the stack
  @param graph to be searched and vertex to be visited
*/
void visit(graph g, int v){
    int u;
    g->verticies[v].state = VISITED_SELF;
    step++;
    g->verticies[v].distance = step;
    for (u = 0; u < g->capacity; u++){
        if (g->edges[v][u] == 1 && g->verticies[u].state == UNVISITED){
            g->verticies[u].predecessor = v;
            visit(g, u);
        }
    }
    step++;
    g->verticies[v].state = VISITED_DESCENDANTS;
    g->verticies[v].finish = step;
}
