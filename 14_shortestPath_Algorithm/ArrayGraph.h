#ifndef __ARRAY_GRAPH_H__
#define _ARRAY_GRAPH_H__

#define MAX_SIZE 10
#define INF 987654321
#define NONE 9999

// 그래프를 인접 행렬로 표현하기 위한 구조체 정의, define structures for representing graphs as adjacency matrices
typedef struct GraphType {
	int n; 
	int cost[MAX_SIZE][MAX_SIZE];
	int dist[MAX_SIZE];
	int pred[MAX_SIZE];
	int S[MAX_SIZE];
	int A[MAX_SIZE][MAX_SIZE];
} Graph;

Graph* createGraph();									// 공백 그래프를 생성하는 연산, operations that generate a empty graph
int isEmpty(Graph* G);									// 그래프가 공백인지 검사, check if the graph is empty
void insertVertex(Graph* G, int v);						// 그래프 G에 정점 v를 삽입, insert vertex v into graph G
void insertEdge(Graph* G, int u, int v, int weight);	// 그래프 G에 간선(u, v)를 삽입, insert edge(u, v) into graph G
void deleteVertex(Graph* G, int v);						// 그래프 G에 정점 v를 삭제하고 연결된 모든 간선 삭제, delete vertex v in graph G and delete all connected edges
void deleteEdge(Graph* G, int u, int v);				// 그래프 G에 간선 (u, v)를 삭제, delete edge(u, v) on graph G
void destroyGraph(Graph* G);							// 그래프 G의 리소스 해제, unresource graph G
void displayGraph(Graph* G);							// 그래프 G의 인접 행렬 정보 출력, display adjacency matrix information for graph G

int nextVertex(Graph* G);								// 최소 비용을 갖는 다음 정점을 찾는 연산, operation that finds the next vertex with a minimum cost
void dijkstra(Graph* G, int v);							// Dijkstra Algorithm
int bellmanFord(Graph* G, int v);						// Bellman-Ford Algorithm
void floyd(Graph* G);									// Floyd-Warshall Algorithm
void printShortestPath(Graph* G, int src, int dst);		// 최단경로 출력, display shortest path
int printShortestPathCost(Graph* G, int src, int dst);	// 최단경로 비용 출력, display shortest path cost
void printAllPairShortestCost(Graph* G);				// 모든 정점 쌍 사이의 최단 경로 비용 출력, display shorteet path cost between all pairs of vertices
 
#endif
