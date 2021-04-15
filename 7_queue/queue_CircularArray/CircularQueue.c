#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

// ����ť ����
Queue* create() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = 0;
	Q->rear = 0;
	return Q;
}

// ť�� ��ȭ�������� Ȯ���ϴ� ����				
int isFull(Queue* Q) {
	/*mod ���� --> ����ť�� �ٽ��� ������ �ε��� ����, 0��° �ε������� ���� ������Ʈ �ǵ���.*/
	return (Q->rear + 1) % MAX_SIZE == Q->front;	
}

// ť�� ����������� Ȯ���ϴ� ����			
int isEmpty(Queue* Q) {
	return Q->front == Q->rear;
}	

// ť�� rear�� ��Ҹ� �߰��ϴ� ����		
void enqueue(Queue* Q, element x) {
	if (isFull(Q)) {//ť�� �ڷᱸ���� ��ȭ���¸� �� �̻� ���� ���� �������� �ʰ� ����.
		printf("[ERROR] Queue is full!!\n");
		return;
	}
	Q->rear = (Q->rear + 1) % MAX_SIZE;
	Q->queue[Q->rear] = x;
}	

// ť���� ���� ���� ����� ��� ���� �� ��ȯ�ϴ� ����
element dequeue(Queue* Q) {
	if (isEmpty(Q)) {//ť�� �ڷᱸ���� ������¸� �� �̻� ���� ���� �������� �ʰ� ����.
		printf("[ERROR] Queue is empty!!\n");
		return;
	}
	Q->front = (Q->front + 1) % MAX_SIZE;
	return Q->queue[Q->front];
}

// ť���� ���� ���� ����� ��Ҹ� ��ȯ�ϴ� ����	
element peek(Queue* Q) {
	if (isEmpty(Q)) {//ť�� �ڷᱸ���� ������¸� �� �̻� ���� ���� �������� �ʰ� ����.
		printf("[ERROR] Queue is full!!\n");
		return;
	}
	return (Q->front + 1) % MAX_SIZE;
}	

// ť�� ��� ��� ���	
void displayQueue(Queue* Q) {
	int i, first, rear;
	first = (Q->front+1) % MAX_SIZE;
	rear = (Q->rear+1) % MAX_SIZE;
	i = first;
	printf("QUEUE [ ");
	while(i != rear) {
		printf("%d ", Q->queue[i]);
		i = (i+1) % MAX_SIZE;
	}
	printf(" ]\tfront: %d\trear: %d\n", Q->front, Q->rear);
}

// ť ����		
void clear(Queue* Q) {
	Q->rear = Q->front;
}			
