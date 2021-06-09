#ifndef __DEQUE_H__
#define __DEQUE_H__

#define ERROR 123456789
#define TRUE 1
#define FALSE 0
 
typedef int element;

// Deque의 노드 구조를 구조체로 정의
typedef struct DequeNode {
	element data;
	struct DequeNode* llink;
	struct DequeNode* rlink;
}dequeNode;

// Queue의 front, rear를 표현할 구조체
typedef struct LinkedDeque {
	dequeNode *front, *rear;
}Deque; 

Deque* create();						// 공백덱 생성
int isFull(Deque* DQ);					// 덱이 포화상태인지 확인하는 연산
int isEmpty(Deque* DQ);					// 덱이 공백상태인지 확인하는 연산
void insertFront(Deque* DQ, element x);	// 덱의 머리에 요소 추가하는 연산
void insertRear(Deque* DQ, element x);	// 덱의 꼬리에 요소 추가하는 연산
element deleteFront(Deque* DQ);			// 덱의 머리에 위치한 요소 삭제 및 반환하는 연산
element deleteRear(Deque* DQ);			// 덱의 꼬리에 위치한 요소 삭제 및 반환하는 연산 
element getFront(Deque* DQ);			// 덱의 머리에 위치한 요소 반환하는 연산. 삭제 X
element getRear(Deque* DQ);				// 덱의 꼬리에 위치한 요소 반환하는 연산. 삭제 X
void displayDeque(Deque* DQ);			// 덱의 모든 요소 출력
void clear(Deque* DQ);					// 덱 비우기 

#endif




