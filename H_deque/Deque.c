#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

// 공백덱 생성
Deque* create() {
	Deque* DQ = (Deque*)malloc(sizeof(Deque));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}

// 덱이 포화상태인지 확인하는 연산					
int isFull(Deque* DQ) {
	// Fill your code
	return 0;
}

// 덱이 공백상태인지 확인하는 연산				
int isEmpty(Deque* DQ) {
	// Fill your code
	return DQ->front == NULL;
}

// 덱의 머리에 요소 추가하는 연산			
void insertFront(Deque* DQ, element x) {
	// Fill your code
	/* ## DEQUE은 STACK과 QUEUE의 결합형태로 양끝에서 삽입과 삭제 연산이 모두 가능하다는 것을 염두!!!!*/
	dequeNode* newNode = (dequeNode*)malloc(sizeof(dequeNode));//1. 새노드 생성
	newNode->data = x;//2. 데이터값 할당
	newNode->rlink = DQ->front;

	/* ## 공백일 경우 REAR가 새노드 가리킴
		## 공백 아니면 기존 첫노드의 왼쪽 링크필드에 새노드 주소 저장*/
	if (isEmpty(DQ)) {
		DQ->rear = newNode;
	}
	else {
		DQ->front->llink = newNode;
	}
	/* ## 이중연결리스트의 첫노드 왼쪽링크필드 --> null
		## front가 새노드 가리키도록l*/
	newNode->llink = NULL;
	DQ->front = newNode;
}

// 덱의 꼬리에 요소 추가하는 연산
void insertRear(Deque* DQ, element x) {
	// Fill your code
	dequeNode* newNode = (dequeNode*)malloc(sizeof(dequeNode));//1. 새노드 생성
	newNode->data = x;//2. 데이터값 할당
	newNode->llink = DQ->rear;

	/* ## 공백일 경우 FRONT가 새노드 가리킴
		## 공백 아니면 기존 첫노드의 오른쪽 링크필드에 새노드 주소 저장*/
	if (isEmpty(DQ)) {
		DQ->front = newNode;
	}
	else {
		DQ->rear->rlink = newNode;
	}
	/* ## 이중연결리스트의 첫노드 오른쪽링크필드 --> null
		## front가 새노드 가리키도록l*/
	newNode->rlink = NULL;
	DQ->rear = newNode;
}

// 덱의 머리에 위치한 요소 삭제 및 반환하는 연산	
element deleteFront(Deque* DQ) {
	// Fill your code
	dequeNode* temp = DQ->front;//삭제할 노드를 가리킬 포인터
	element item;//삭제할 노드의 데이터를 저장할 공간
	
	if (isEmpty(DQ)) {
		printf("[ERROR] Deque is EMPTY!!\n");
		return ERROR;
	}
	/* ## 1. 반환할 데이터 준비
	    ## 2. 노드 연결 갱신
		## 3. 메모리 해제*/
	item = DQ->front->data;
	DQ->front = DQ->front->rlink;
	free(temp);
	/* ## 자료구조에 큐가 하나만 있을 경우 
			  rear값도 동일하게 null값으로 초기화*/
	if (DQ->front == NULL) {
		DQ->rear = NULL;
	}
	else {
		DQ->front->llink = NULL;
	}
	/*반환*/
	return item;
}

// 덱의 꼬리에 위치한 요소 삭제 및 반환하는 연산 		
element deleteRear(Deque* DQ) {
	// Fill your code
	dequeNode* temp = DQ->rear;//삭제할 노드를 가리킬 포인터
	element item;//삭제할 노드의 데이터를 저장할 공간

	if (isEmpty(DQ)) {
		printf("[ERROR] Deque is EMPTY!!\n");
		return ERROR;
	}
	/* ## 1. 반환할 데이터 준비
		## 2. 노드 연결 갱신
		## 3. 메모리 해제*/
	item = DQ->rear->data;
	DQ->rear = DQ->rear->llink;
	free(temp);
	/* ## 자료구조에 큐가 하나만 있을 경우
			  front값도 동일하게 null값으로 초기화*/
	if (DQ->rear == NULL) {
		DQ->front = NULL;
	}
	else {
		DQ->rear->rlink = NULL;
	}
	/*반환*/
	return item;
}

// 덱의 머리에 위치한 요소 반환하는 연산. 삭제 X		
element getFront(Deque* DQ) {
	// Fill your code
	if (isEmpty(DQ)) {
		printf("[ERROR] Deque is EMPTY!!\n");
		return ERROR;
	}
	return DQ->front->data;
}

// 덱의 꼬리에 위치한 요소 반환하는 연산. 삭제 X		
element getRear(Deque* DQ) {
	// Fill your code
	if (isEmpty(DQ)) {
		printf("[ERROR] Deque is EMPTY!!\n");
		return ERROR;
	}
	return DQ->front->data;
}	

// 덱의 모든 요소 출력		
void displayDeque(Deque* DQ) {
	dequeNode* p = DQ->front;
	printf("Deque [ ");
	while(p) {
		printf("%d ", p->data);
		p = p->rlink;
	}
	printf(" ]\n");
}

// 덱 비우기 	
void clear(Deque* DQ) {
	dequeNode* p;
	while(DQ->front) {
		p = DQ->front;
		DQ->front = DQ->front->rlink;
		free(p);
		p = NULL;
	}
}				
