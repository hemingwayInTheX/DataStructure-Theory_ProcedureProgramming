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
	
	for (int i = 0; i < G->n - 1; i++){//dist, pred 초기화 작업
		G->dist[i] = G->cost[v][i];//dist의 초기값은 인접행렬에서 시작정점의 행
		if (G->cost[v][i] != NULL) {//어떤 정점을 거쳐가는지를 저장하는 pred 초기화
			G->pred[i] = v;
		}
		else {
			G->pred[i] = NULL;
		}
	G->S[v] = 1;//집합 S에 시작정점에 대한 정보를 기억하도록함
	}/*LOOP_1*/
	for (int i = 0; i < G->n; i++){//모든 정점에 대한 relaxation 과정을 완료할 때까지 루프 진행
		u = nextVertex(G);//dist에서 최소비용이 가장 작은 정점을 선택
		G->S[u] = 1;//집합 S에 추가 --> 정점을 추가함으로써 해당 정점을 지나칠 경우 최소비용이 갱신되는지 확인
		for (int w = 0; w < G->n ; w++){//타겟 정점 갱신
			if (G->S[w]!=1 && G->dist[u] + G->cost[u][w]< G->dist[w]) {//기존 비용이 relaxation결과보다 비싸면 해당 값으로 갱신
				G->dist[w] = G->dist[u] + G->cost[u][w];
				G->pred[w] = u;
			}
		}
	}/*LOOP_2*/
}
//G->S[i + 1] != w
// Bellman-Ford Algorithm
int bellmanFord(Graph* G, int v) {

	// Fill your code
	
	/*===벨만포드===
	1) 음수 가중치 허용, 음수 사이클 확인 가능
	2) relaxation = 총 정점의 개수에서 -1만큼 모든 정점 확인
	3) 정점의 개수와 동일한 횟수에서도 최단 경로값이 갱신된다면
	해당 그래프는 음수 사이클을 지니고 있음*/
	int numOfGraph = G->n;//현재 그래프에 삽입된 노드의 개수
	int w = 0;
	int u = 0;
	for (int i = 0; i < numOfGraph; i++) {//모든 정점에 대한 최소 비용을 무한대로 초기화
		G->dist[i] = INF;
	}
	G->dist[v] = 0;//시작 정점은 0으로 초기화

	for (int i = 0; i < numOfGraph - 1; i++) {//정점의 개수보다 1적은 만큼 루프 수행
		for (int u = 0; u < numOfGraph; u++) {//내부 중첩 for문 = 모든 간선에 대한 relaxation을 위한 루프
			for (int w = 0; w < numOfGraph; w++){
				if (G->cost[u][w]== 0 || G->cost[u][w] == INF) {//무한대 OR 0 을 원소로 가지면 루프 재수행
					continue;
				}
				if (G->dist[w] > G->dist[u] + G->cost[u][w]) {//갱신된 비용이 기존의 값보다 저렴하면 해당 값으로 갱신
					G->dist[w] = G->dist[u] + G->cost[u][w];
					G->pred[w] = u;
				}
			}
		}
	}/*LOOP_1*/
	for (int u = 0; u < numOfGraph; u++) {//정점-1만큼 relaxation 수행 후 다시 한 번 검사 --> 음수 사이클 여부 chk
		for (int w = 0; w < numOfGraph; w++) {
			if (G->dist[w] > G->dist[u] + G->cost[u][w]) {//dist값이 갱신되면 false 반환
				return FALSE;
			}
		}
	}/*LOOP_2*/
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
	printf("%c -> %c 최단 경로: %c\t", src+65, dst+65, src+65);	// "%c -> %c Shortest Path: %c"
	int v = dst;//v=3
	Stack* stack = createStack();

	// Fill your code

	/*===스택을 이용한 PRED배열 출력===
	종료정점을 거쳐간 정점을 역순으로 추적 --> 마지막에 스택에 PUSH되는 요소가 시작정점
	(시작정점은 사전에 출력되므로 그 다음 정점부터 출력하도록)*/
	int temp = G->pred[v];//비교연산을 위한 변수 
	element item = 0;

	push(stack, v);//종료 정점 먼저 스택에 저장
	for (int i = 0; i < G->n; i++) {
		if (temp == 0)break;//시작정점이면 루프 종료
		if (temp == i) {//인덱스 i가 종료정점의 이전 정점 --> 해당 인덱스 stack 연산 수행 및 temp 갱신
			push(stack, i);
			temp = G->pred[i];
		}
	}
	while (stack->top != -1) {//스택이 공백이면 작업 종료
		item = pop(stack);
		printf("%c\t", item + 65);
	}

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
