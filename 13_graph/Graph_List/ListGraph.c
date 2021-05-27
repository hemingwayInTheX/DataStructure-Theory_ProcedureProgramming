#include <stdio.h>
#include <stdlib.h>
#include "ListGraph.h"

// 공백 그래프를 생성하는 연산, operations to generate a empty graph
Graph* createGraph(int type) {
	int i;
	Graph* G = (Graph*)malloc(sizeof(Graph));	
	G->n = 0;
	G->type = type;
	for(i=0; i<MAX_SIZE; i++) {
		G->adjList_H[i] = NULL;
	}
	return G;
}

// 그래프가 공백인지 검사, check if the graph is empth
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
	graphNode* chkOverlap;//VERTEX 중복 확인 --> 재귀 호출의 탈출 조건
	graphNode* newNode = (graphNode*)malloc(sizeof(graphNode));// 1)노드 생성
	newNode->vertex = v;// 2) 새노드 정점 초기화
	newNode->link = NULL;

	chkOverlap = G->adjList_H[u];
	while (chkOverlap != NULL) { //연결된 노드들이 있으면 아래 실행문 수행
		if (chkOverlap->vertex == v)//중복 정점 있으면 재귀 종료
			return;
		chkOverlap = chkOverlap->link;
	}

	newNode->link = G->adjList_H[u];// 새노드와 헤더 연결 -->  EX) [0] -----> 3 -->1
	G->adjList_H[u] = newNode;

	if (G->type == UNDIRECT) {//무방향 그래프일 경우 꼬리와 머리의 매개변수 위치를 바꿔서 호출
		insertEdge(G, v, u);
	}
}
		
// 그래프 G에 정점 v를 삭제하고 연결된 모든 간선 삭제, delete vertex v to graph G and delete all connected edges
void deleteVertex(Graph* G, int v) {

	// Fill your code
	graphNode* cgr = G->adjList_H[0];//타깃 노드
	graphNode* pgr = NULL;//타깃 노드의 이전 노드
	int idx = 0;

	/*=== 삭제 ===
	1) 포인터 배열의 인덱스가 NULL을 만날 때까지 작업 수행
	2) 단말일 경우와 단말이 아닐 경우 위치를 갱신하는데 있어 차이를 가짐
	3) 증가된 인덱스 값이 삭제하고자 하는 정점과 값일 동일할 경우 해당 링크필드 NULL로 초기화*/
	
	while (G->adjList_H[idx] != NULL) {
		if (cgr->link == NULL) {//단말일 경우
			cgr = G->adjList_H[++idx];//1번째 인덱스의 주소값으로 갱신
		}
		else {
			pgr = cgr;//이전노드 갱신
			cgr = cgr->link;//타깃 노드 갱신
		    
			if (cgr->vertex == v) {//탐색 성공시
				pgr->link = cgr->link;//이전노드와 다음노드연결
			}
			if (idx == v) {
				G->adjList_H[idx] = NULL;
				idx++;
			}
		}
	}
}


// 그래프 G에 간선 (u, v)를 삭제, delete the edge(u, v) to graph G
void deleteEdge(Graph* G, int u, int v) {
		
	// Fill your code
	graphNode* pgr = G->adjList_H[u];//타깃 노드의 이전 노드
	graphNode* cgr = G->adjList_H[u]->link;//타깃 노드
	graphNode* temp;

	if (v >= G->n) {
		printf("그래프 초과.\n\n");
	}
	while (cgr != NULL) {
		temp = cgr->link;
			if (cgr->vertex == v) {//삭제하고자 하는 정점을 만나면
				pgr->link = cgr->link;//삭제노드의 이전노드와 다음 노드를 연결
				free(cgr);//메모리 해제
				break;
			}
		pgr = cgr;//타깃과 이전 노드 갱신작업
		cgr = temp;
	}
	/*동일한 작업 반복 수행 --> 서로의 인접 노드를 삭제하기 위함*/
	pgr = G->adjList_H[v];
	cgr = G->adjList_H[v]->link;

	while (cgr != NULL) {
		temp = cgr->link;
			if (cgr->vx == u) {
				pgr->link = cgr->link;
				free(cgr);
				break;
			}
			pgr = cgr;
			cgr = temp;
	}
}

// 그래프 G의 리소스 해제, unresource graph G
void destroyGraph(Graph* G) {
	int i;
	for(i=0; i<G->n; i++) {
		if(G->adjList_H[i] != NULL)
			free(G->adjList_H[i]);
	}
	free(G);
}

// 그래프 G의 인접 리스트 정보 출력, display adjacent list information for graph G
void displayGraph(Graph* G) {
	int i;
	graphNode* p;
	for(i=0; i<G->n; i++) {
		printf("정점 %d의 인접리스트", i);	// Adjacent list of vertex %d
		p = G->adjList_H[i];
		while(p) {
			printf(" -> %d ", p->vertex);
			p = p->link;
		}			
		printf("\n");
	}
}

