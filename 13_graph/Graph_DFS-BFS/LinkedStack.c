#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

// ���齺�� ����, create a empty stack
Stack* create() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = NULL;
	return S;
}


// ������ ����������� Ȯ���ϴ� ����, operations to determine if the stack is empty		
int isEmpty(Stack* S) {

	// Fill your code
	return S->top == NULL;//TOP�� ����Ű�°� ���ٸ� ����Ʈ�� �������

}

// ������ top�� ��Ҹ� �߰��ϴ� ����, operations that add elements to top of stack		
void push(Stack* S, element x) {

	// Fill your code
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));//1. make newNode
	newNode->data = x;//2. fill data in newNode's dataField

	newNode->link = S->top;//������� ��ũ�ʵ忡 ���� ù����� �ּҰ��� ������ ����
	S->top = newNode;//TOP�� ����带 ����Ű����

}

// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����, operations to delete and return the last stored element on the stack
element pop(Stack* S) {

	// Fill your code
	stackNode* temp;//POP�ϰ��� �ϴ� ����� �ּҰ��� �����ϴ� ������ ����
	element e;
	if (isEmpty(S)) {//����Ʈ�� �����̸� �˻�����
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}

	else {
		temp = S->top;//POP�ҷ��� ����� �ּҰ��� TEMP�� ����
		e = temp->data;//POP�ϴ� ����� �����Ͱ��� ��ȯ������ ����
		S->top = temp->link;//TOP�� POP��� ������带 ����Ű����
		free(temp);
	}
	return e;

}

// ���� ����, empty stack
void clear(Stack* S) {
	stackNode* p;
	while(S->top) {
		p = S->top;
		S->top = S->top->link;
		free(p);
		p = NULL;
	}
}				


