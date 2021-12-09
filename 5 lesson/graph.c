#include <stdio.h>
#include "graph.h"
#include "err.h"
#include <stdbool.h>

struct GraphRecord
{
      int adj[max][max];
      int visited[max];
      int nodes;
};

Graph CreateGraph(int NodesCount)
{
      Graph G;

      G = malloc(sizeof(struct GraphRecord));
      if(G == NULL) Error( "Out of space!!!" );

      G->nodes = NodesCount;

      return G;
}


void DisposeGraph(Graph G)
{
     free(G);
}


/* a function to build adjacency matrix of a graph */
void buildadjm(Graph G){
     int i, j;

     for(i = 0; i < G->nodes; i++){
         for(j = 0; j < G->nodes; j++){
             printf("enter 1 if there is an edge from %d to %d, otherwise enter 0 \n", i,j);
             scanf("%d",&(G->adj[i][j]));
         }
     }
}

void printadjm(Graph G)
{
     int i,j;
     for(i=0;i<G->nodes;i++)
     {
         for(j=0;j<G->nodes;j++)
          printf(" %d",G->adj[i][j]);
         putchar('\n');
     }
}

void ClearVisited(Graph G)
{
     int n;
     for(n=0; n<G->nodes; n++)
         G->visited[n] = 0;
}

void dfs(Graph G){
     if(G == NULL) Error("No graph!");
     int n;

     for(n = 0; n < G->nodes; n++){
         if(G->visited[n] == 0){
             dfsr(n, G);
         }
     }
}

/* a function to visit the nodes in a depth-first order */
void dfsr(int x, Graph G){
   int j;

   printf("The node visited: %d\n",x);
   G->visited[x] = 1;
   for(j = 0; j < G->nodes; j++){
       if(G->adj[x][j] == 1 && G->visited[j] == 0){
           dfsr(j, G);
       }
   }
}
void dfsstr(int x, Graph G);

void dfsst(Graph G){
    if(G == NULL) Error("No graph!");

    for(int i = 0; i < G->nodes; i++){
        if (G->visited[i] == 0){
            dfsstr(i, G);
        }
    }
}
void dfsstr(int x, Graph G) {
    G->visited[x] = 1;
    for(int i = 0; i < G->nodes; i++){
        if(G->adj[x][i] == 1 && G->visited[i] == 0) {
            printf("Edge: (%d,%d)\n", x, i);
            dfsstr(i, G);
        }
    }
}

void bfsr(int x, Graph G, int array[], int r, int f);

void bfs(Graph G){
    if(G == NULL) Error("No graph!");

    int n;
    int array[G->nodes];
    for(int i = 0; i < G->nodes; i++){
        array[i] = 0;
    }

    for(n = 0; n < G->nodes; n++){
        if(G->visited[n] == 0)
            bfsr(n, G, array, -1, 0);
    }

    for(int i = 0; i < G->nodes; i++){
        if(G->visited[i] == 1){
            printf("The node visited: %d\n", i);
        }
    }
}

// a function to visit the nodes in a breadth-first order
void bfsr(int x, Graph G, int array[], int r, int f){

    G->visited[x] = 1;
    for(int i = 0; i < G->nodes; i++){
        if(G->adj[x][i] == 1 && G->visited[i] == 0){

            array[++r] = i;
            if(f <= r){
                G->visited[array[f]] = 1;
                bfsr(array[f++], G, array, r, f);
            }
        }
    }
}

void bfsst(Graph G){
    if(G == NULL) Error("No graph!");

    int* numbers = (int*)calloc(G->nodes, sizeof(int));

    for(int i = 0; i < G->nodes; i++){
        for(int j = i + 1; j < G->nodes; j++){
            if(G->adj[i][j] == 1){
                if(numbers[j] != 1 || numbers[i] != 1){
                    printf("Edge: (%d,%d)\n", i, j);
                    numbers[i] = 1;
                    numbers[j] = 1;
                }
            }
        }
    }

    free(numbers);
}
