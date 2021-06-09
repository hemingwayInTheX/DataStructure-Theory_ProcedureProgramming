#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define MAX_SIZE 100
#define ERROR 123456789
#define TRUE 1
#define FALSE 0
 
typedef int element;

// Queue를 구조체로 정의
typedef struct CircularQueue {
	element queue[MAX_SIZE];
	int front, rear;
}Queue;

Queue* create();					// 공백큐 생성
int isFull(Queue* Q);				// 큐가 포화상태인지 확인하는 연산
int isEmpty(Queue* Q);				// 큐가 공백상태인지 확인하는 연산
void enqueue(Queue* Q, element x);	// 큐의 rear에 요소를 추가하는 연산
element dequeue(Queue* Q);			// 큐에서 가장 먼저 저장된 요소 삭제 및 반환하는 연산
element peek(Queue* Q);				// 큐에서 가장 먼저 저장된 요소를 반환하는 연산
void displayQueue(Queue* Q);		// 큐의 모든 요소 출력
void clear(Queue* Q);				// 큐 비우기 

#endif


