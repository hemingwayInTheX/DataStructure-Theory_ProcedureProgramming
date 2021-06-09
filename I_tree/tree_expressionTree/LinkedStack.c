#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

// ���齺�� ����, create a empty stack
Stack* createStack() {

	// Fill your code
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = NULL;
	return S;
}

// ������ ��ȭ�������� Ȯ���ϴ� ����, operations to determine if the stack is full
int isFull(Stack* S) {

	// Fill your code
	return 0;
}

// ������ ����������� Ȯ���ϴ� ����, operations to determine if the stack is empty
int isEmpty(Stack* S) {

	// Fill your code
	return 	S->top == NULL;
}

// ������ top�� ��Ҹ� �߰��ϴ� ����, operations that add elements to top of stack
void push(Stack* S, element x) {

	// Fill your code
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));//1) ������
	newNode->data = x;//2) �������Ҵ�
	newNode->link = S->top;//3)����� ��ũ�ʵ� �ʱ�ȭ
	S->top = newNode;//4)top�� ����� ����Ű����
}

// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����, operations to delete and return the last stored element on the stack
element pop(Stack* S) {

	// Fill your code
	stackNode* temp;
	element item;
	if (isEmpty(S)) {//�ڷᱸ���� �����̸� ������ ��ȯ
	printf("[ERROR] Stack is EMPTY!!\n");
	return ERROR;
	}
	else {
		temp = S->top;//1) ������� �غ�
		item = temp->data;//2) ��������� �����Ͱ� ��ȯ �غ�
		S->top = temp->link;//3) ��������� ���� ��带 top�� ����Ű���� �ʱ�ȭ
		free(temp);//4) �޸� ����
	}
	return item;//5) ��ȯ
}

// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����, operations that return the last stored element in the stack
element peek(Stack* S) {

	// Fill your code
	if (isEmpty(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}
	return S->top->data;
}

// ������ ��� ��� ���, output all elements in the stack
void displayStack(Stack* S) {
	stackNode* p = S->top;
	printf("STACK [ ");
	while(p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// ���� ����, empth stack
void clear(Stack* S) {
	stackNode* p;
	while(S->top) {
		p = S->top;
		S->top = S->top->link;
		free(p);
		p = NULL;
	}
}				


