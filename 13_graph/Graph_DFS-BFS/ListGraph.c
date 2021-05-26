#include <stdio.h>
#include <stdlib.h>
#include "ListGraph.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"

// ���� �׷����� �����ϴ� ����, operations to generate a empty graph
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

// �׷����� �������� �˻�, check if the graph is empty
int isEmptyGraph(Graph* G) {
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

// �׷��� G�� ����(u, v)�� ����, insert a edge(u, v) into graph G
void insertEdge(Graph* G, int u, int v) {

	// Fill your code
	graphNode* newNode = (graphNode*)malloc(sizeof(graphNode));
	newNode->vertex = v;
	newNode->link = G->adjList_H[u];
	G->adjList_H[u] = newNode;

}

// �׷��� G�� ���ҽ� ����, unresource graph G
void destroyGraph(Graph* G) {
	int i;
	for(i=0; i<G->n; i++) {
		if(G->adjList_H[i] != NULL)
			free(G->adjList_H[i]);
	}
	free(G);
}

// �׷��� G�� ���� ����Ʈ ���� ���, display adjacent list information for graph G
void displayGraph(Graph* G) {
	int i;
	graphNode* p;
	for(i=0; i<G->n; i++) {
		printf("���� %d�� ��������Ʈ", i);	// Adjacent list with vertex %d
		p = G->adjList_H[i];
		while(p) {
			printf(" -> %d ", p->vertex);
			p = p->link;
		}			
		printf("\n");
	}
}

// visited[], pred[] �ʱ�ȭ, initialized visited[], pre[]
void initSearch(Graph* G) {
	int i;
	for(i=0; i<G->n; i++) {
		G->visited[i] = FALSE;
		G->pred[i] = -1;
	}
}

// ���� �켱 Ž�� iterative version, depth first search iterative version
void dfs_iter(Graph* G, int v) {

	// Fill your code

	/*===DFS(���̿켱Ž��)===
	1) ���������� �����ؼ� ���� �б�� �����ϱ� �� �ش� �б� ���� ��ȸ
	2) VISITED = ��ȸ�� ���� üũ --> �湮������ TRUE, �̹湮�̸� FALSE
	3) STACK = ���� �ֱٿ� �湮�ߴ� ���� ����
	4) a> �ϳ��� ���� �湮
		 b> ������������ �� �� ������ ������ �̿� �� �ϳ� �湮
		 c> STACK ������ �ƴϸ� a,b �ݺ�*/

	graphNode* w;//�������� ���� ���� 
	Stack* s = create();
	G->visited[v] = TRUE;// a)��ȸ�� ���� �湮 ó��
	push(s, v);// b) ���� ����
	printf("%3d", v);

	while (!isEmpty(s)) {
		v = pop(s);
		w = G->adjList_H[v];
		while (w != NULL) {//���������� ������
			if (!G->visited[w->vertex]) {//   (��) �������� �߿� �湮�� ������ ������
				push(s, v);// b) ���� ����
				G->visited[w->vertex] = TRUE;// a) ��ȸ�� ���� �湮 ó��
				printf("%3d",w->vertex);//c) ACTION
				v = w->vertex;//���� ���� ����
				w = G->adjList_H[v];//���� ���� ����
			}
			else {// (��) �������� �߿� �湮�� ������ ������
				w = w->link;//backtracking
			}
		}
	}
}	

// ���� �켱 Ž�� recursive version, depth first search recursive version
void dfs_recur(Graph* G, int v)	{

	// Fill your code
	printf("%3d", v);
	graphNode* w;//�������� ���� ���� 
	G->visited[v] = TRUE;
	
	//if (G->adjList_H[v] == NULL) return;
	
	for (w = G->adjList_H[v]; w; w = w->link) {//���������� �������� üũ �� ť�� push
		if (!G->visited[w->vertex]) {//�̹湮�� ���������� �ִٸ�
			G->pred[w->vertex] = v;
			dfs_recur(G, w->vertex);//��� ȣ��
		}
	}
}



// �ʺ� �켱 Ž��, width first search
void bfs(Graph* G, int v) {

	// Fill your code

	/*===BFS(�ʺ�켱Ž��)===
	1) �������� ����� ������ ������� �湮
	2) VISITED = ��ȸ�� ���� üũ --> �湮������ TRUE, �̹湮�̸� FALSE
	3) QUEUE = ������ push, �������� ������� Ȯ������ pop
	4) a> queue ���� �տ� �ִ� ��� pop
	     b> pop�� ������ �������� �� �̹湮�� ���� push
		 c> QUEUE ������ �ƴϸ� a,b �ݺ�*/

	graphNode* w;//�������� ���� ���� 
	Queue* q = createQueue();
	G->visited[v] = TRUE;//��ȸ�� ���� Ȯ�� 
	enqueue(q, v);//
	printf("%3d", v);

	while (!isEmptyQueue(q)) {//ť�� �����϶� ���� ���� ����
		v = dequeue(q);//�������� pop
		for (w = G->adjList_H[v]; w != NULL; w = w->link) {//���������� �������� üũ �� ť�� push
			if (!G->visited[w->vertex]) {//�̹湮�� ���������� �ִٸ�
				enqueue(q, w->vertex);//ť�� push
				G->visited[w->vertex] = TRUE;//��ȸ�� ���� Ȯ��
				printf("%3d", w->vertex);
			}
		}
	}
}		
