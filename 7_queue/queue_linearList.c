#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 8 //�迭�� �ִ� ũ�� ����

typedef int element;

/*ť ����ü ����*/
typedef struct circularQueue {
	element queue[MAX_Q_SIZE];//������ ���� ���� --> �迭 ��� ť ds ����
	int front, rear;// ���� ��� ������ --> front ���� ��� ������ --> rear
}Queue;

/*ADT ����*/
Queue* create();//�ʱ�ȭ
int isFull(Queue* Q);//��ȭ���� Ȯ��
int isEmpty(Queue* Q);//������� Ȯ��
void enqueue(Queue* Q, element x);//������ ����(PUSH)
element dequeue(Queue* Q);//������ ����(POP)
element peek(Queue* Q);//������ �˻�
void display(Queue* Q);

int main(void) {
	Queue* queue;
	queue = create();//�ʱ�ȭ

	enqueue(queue, 10);
	display(queue);
	//enqueue(queue, 20);

	system("pause");
	return 0;
}

Queue* create() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));//���� �޸� �Ҵ�
	return Q;
}
/* ��ȭ���� �˻� = mod ���� --> front �� rear�� �ߺ� ȸ��
    ������� �˻� = front, rear ������ ����*/
int isFull(Queue* Q) { return (Q->rear + 1) % MAX_Q_SIZE == Q->front; }

int isEmpty(Queue* Q) { return Q->rear == Q->front; }

void enqueue(Queue* Q, element x) {
	if (isFull(Q)) {//�ڷᱸ���� �������� ���Կ��� �Ұ�
		printf("���� �ڷᱸ���� ��ȭ�����Դϴ�.\n");
	}
	Q->rear = (Q->rear + 1) % MAX_Q_SIZE;//�� ���� �� �Ҵ�
	Q->queue[Q->rear] = x;
}

element dequeue(Queue* Q) {
	/*������ �����ϸ� FRONT�� ����Ű�� ���� �� ĭ ������ �̵� 
	   REAR�� ������ �ڷᱸ�� ���� ��� ������ ���� �� ������� */
	if (isEmpty(Q)) {
		printf("���� �ڷᱸ���� ��������Դϴ�.\n");
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