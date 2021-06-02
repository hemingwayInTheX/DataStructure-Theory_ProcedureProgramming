#include <stdio.h>
#include <stdlib.h>
#include "ArrayGraph.h"
#include "ArrayStack.h"

// ���� �׷����� �����ϴ� ����, operations that generate a empty graph
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

// �׷����� �������� �˻�, check if the graph is empty	
int isEmpty(Graph* G) {
	return G->n == 0;
}

// �׷��� G�� ���� v�� ����, insert vertex v into graph G
void insertVertex(Graph* G, int v) {
	if((G->n)+1 > MAX_SIZE) {
		printf("[ERROR] �׷��� ������ ���� �ʰ�\n");	// [ERROR] Exceeding the number of graph vertices
		return;
	}
	G->n++;
}

// �׷��� G�� ����(u, v)�� ����, insert edge(u, v) into graph G
void insertEdge(Graph* G, int u, int v, int weight) {
	G->cost[u][v] = weight;	
}

// �׷��� G�� ���� v�� �����ϰ� ����� ��� ���� ����, delete vertex v in graph G and delete all connected edges
void deleteVertex(Graph* G, int v) {
	int i;
	for(i=0; i<G->n; i++) {
		G->cost[i][v] = INF;
		G->cost[v][i] = INF;
	}	
}

// �׷��� G�� ���� (u, v)�� ����, delete edge(u, v) on graph G
void deleteEdge(Graph* G, int u, int v) {
	G->cost[u][v] = INF;
}

// �׷��� G�� ���ҽ� ����, unresource graph G
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

// �׷��� G�� ���� ��� ���� ���, display adjacency matrix information for graph G
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

// �ּ� ����� ���� ���� ������ ã�� ����, operation that finds the next vertex with a minimum cost
// Dijkstra Algorithm ������ �ʿ��� ��� �̿�, use when needed to implement Dijkstra Algorithm 
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

	/*===���ͽ�Ʈ��===
	1) ���� ������ �־����� �̿� ���� �׷��� G�� ��� �����鿡 ���� �ּҺ�� ���
	2) relaxation = ������ �߰��ϸ鼭 �߰��� ������ ���İ� ��� ������ ��뺸�� 
	������ �� �ش� ������ ����
	3) ��� ������ ���� relaxation�� ������ �۾� ����*/
	int u = 0;//�߰��Ǵ� ������ ���� ������ ������ �ִ� ����
	G->S[0] = v;//���� S�� ���������� ���� ������ ����ϵ�����
	
	for (int i = 0; i < G->n - 1; i++){//dist, pred �ʱ�ȭ �۾�
		G->dist[i] = G->cost[v][i];//dist�� �ʱⰪ�� ������Ŀ��� ���������� ��
		if (G->cost[v][i] != NULL) {//� ������ ���İ������� �����ϴ� pred �ʱ�ȭ
			G->pred[i] = v;
		}
		else {
			G->pred[i] = NULL;
		}
	}/*LOOP_1*/
	for (int i = 0; G->S[i+1]!=G->n; i++){//��� ������ ���� relaxation ������ �Ϸ��� ������ ���� ����
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
	//for (int i = 0; i < G->n-1; i++){//���������� ������ �׷��� G�� ���� ������ŭ ��� ������ ���� relaxation �۾� ����
	//	for (int i = 0; i < length; i++){
	//		if(G->dist[v]>dist)
	//	}
	//}

}	

// Floyd-Warshall Algorithm
void floyd(Graph* G){

	// Fill your code
	/*===�÷��̵� �ͼ�===
	1) ��� ���� �� ���� �ִ� �Ÿ� ���
	2) ���ͽ�Ʈ�� cost��Ŀ��� ���������� �ش��ϴ� ������ dist�� �ʱ�ȭ�ߴٸ�
	�÷��̵�� cost���(2���� �迭)��ü�� �ʱ����
	3) ��� ������ ���İ��鼭 ���� �ְ��� �ּҺ�� ���*/
	for (int i = 0; i < G->n; i++) {
		for (int j = 0; j < G->n; j++){
			G->A[i][j] = G->cost[i][j];
		}
	}//LOOP_1
	for (int k = 0; k < G->n; k++){//����� k�� ���İ��� ������ ���� ���� ����
		for (int i = 0; i < G->n; i++){//����� i�� �� ���� ����
			for (int j = 0; j < G->n; j++){//����� j�� �� ���� ����
				if (G->A[i][k] + G->A[k][j] < G->A[i][j]) {//Ư�� ������ ���� ���� ����� ������ ��κ��� �����ϸ� �ش� �ε��� ����
					G->A[i][j] = G->A[i][k] + G->A[k][j];
				}
			}
		}
	}

}	

// �ִܰ�� ���, display shortest path
void printShortestPath(Graph* G, int src, int dst) {
	printf("%c -> %c �ִ� ���: %c", src+65, dst+65, src+65);	// "%c -> %c Shortest Path: %c"
	int v = dst;
	Stack* stack = createStack();

	// Fill your code
	

	printf("\n");
	clearStack(stack);
}	

// �ִܰ�� ��� ���, display shortest path cost
int printShortestPathCost(Graph* G, int src, int dst) {
	printf("%c -> %c �ִ� ��� ���: %d\n", src+65, dst+65, G->dist[dst]);	// "%c -> %c Shortest Path Cost: %d"
}

// ��� ���� �� ������ �ִ� ��� ��� ���, display shorteet path cost between all pairs of vertices
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
