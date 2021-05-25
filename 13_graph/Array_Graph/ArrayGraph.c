#include <stdio.h>
#include <stdlib.h>
#include "ArrayGraph.h"

// 공백 그래프를 생성하는 연산, operations to generate a empty graph
Graph* createGraph(int type) {
	int i, j;
	Graph* G = (Graph*)malloc(sizeof(Graph));	
	G->n = 0;
	G->type = type;
	for(i=0; i<MAX_SIZE; i++) {
		for(j=0; j<MAX_SIZE; j++)
			G->adjMatrix[i][j] = 0;
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
		printf("[ERROR] 그래프 정점의 개수 초과\n");	// [ERROR] Graph vertex exceeded
		return;
	}
	G->n++;
}

// 그래프 G에 간선(u, v)를 삽입, insert a edge(u, v) into graph G
void insertEdge(Graph* G, int u, int v) {

	// Fill your code
	if (G->type == 0) {//무방향 그래프일 경우 간선 삽입
		G->adjMatrix[u][v] = 1;
		G->adjMatrix[v][u] = 1;
	}
	else {//방향 그래프일 경우 간선 삽입
		if(G->adjMatrix[u][v]!=0)//방향성 고려 --> 입력값에 해당되는 반대 인덱스에 값이 있으면 0으로 초기화
			G->adjMatrix[v][u] = 0;
		G->adjMatrix[u][v] = 1;
	}
}

// 그래프 G에 정점 v를 삭제하고 연결된 모든 간선 삭제, delete vertex v to graph G and delete all connected edges
void deleteVertex(Graph* G, int v) {

	// Fill your code
	/*==정점 v 삭제==
	1) 입력값(v)을 행,열 기준으로 해당되는 인덱스의 요소가 1임을 탐색
	2) 1인 인덱스 탐색 성공 시, 해당 위치는 0으로 초기화 --> 정점 삭제 및, 연결된 간선 삭제*/
	
	if (G->type == 0) {//무방향 그래프일 경우
		for (int i = 0; i < G->n; i++) {
			for (int j = 0; j < G->n; j++) {
				if (G->adjMatrix[i][v] == 1 || G->adjMatrix[v][i] == 1)
					G->adjMatrix[i][v] = 0;
				G->adjMatrix[v][i] = 0;
			}
		}
	}
	else {//방향 그래프일 경우
		for (int i = 0; i < G->n; i++) {
			for (int j = 0; j < G->n; j++) {
				if (G->adjMatrix[i][v] == 1 || G->adjMatrix[v][i]==1)
					G->adjMatrix[i][v] = 0;
					G->adjMatrix[v][i] = 0;
			}
		}
	}
}

// 그래프 G에 간선 (u, v)를 삭제, delete the edge(u, v) to graph G
void deleteEdge(Graph* G, int u, int v) {
	// Fill your code

	/*==간선 삭제==
	1) 입력값에 해당되는 인덱스의 값이 1인지 확인
	2) 확인될 경우 해당 원소 0으로 초기화*/
	if (G->type == 0) {//무방향 그래프일 경우
		if (G->adjMatrix[u][v] == 1) {
			G->adjMatrix[u][v] = 0;
			G->adjMatrix[v][u] = 0;
		}
	}
	else {//방향 그래프일 경우
		if (G->adjMatrix[u][v] == 1){
			G->adjMatrix[u][v] = 0;
		}
	}
}

// 그래프 G의 리소스 해제, unresource graph G
void destroyGraph(Graph* G) {
	int i, j;
	for(i=0; i<G->n; i++) {
		for(j=0; j<G->n; j++)
			G->adjMatrix[i][j] = 0;
	}
	G->n = 0;
}

// 그래프 G의 인접 행렬 정보 출력, display adjacent matrix information for graph G
void displayGraph(Graph* G) {
	int i, j;
	for(i=0; i<G->n; i++) {
		for(j=0; j<G->n; j++)
			printf("%2d\t", G->adjMatrix[i][j]);
		printf("\n");
	}
}
