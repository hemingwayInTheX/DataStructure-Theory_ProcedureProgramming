#include <stdio.h>
#include <stdlib.h>
#include "ListGraph.h"

// ���� �׷����� �����ϴ� ����, operations to generate a empty graph
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

// �׷����� �������� �˻�, check if the graph is empth
int isEmpty(Graph* G) {
	return G->n == 0;
}

// �׷��� G�� ���� v�� ����, insert vertex v into graph G
void insertVertex(Graph* G, int v) {
	if((G->n)+1 > MAX_SIZE) {
		printf("[ERROR] �׷��� ������ ���� �ʰ�\n");	// [ERROR] Graph vertex exceeded
		return;
	}
	G->n++;
}

// �׷��� G�� ����(u, v)�� ����, insert a edge(u, v) into graph G
void insertEdge(Graph* G, int u, int v) {

	// Fill your code
	graphNode* chkOverlap;//VERTEX �ߺ� Ȯ�� --> ��� ȣ���� Ż�� ����
	graphNode* newNode = (graphNode*)malloc(sizeof(graphNode));// 1)��� ����
	newNode->vertex = v;// 2) ����� ���� �ʱ�ȭ
	newNode->link = NULL;

	chkOverlap = G->adjList_H[u];
	while (chkOverlap != NULL) { //����� ������ ������ �Ʒ� ���๮ ����
		if (chkOverlap->vertex == v)//�ߺ� ���� ������ ��� ����
			return;
		chkOverlap = chkOverlap->link;
	}

	newNode->link = G->adjList_H[u];// ������ ��� ���� -->  EX) [0] -----> 3 -->1
	G->adjList_H[u] = newNode;

	if (G->type == UNDIRECT) {//������ �׷����� ��� ������ �Ӹ��� �Ű����� ��ġ�� �ٲ㼭 ȣ��
		insertEdge(G, v, u);
	}
}
		
// �׷��� G�� ���� v�� �����ϰ� ����� ��� ���� ����, delete vertex v to graph G and delete all connected edges
void deleteVertex(Graph* G, int v) {

	// Fill your code
	graphNode* cgr = G->adjList_H[0];//Ÿ�� ���
	graphNode* pgr = NULL;//Ÿ�� ����� ���� ���
	int idx = 0;

	/*=== ���� ===
	1) ������ �迭�� �ε����� NULL�� ���� ������ �۾� ����
	2) �ܸ��� ���� �ܸ��� �ƴ� ��� ��ġ�� �����ϴµ� �־� ���̸� ����
	3) ������ �ε��� ���� �����ϰ��� �ϴ� ������ ���� ������ ��� �ش� ��ũ�ʵ� NULL�� �ʱ�ȭ*/
	
	while (G->adjList_H[idx] != NULL) {
		if (cgr->link == NULL) {//�ܸ��� ���
			cgr = G->adjList_H[++idx];//1��° �ε����� �ּҰ����� ����
		}
		else {
			pgr = cgr;//������� ����
			cgr = cgr->link;//Ÿ�� ��� ����
		    
			if (cgr->vertex == v) {//Ž�� ������
				pgr->link = cgr->link;//�������� ������忬��
			}
			if (idx == v) {
				G->adjList_H[idx] = NULL;
				idx++;
			}
		}
	}
}


// �׷��� G�� ���� (u, v)�� ����, delete the edge(u, v) to graph G
void deleteEdge(Graph* G, int u, int v) {
		
	// Fill your code
	graphNode* pgr = G->adjList_H[u];//Ÿ�� ����� ���� ���
	graphNode* cgr = G->adjList_H[u]->link;//Ÿ�� ���
	graphNode* temp;

	if (v >= G->n) {
		printf("�׷��� �ʰ�.\n\n");
	}
	while (cgr != NULL) {
		temp = cgr->link;
			if (cgr->vertex == v) {//�����ϰ��� �ϴ� ������ ������
				pgr->link = cgr->link;//��������� �������� ���� ��带 ����
				free(cgr);//�޸� ����
				break;
			}
		pgr = cgr;//Ÿ��� ���� ��� �����۾�
		cgr = temp;
	}
	/*������ �۾� �ݺ� ���� --> ������ ���� ��带 �����ϱ� ����*/
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
		printf("���� %d�� ��������Ʈ", i);	// Adjacent list of vertex %d
		p = G->adjList_H[i];
		while(p) {
			printf(" -> %d ", p->vertex);
			p = p->link;
		}			
		printf("\n");
	}
}

