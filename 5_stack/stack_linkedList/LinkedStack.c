#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

// ���齺�� ����, create a empty stack
Stack* create() {

	// Fill your code
	Stack* S = (Stack*)malloc(sizeof(Stack));//StackŸ���� �ּҰ��� �����ϴ� ������ ������ �������� �������� �Ҵ�� �޸��� ù ��° �ּҸ� ����
	S->top = NULL;//top�� NULL�̶�°� ���齺���� �ǹ�
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
	return S->top == NULL;

}

// ������ top�� ��Ҹ� �߰��ϴ� ����, operation to add elements to the top of a stack			
void push(Stack* S, element x) {

	// Fill your code
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));//1. make newNode
	newNode->data = x;//2. fill data in newNode's dataField

	newNode->link = S->top;
	S->top = newNode;

}

// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����, operations that delete and return the last stored element in the stack
element pop(Stack* S) {

	// Fill your code
	stackNode* temp;//�����ϰ��� �ϴ� ����� �ּҰ��� �����ϴ� ������ ����
	element e;
	if (isEmpty(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}

	else {
		temp = S->top;
		e = temp->data;
		S->top = temp->link;
		free(temp);
	}
	return e;
}

// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����, operations that return the last stored element in the stack			
element peek(Stack* S) {

	// Fill your code
	element e;
	if (isEmpty(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}
	else {
		return S->top->data;
	}
}

// ������ ��� ��� ���, display all elements in the stack 			
void displayStack(Stack* S) {
	stackNode* p = S->top;
	printf("STACK [ ");
	while(p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// ���� ����, empty stack
void clear(Stack* S) {
	
	// Fill your code


}				


