#include <stdio.h>
#include <stdlib.h>
#include "ListGraph.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"

// 공백 그래프를 생성하는 연산, operations to generate a empty graph
Graph* createGraph(int type) {
	int i;
	Graph* G = (Graph*)malloc(sizeof(Graph));	
	G->n = 0;
	G->type = type;
	for(i=0; i<MAX_SIZE; i++) {
		G->adjList_H[i] = NULL;
		G->visited[i] = FALSE;
		G->pred[i] = -1;
	}
	return G;
}

// 그래프가 공백인지 검사, check if the graph is empty
int isEmptyGraph(Graph* G) {
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

// 그래프 G에 간선(u, v)를 삽입, insert a edge(u, v) into graph G
void insertEdge(Graph* G, int u, int v) {

	// Fill your code
	graphNode* newNode = (graphNode*)malloc(sizeof(graphNode));
	newNode->vertex = v;
	newNode->link = G->adjList_H[u];
	G->adjList_H[u] = newNode;

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
		printf("정점 %d의 인접리스트", i);	// Adjacent list with vertex %d
		p = G->adjList_H[i];
		while(p) {
			printf(" -> %d ", p->vertex);
			p = p->link;
		}			
		printf("\n");
	}
}

// visited[], pred[] 초기화, initialized visited[], pre[]
void initSearch(Graph* G) {
	int i;
	for(i=0; i<G->n; i++) {
		G->visited[i] = FALSE;
		G->pred[i] = -1;
	}
}

// 깊이 우선 탐색 iterative version, depth first search iterative version
void dfs_iter(Graph* G, int v) {

	// Fill your code

	/*===DFS(깊이우선탐색)===
	1) 시작점에서 시작해서 다음 분기로 갱신하기 전 해당 분기 부터 순회
	2) VISITED = 순회한 정점 체크 --> 방문했으면 TRUE, 미방문이면 FALSE
	3) STACK = 가장 최근에 방문했던 정점 저장
	4) a> 하나의 정점 방문
		 b> 인접정점으로 갈 수 있으면 무조건 이웃 중 하나 방문
		 c> STACK 공백이 아니면 a,b 반복*/

	graphNode* w;//인접정점 정보 저장 
	Stack* s = create();
	G->visited[v] = TRUE;// a)순회한 정점 방문 처리
	push(s, v);// b) 스택 삽입
	printf("%3d", v);

	while (!isEmpty(s)) {
		v = pop(s);
		w = G->adjList_H[v];
		while (w != NULL) {//인접정점이 있으면
			if (!G->visited[w->vertex]) {//   (ㄱ) 인접정점 중에 방문할 정점이 있으면
				push(s, v);// b) 스택 삽입
				G->visited[w->vertex] = TRUE;// a) 순회한 정점 방문 처리
				printf("%3d",w->vertex);//c) ACTION
				v = w->vertex;//시작 정점 갱신
				w = G->adjList_H[v];//인접 정점 갱신
			}
			else {// (ㄴ) 인접정점 중에 방문할 정점이 없으면
				w = w->link;//backtracking
			}
		}
	}
}	

// 깊이 우선 탐색 recursive version, depth first search recursive version
void dfs_recur(Graph* G, int v)	{

	// Fill your code
	printf("%3d", v);
	graphNode* w;//인접정점 정보 저장 
	G->visited[v] = TRUE;
	
	//if (G->adjList_H[v] == NULL) return;
	
	for (w = G->adjList_H[v]; w; w = w->link) {//시작정점의 인접정점 체크 후 큐에 push
		if (!G->visited[w->vertex]) {//미방문한 인접정점이 있다면
			G->pred[w->vertex] = v;
			dfs_recur(G, w->vertex);//재귀 호출
		}
	}
}



// 너비 우선 탐색, width first search
void bfs(Graph* G, int v) {

	// Fill your code

	/*===BFS(너비우선탐색)===
	1) 시작점과 가까운 정점을 순서대로 방문
	2) VISITED = 순회한 정점 체크 --> 방문했으면 TRUE, 미방문이면 FALSE
	3) QUEUE = 시작점 push, 시작점의 인접노드 확인위해 pop
	4) a> queue 가장 앞에 있는 노드 pop
	     b> pop한 정점의 인접정점 중 미방문한 정점 push
		 c> QUEUE 공백이 아니면 a,b 반복*/

	graphNode* w;//인접정점 정보 저장 
	Queue* q = createQueue();
	G->visited[v] = TRUE;//순회한 정점 확인 
	enqueue(q, v);//
	printf("%3d", v);

	while (!isEmptyQueue(q)) {//큐가 공백일때 까지 루프 실행
		v = dequeue(q);//시작정점 pop
		for (w = G->adjList_H[v]; w != NULL; w = w->link) {//시작정점의 인접정점 체크 후 큐에 push
			if (!G->visited[w->vertex]) {//미방문한 인접정점이 있다면
				enqueue(q, w->vertex);//큐에 push
				G->visited[w->vertex] = TRUE;//순회한 정점 확인
				printf("%3d", w->vertex);
			}
		}
	}
}		
