#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

// 공백큐 생성
Queue* create() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

// 큐가 포화상태인지 확인하는 연산				
int isFull(Queue* Q) {
	// Fill your code
	return 0;
}

// 큐가 공백상태인지 확인하는 연산			
int isEmpty(Queue* Q) {
	// Fill your code
	return Q->front == NULL && Q->rear == NULL;
}	

// 큐의 rear에 요소를 추가하는 연산		
void enqueue(Queue* Q, element x) {
	// Fill your code
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));//노드 생성
	newNode->data = x;//데이터 값 할당
	newNode->link = NULL;//링크필드 널값으로 --> 연결 리스트의 특징

	if (isEmpty(Q)) {//공백일 경우 front,rear가 새노드 가리키도록
		Q->front = newNode;
	}
	else {
		Q->rear->link = newNode;//새노드 추가될 때마다 rear 가 가리키는 노드의 주소값 갱신
	}
	Q->rear = newNode;
}	

// 큐에서 가장 먼저 저장된 요소 삭제 및 반환하는 연산
element dequeue(Queue* Q) {
	// Fill your code
	queueNode* temp;//삭제할 노드를 가리킬 포인터
	element e;//반환값 저장

	if (isEmpty(Q)) {
		printf("[ERROR] Queue is EMPTY!!\n");
		return ERROR;
	}
	/* ## 스택의 pop과 동일
		##  1. 반환값 준비 
		##  2. front가 삭제노드의 다음 노드 가리키도록
		##  3. 메모리 해제
		###  *  분기 사용 == 자료구조에 노드가 하나 밖에 없을 경우
		###      rear의 값을 null값으로 초기화 하지 않는다면 enqueue연산
					수행 시 오류 발생.*/
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

// 큐에서 가장 먼저 저장된 요소를 반환하는 연산	
element peek(Queue* Q) {
	// Fill your code
	if (isEmpty(Q)) {
		printf("[ERROR] Queue is EMPTY!!\n");
		return ERROR;
	}
	return Q->front->data;
}	

// 큐의 모든 요소 출력	
void displayQueue(Queue* Q) {
	queueNode* p = Q->front;
	printf("Queue [ ");
	while(p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// 큐 비우기		
void clear(Queue* Q) {
	queueNode* p;
	while(Q->front) {
		p = Q->front;
		Q->front = Q->front->link;
		free(p);
		p = NULL;
	}
}			

