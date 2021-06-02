#include <stdio.h>
#include <stdlib.h>
#include "ArrayGraph.h"
#include "ArrayStack.h"

// 공백 그래프를 생성하는 연산, operations that generate a empty graph
Graph* createGraph() {
	int i, j;
	Graph* G = (Graph*)malloc(sizeof(Graph));	
	G->n = 0;
	for(i=0; i<MAX_SIZE; i++) {
		for(j=0; j<MAX_SIZE; j++) {
			if(i==j)
				G->cost[i][j] = 0;
			else
				G->cost[i][j] = INF;
			G->A[i][j] = INF;
		}
		G->dist[i] = INF;
		G->pred[i] = NONE;
		G->S[i] = 0;
	}
	return G;
}

// 그래프가 공백인지 검사, check if the graph is empty	
int isEmpty(Graph* G) {
	return G->n == 0;
}

// 그래프 G에 정점 v를 삽입, insert vertex v into graph G
void insertVertex(Graph* G, int v) {
	if((G->n)+1 > MAX_SIZE) {
		printf("[ERROR] 그래프 정점의 개수 초과\n");	// [ERROR] Exceeding the number of graph vertices
		return;
	}
	G->n++;
}

// 그래프 G에 간선(u, v)를 삽입, insert edge(u, v) into graph G
void insertEdge(Graph* G, int u, int v, int weight) {
	G->cost[u][v] = weight;	
}

// 그래프 G에 정점 v를 삭제하고 연결된 모든 간선 삭제, delete vertex v in graph G and delete all connected edges
void deleteVertex(Graph* G, int v) {
	int i;
	for(i=0; i<G->n; i++) {
		G->cost[i][v] = INF;
		G->cost[v][i] = INF;
	}	
}

// 그래프 G에 간선 (u, v)를 삭제, delete edge(u, v) on graph G
void deleteEdge(Graph* G, int u, int v) {
	G->cost[u][v] = INF;
}

// 그래프 G의 리소스 해제, unresource graph G
void destroyGraph(Graph* G) {
	int i, j;
	for(i=0; i<G->n; i++) {
		for(j=0; j<G->n; j++) {
			if(i != j)
				G->cost[i][j] = INF;
	}
		G->dist[i] = INF;
		G->pred[i] = NONE;
	}
	G->n = 0;
}

// 그래프 G의 인접 행렬 정보 출력, display adjacency matrix information for graph G
void displayGraph(Graph* G) {
	int i, j;
	for(i=0; i<G->n; i++) {
		for(j=0; j<G->n; j++){
			if(G->cost[i][j] == INF)
				printf("INF\t");
			else
				printf("%2d\t", G->cost[i][j]);
		}			
		printf("\n");
	}
}

// 최소 비용을 갖는 다음 정점을 찾는 연산, operation that finds the next vertex with a minimum cost
// Dijkstra Algorithm 구현시 필요할 경우 이용, use when needed to implement Dijkstra Algorithm 
int nextVertex(Graph* G) {
	int i, minCost, minVertex;
	minCost = INF;
	minVertex = -1;
	for(i=0; i<G->n; i++) {
		if(G->dist[i] < minCost && !G->S[i]) {
			minCost = G->dist[i];
			minVertex = i;
		}
	}
	return minVertex;
}	

// Dijkstra Algorithm
void dijkstra(Graph* G, int v) {

	// Fill your code

	/*===다익스트라===
	1) 시작 정점이 주어지고 이에 대한 그래프 G의 모든 정점들에 대한 최소비용 계산
	2) relaxation = 정점을 추가하면서 추가된 정점을 거쳐갈 경우 기존의 비용보다 
	저렴할 때 해당 값으로 갱신
	3) 모든 정점에 대한 relaxation이 끝나면 작업 종료*/
	int u = 0;//추가되는 정점에 대한 정보를 가지고 있는 변수
	G->S[0] = v;//집합 S에 시작정점에 대한 정보를 기억하도록함
	
	for (int i = 0; i < G->n - 1; i++){//dist, pred 초기화 작업
		G->dist[i] = G->cost[v][i];//dist의 초기값은 인접행렬에서 시작정점의 행
		if (G->cost[v][i] != NULL) {//어떤 정점을 거쳐가는지를 저장하는 pred 초기화
			G->pred[i] = v;
		}
		else {
			G->pred[i] = NULL;
		}
	}/*LOOP_1*/
	for (int i = 0; G->S[i+1]!=G->n; i++){//모든 정점에 대한 relaxation 과정을 완료할 때까지 루프 진행
		u = nextVertex(G);
		G->S[i] = u;
		for (int w = 0; w < G->n ; w++){
			if (G->S[i + 1] != w && G->dist[u] + G->cost[u][w]) {
				G->dist[w] = G->dist[u] + G->cost[u][w];
				G->pred[w] = u;
			}
		}

	}/*LOOP_2*/
}

// Bellman-Ford Algorithm
int bellmanFord(Graph* G, int v) {

	// Fill your code
	//for (int i = 0; i < G->n-1; i++){//시작정점을 제외한 그래프 G의 정점 개수만큼 모든 간선에 대한 relaxation 작업 수행
	//	for (int i = 0; i < length; i++){
	//		if(G->dist[v]>dist)
	//	}
	//}

}	

// Floyd-Warshall Algorithm
void floyd(Graph* G){

	// Fill your code
	/*===플로이드 와샬===
	1) 모든 정점 쌍 간의 최단 거리 계산
	2) 다익스트라가 cost행렬에서 시작정점에 해당하는 정보로 dist를 초기화했다면
	플로이드는 cost행렬(2차원 배열)자체가 초기상태
	3) 모든 정점을 거쳐가면서 정점 쌍간의 최소비용 계산*/
	for (int i = 0; i < G->n; i++) {
		for (int j = 0; j < G->n; j++){
			G->A[i][j] = G->cost[i][j];
		}
	}//LOOP_1
	for (int k = 0; k < G->n; k++){//제어변수 k는 거쳐가는 정점에 대한 정보 갱신
		for (int i = 0; i < G->n; i++){//제어변수 i는 행 정보 갱신
			for (int j = 0; j < G->n; j++){//제어변수 j는 열 정보 갱신
				if (G->A[i][k] + G->A[k][j] < G->A[i][j]) {//특정 정점을 거쳐 가는 비용이 기존의 경로보다 저렴하면 해당 인덱스 갱신
					G->A[i][j] = G->A[i][k] + G->A[k][j];
				}
			}
		}
	}

}	

// 최단경로 출력, display shortest path
void printShortestPath(Graph* G, int src, int dst) {
	printf("%c -> %c 최단 경로: %c", src+65, dst+65, src+65);	// "%c -> %c Shortest Path: %c"
	int v = dst;
	Stack* stack = createStack();

	// Fill your code
	

	printf("\n");
	clearStack(stack);
}	

// 최단경로 비용 출력, display shortest path cost
int printShortestPathCost(Graph* G, int src, int dst) {
	printf("%c -> %c 최단 경로 비용: %d\n", src+65, dst+65, G->dist[dst]);	// "%c -> %c Shortest Path Cost: %d"
}

// 모든 정점 쌍 사이의 최단 경로 비용 출력, display shorteet path cost between all pairs of vertices
void printAllPairShortestCost(Graph* G) {
	int i, j;
	
	for(i=0; i<G->n; i++) {
		for(j=0; j<G->n; j++) {
			if(G->A[i][j] == INF)
				printf("INF\t");
			else
				printf("%2d\t", G->A[i][j]);
		}			
		printf("\n");
	}
}		
