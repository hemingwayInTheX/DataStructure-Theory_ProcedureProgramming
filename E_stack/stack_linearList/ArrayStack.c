#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

// ���齺�� ����, create a empty stack
Stack* create() {
	
	// Fill your code
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = -1;//��������� stack���� top�� ����Ű�� �ִ� �����Ͱ� ���� ������ -1�� �ʱ�ȭ
	return S;
}

// ������ ��ȭ�������� Ȯ���ϴ� ����, operations to determine if the stack is full
int isFull(Stack* S) {

	// Fill your code
	return S->top == MAX_SIZE - 1;
}

// ������ ����������� Ȯ���ϴ� ����, operations to determine if the stack is empty			
int isEmpty(Stack* S) {

	// Fill your code
	return S->top == -1;//top�� -1�� ����Ų�ٴ°� �����Ͱ� ���ٴ� �ǹ�
}

// ������ top�� ��Ҹ� �߰��ϴ� ����, operations to add elements to the top of a stack
void push(Stack* S, element x) {

	// Fill your code
	if (isFull(S)) {//��ȭ������ ��� �� �̻� �����͸� ������ �� ����
		printf("[ERROR] Stack is FULL\n");
		return ERROR;
	}
	else {
		/*S->top += 1;
		S->stack[S->top] = x;*/
		S->stack[++(S->top)] = x;//���������� --> ���� �� ������Ű�� ���� �� �Ҵ�
	}

}

// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����, operations that delete and return the last stored element in the stack	
element pop(Stack* S) {

	// Fill your code
	if (isEmpty(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}
	else {
		/*element e = S->stack[S->top];
		S->top -= 1;*/
	return S->stack[(S->top)--];//����������-->���� ���� ��ȯ�� ������ TOP����
	}
}

// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����, operations that return the last stored element in the stack
element peek(Stack* S) {

	// Fill your code
	if (isEmpty(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}
	else {
		return S->stack[S->top];
	}

}

// ������ ��� ��� ���, display all elements in the stack
void displayStack(Stack* S) {
	int i;
	printf("STACK [ "); 
	for(i=0; i<=S->top; i++)
		printf("%d ", S->stack[i]);
	printf(" ]\ttop: %d\n", S->top);
}

// ���� ����, empty stack
void clear(Stack* S) {
	
	// Fill your code
	S->top = -1;//top�� -1�� ����Ű���� �ϸ� array������ ��� ��ҵ��� �ʱ�ȭ

}				

