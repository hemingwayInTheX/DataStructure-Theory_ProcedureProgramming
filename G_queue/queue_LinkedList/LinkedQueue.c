#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

// ����ť ����
Queue* create() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

// ť�� ��ȭ�������� Ȯ���ϴ� ����				
int isFull(Queue* Q) {
	// Fill your code
	return 0;
}

// ť�� ����������� Ȯ���ϴ� ����			
int isEmpty(Queue* Q) {
	// Fill your code
	return Q->front == NULL && Q->rear == NULL;
}	

// ť�� rear�� ��Ҹ� �߰��ϴ� ����		
void enqueue(Queue* Q, element x) {
	// Fill your code
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));//��� ����
	newNode->data = x;//������ �� �Ҵ�
	newNode->link = NULL;//��ũ�ʵ� �ΰ����� --> ���� ����Ʈ�� Ư¡

	if (isEmpty(Q)) {//������ ��� front,rear�� ����� ����Ű����
		Q->front = newNode;
	}
	else {
		Q->rear->link = newNode;//����� �߰��� ������ rear �� ����Ű�� ����� �ּҰ� ����
	}
	Q->rear = newNode;
}	

// ť���� ���� ���� ����� ��� ���� �� ��ȯ�ϴ� ����
element dequeue(Queue* Q) {
	// Fill your code
	queueNode* temp;//������ ��带 ����ų ������
	element e;//��ȯ�� ����

	if (isEmpty(Q)) {
		printf("[ERROR] Queue is EMPTY!!\n");
		return ERROR;
	}
	/* ## ������ pop�� ����
		##  1. ��ȯ�� �غ� 
		##  2. front�� ��������� ���� ��� ����Ű����
		##  3. �޸� ����
		###  *  �б� ��� == �ڷᱸ���� ��尡 �ϳ� �ۿ� ���� ���
		###      rear�� ���� null������ �ʱ�ȭ ���� �ʴ´ٸ� enqueue����
					���� �� ���� �߻�.*/
	else {
		temp = Q->front;
		e = temp->data;
		Q->front = temp->link;
		free(temp);
		if (Q->front == NULL) {
			Q->rear = NULL;
		}
		return e;
	}
}

// ť���� ���� ���� ����� ��Ҹ� ��ȯ�ϴ� ����	
element peek(Queue* Q) {
	// Fill your code
	if (isEmpty(Q)) {
		printf("[ERROR] Queue is EMPTY!!\n");
		return ERROR;
	}
	return Q->front->data;
}	

// ť�� ��� ��� ���	
void displayQueue(Queue* Q) {
	queueNode* p = Q->front;
	printf("Queue [ ");
	while(p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// ť ����		
void clear(Queue* Q) {
	queueNode* p;
	while(Q->front) {
		p = Q->front;
		Q->front = Q->front->link;
		free(p);
		p = NULL;
	}
}			

