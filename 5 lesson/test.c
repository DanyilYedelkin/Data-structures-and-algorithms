#include <stdio.h>
#include "graph.h"
#include "err.h"

int main()
   {
    int n;
    Graph G;
    printf("enter the number of nodes in graph maximum = %d\n",max);
    scanf("%d",&n);
    G = CreateGraph(n);
    buildadjm(G);

	printf("\nAdjacency matrix:\n");
    printadjm(G);

    printf("\nDepth first search:\n");
    ClearVisited(G);
    dfs(G);
    ClearVisited(G);
    printf("\nDFS Spanning tree:\n");
    dfsst(G);

    printf("\nBreadth first search:\n");
    ClearVisited(G);
    bfs(G);
    printf("\nBFS Spanning tree:\n");
    bfsst(G);

	DisposeGraph(G);
	putchar('\n');
	system("pause");
	return 0;
   }
