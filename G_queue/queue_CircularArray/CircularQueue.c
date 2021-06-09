#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

// 공백큐 생성
Queue* create() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = 0;
	Q->rear = 0;
	return Q;
}

// 큐가 포화상태인지 확인하는 연산				
int isFull(Queue* Q) {
	/*mod 연산 --> 원형큐의 핵심은 마지막 인덱스 다음, 0번째 인덱스에도 값이 업데이트 되도록.*/
	return (Q->rear + 1) % MAX_SIZE == Q->front;	
}

// 큐가 공백상태인지 확인하는 연산			
int isEmpty(Queue* Q) {
	return Q->front == Q->rear;
}	

// 큐의 rear에 요소를 추가하는 연산		
void enqueue(Queue* Q, element x) {
	if (isFull(Q)) {//큐의 자료구조가 포화상태면 더 이상 삽입 연산 진행하지 않고 종료.
		printf("[ERROR] Queue is full!!\n");
		return;
	}
	Q->rear = (Q->rear + 1) % MAX_SIZE;
	Q->queue[Q->rear] = x;
}	

// 큐에서 가장 먼저 저장된 요소 삭제 및 반환하는 연산
element dequeue(Queue* Q) {
	if (isEmpty(Q)) {//큐의 자료구조가 공백상태면 더 이상 삭제 연산 진행하지 않고 종료.
		printf("[ERROR] Queue is empty!!\n");
		return;
	}
	Q->front = (Q->front + 1) % MAX_SIZE;
	return Q->queue[Q->front];
}

// 큐에서 가장 먼저 저장된 요소를 반환하는 연산	
element peek(Queue* Q) {
	if (isEmpty(Q)) {//큐의 자료구조가 공백상태면 더 이상 삭제 연산 진행하지 않고 종료.
		printf("[ERROR] Queue is full!!\n");
		return;
	}
	return (Q->front + 1) % MAX_SIZE;
}	

// 큐의 모든 요소 출력	
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

// 큐 비우기		
void clear(Queue* Q) {
	Q->rear = Q->front;
}			
