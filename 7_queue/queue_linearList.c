#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 8 //배열의 최대 크기 정의

typedef int element;

/*큐 구조체 정의*/
typedef struct circularQueue {
	element queue[MAX_Q_SIZE];//데이터 저장 공간 --> 배열 기반 큐 ds 구현
	int front, rear;// 삭제 요소 포인터 --> front 삽입 요소 포인터 --> rear
}Queue;

/*ADT 정의*/
Queue* create();//초기화
int isFull(Queue* Q);//포화상태 확인
int isEmpty(Queue* Q);//공백상태 확인
void enqueue(Queue* Q, element x);//데이터 삽입(PUSH)
element dequeue(Queue* Q);//데이터 삭제(POP)
element peek(Queue* Q);//데이터 검색
void display(Queue* Q);

int main(void) {
	Queue* queue;
	queue = create();//초기화

	enqueue(queue, 10);
	display(queue);
	//enqueue(queue, 20);

	system("pause");
	return 0;
}

Queue* create() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));//동적 메모리 할당
	return Q;
}
/* 포화상태 검사 = mod 연산 --> front 와 rear의 중복 회피
    공백상태 검사 = front, rear 같으면 공백*/
int isFull(Queue* Q) { return (Q->rear + 1) % MAX_Q_SIZE == Q->front; }

int isEmpty(Queue* Q) { return Q->rear == Q->front; }

void enqueue(Queue* Q, element x) {
	if (isFull(Q)) {//자료구조가 차있으면 삽입연산 불가
		printf("현재 자료구조는 포화상태입니다.\n");
	}
	Q->rear = (Q->rear + 1) % MAX_Q_SIZE;//값 갱신 후 할당
	Q->queue[Q->rear] = x;
}

element dequeue(Queue* Q) {
	/*데이터 삭제하면 FRONT가 가리키는 공간 한 칸 앞으로 이동 
	   REAR와 만나면 자료구조 내의 모든 데이터 삭제 후 공백상태 */
	if (isEmpty(Q)) {
		printf("현재 자료구조는 공백상태입니다.\n");
	}
	Q->front = (Q->front + 1) % MAX_Q_SIZE;
	return Q->queue[Q->front];
}

void display(Queue* Q) {
	printf("QUEUE [");
	for (int i = 0; i < Q->rear; i++){
		printf("%d", Q->queue[i]);
	}
	printf("]\trear: %d\n", Q->rear);
}