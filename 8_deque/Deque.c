#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

// ���鵦 ����
Deque* create() {
	Deque* DQ = (Deque*)malloc(sizeof(Deque));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}

// ���� ��ȭ�������� Ȯ���ϴ� ����					
int isFull(Deque* DQ) {
	// Fill your code
	return 0;
}

// ���� ����������� Ȯ���ϴ� ����				
int isEmpty(Deque* DQ) {
	// Fill your code
	return DQ->front == NULL;
}

// ���� �Ӹ��� ��� �߰��ϴ� ����			
void insertFront(Deque* DQ, element x) {
	// Fill your code
	/* ## DEQUE�� STACK�� QUEUE�� �������·� �糡���� ���԰� ���� ������ ��� �����ϴٴ� ���� ����!!!!*/
	dequeNode* newNode = (dequeNode*)malloc(sizeof(dequeNode));//1. ����� ����
	newNode->data = x;//2. �����Ͱ� �Ҵ�
	newNode->rlink = DQ->front;

	/* ## ������ ��� REAR�� ����� ����Ŵ
		## ���� �ƴϸ� ���� ù����� ���� ��ũ�ʵ忡 ����� �ּ� ����*/
	if (isEmpty(DQ)) {
		DQ->rear = newNode;
	}
	else {
		DQ->front->llink = newNode;
	}
	/* ## ���߿��Ḯ��Ʈ�� ù��� ���ʸ�ũ�ʵ� --> null
		## front�� ����� ����Ű����l*/
	newNode->llink = NULL;
	DQ->front = newNode;
}

// ���� ������ ��� �߰��ϴ� ����
void insertRear(Deque* DQ, element x) {
	// Fill your code
	dequeNode* newNode = (dequeNode*)malloc(sizeof(dequeNode));//1. ����� ����
	newNode->data = x;//2. �����Ͱ� �Ҵ�
	newNode->llink = DQ->rear;

	/* ## ������ ��� FRONT�� ����� ����Ŵ
		## ���� �ƴϸ� ���� ù����� ������ ��ũ�ʵ忡 ����� �ּ� ����*/
	if (isEmpty(DQ)) {
		DQ->front = newNode;
	}
	else {
		DQ->rear->rlink = newNode;
	}
	/* ## ���߿��Ḯ��Ʈ�� ù��� �����ʸ�ũ�ʵ� --> null
		## front�� ����� ����Ű����l*/
	newNode->rlink = NULL;
	DQ->rear = newNode;
}

// ���� �Ӹ��� ��ġ�� ��� ���� �� ��ȯ�ϴ� ����	
element deleteFront(Deque* DQ) {
	// Fill your code
	dequeNode* temp = DQ->front;//������ ��带 ����ų ������
	element item;//������ ����� �����͸� ������ ����
	
	if (isEmpty(DQ)) {
		printf("[ERROR] Deque is EMPTY!!\n");
		return ERROR;
	}
	/* ## 1. ��ȯ�� ������ �غ�
	    ## 2. ��� ���� ����
		## 3. �޸� ����*/
	item = DQ->front->data;
	DQ->front = DQ->front->rlink;
	free(temp);
	/* ## �ڷᱸ���� ť�� �ϳ��� ���� ��� 
			  rear���� �����ϰ� null������ �ʱ�ȭ*/
	if (DQ->front == NULL) {
		DQ->rear = NULL;
	}
	else {
		DQ->front->llink = NULL;
	}
	/*��ȯ*/
	return item;
}

// ���� ������ ��ġ�� ��� ���� �� ��ȯ�ϴ� ���� 		
element deleteRear(Deque* DQ) {
	// Fill your code
	dequeNode* temp = DQ->rear;//������ ��带 ����ų ������
	element item;//������ ����� �����͸� ������ ����

	if (isEmpty(DQ)) {
		printf("[ERROR] Deque is EMPTY!!\n");
		return ERROR;
	}
	/* ## 1. ��ȯ�� ������ �غ�
		## 2. ��� ���� ����
		## 3. �޸� ����*/
	item = DQ->rear->data;
	DQ->rear = DQ->rear->llink;
	free(temp);
	/* ## �ڷᱸ���� ť�� �ϳ��� ���� ���
			  front���� �����ϰ� null������ �ʱ�ȭ*/
	if (DQ->rear == NULL) {
		DQ->front = NULL;
	}
	else {
		DQ->rear->rlink = NULL;
	}
	/*��ȯ*/
	return item;
}

// ���� �Ӹ��� ��ġ�� ��� ��ȯ�ϴ� ����. ���� X		
element getFront(Deque* DQ) {
	// Fill your code
	if (isEmpty(DQ)) {
		printf("[ERROR] Deque is EMPTY!!\n");
		return ERROR;
	}
	return DQ->front->data;
}

// ���� ������ ��ġ�� ��� ��ȯ�ϴ� ����. ���� X		
element getRear(Deque* DQ) {
	// Fill your code
	if (isEmpty(DQ)) {
		printf("[ERROR] Deque is EMPTY!!\n");
		return ERROR;
	}
	return DQ->front->data;
}	

// ���� ��� ��� ���		
void displayDeque(Deque* DQ) {
	dequeNode* p = DQ->front;
	printf("Deque [ ");
	while(p) {
		printf("%d ", p->data);
		p = p->rlink;
	}
	printf(" ]\n");
}

// �� ���� 	
void clear(Deque* DQ) {
	dequeNode* p;
	while(DQ->front) {
		p = DQ->front;
		DQ->front = DQ->front->rlink;
		free(p);
		p = NULL;
	}
}				
