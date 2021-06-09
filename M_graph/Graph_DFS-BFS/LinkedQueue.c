#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

// ����ť ����, create s empty queue
Queue* createQueue() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

// ť�� ����������� Ȯ���ϴ� ����, operations to determine if a queue is empty	
int isEmptyQueue(Queue* Q) {

	// Fill your code
	return Q->front == NULL && Q->rear == NULL;

}	

// ť�� rear�� ��Ҹ� �߰��ϴ� ����, operations that add elements to the rear of a queue
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

// ť���� ���� ���� ����� ��� ���� �� ��ȯ�ϴ� ����, operations that delete and return the first stored element in a queue
element dequeue(Queue* Q) {

	// Fill your code

	/* ## ������ pop�� ����
		##  1. ��ȯ�� �غ�
		##  2. front�� ��������� ���� ��� ����Ű����
		##  3. �޸� ����
		###  *  �б� ��� == �ڷᱸ���� ��尡 �ϳ� �ۿ� ���� ���
		###      rear�� ���� null������ �ʱ�ȭ ���� �ʴ´ٸ� enqueue����
					���� �� ���� �߻�.*/

	queueNode* temp;//������ ��带 ����ų ������
	element e;//��ȯ�� ����

	if (isEmpty(Q)) {
		printf("[ERROR] Queue is EMPTY!!\n");
		return ERROR;
	}
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

// ť ����, empth queue		
void clearQueue(Queue* Q) {
	queueNode* p;
	while(Q->front) {
		p = Q->front;
		Q->front = Q->front->link;
		free(p);
		p = NULL;
	}
}			

