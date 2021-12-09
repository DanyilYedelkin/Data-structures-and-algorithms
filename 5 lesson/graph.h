#define max 10

struct GraphRecord;
typedef struct GraphRecord *Graph;

Graph CreateGraph(int NodesCount);
void DisposeGraph(Graph G);
void buildadjm(Graph G);
void printadjm(Graph G);
void ClearVisited(Graph G);
void dfs(Graph G);
void dfsr(int x, Graph G);
void dfst(int x, Graph G);
void dfsst(Graph G);
void bfs(Graph G);
void bfsst(Graph G);


void MyPrintf(const char *format, ...);