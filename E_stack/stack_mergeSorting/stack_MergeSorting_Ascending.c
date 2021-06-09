#include <stdio.h>
#include <stdlib.h>
#include "stack_MergeSorting_Ascending.h"

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

	// Fill your codee
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


void mergeSortedStacks(Stack* A, Stack* B) {
	Stack* C = create();/*A,B ��� ���� ���� ��Һ��� PUSH�� �ӽ� ����*/
	Stack* D = create();/*C�� TOP��Ҹ� ���ʴ�� PUSH�� TOP�� �ּҰ��� ������ ��� ���� */

	element itemA = 0;/*A���� TOP�� ����Ű�� ����*/
	element itemB = 0;/*B���� TOP�� ����Ű�� ����*/
	element itemC = 0;/*C���� TOP�� ����Ű�� ����*/
	
	/* 1) ���� A, ���� B TOP ��, ���� ��� ����C �� ����*/
	while (1) {
		itemA = peek(A);
		itemB = peek(B);

		if (itemA > itemB) {/*A�� B���� ũ�� B���� POP�ϰ� C�� PUSH*/
			itemB = pop(B);
			push(C,itemB);
			if (isEmpty(B)) {break;}/*�����̸� ESCAPE LOOP*/
			itemB = peek(B);/*POP���� ���� ���� �񱳴�� �������� PEEK*/
		}
		else if (itemA < itemB) {/*B�� A���� ũ�� A���� POP�ϰ� C�� PUSH*/
			itemA = pop(A);
			push(C, itemA);
			if (isEmpty(A)) {break;}/*�����̸� ESCAPE LOOP*/
			itemA = peek(A);/*POP���� ���� ���� �񱳴�� �������� PEEK*/
		}
	}/*LOOP1*/
	
	 /* 2) ���� ū ��Ұ� ���� A�� ���������� C�� PUSH*/
	if (!isEmpty(A)) {
		element a = pop(A);
		push(C, a);
	}
	/* 3) ���� ū ��Ұ� ���� B�� ���������� C�� PUSH*/
	else if (!isEmpty(B)) {
		element b = pop(B);
		push(C, b);
	}

	/* 4) ���� C�� TOP��Ҹ� ����D�� ���ʴ�� PUSH*/
	while (!isEmpty(C)) {
		itemC = pop(C);
		push(D, itemC);
	}
	displayStack(D);

}

// ������ ��� ��� ���, display all elements in the stack
void displayStack(Stack* S) {
	int i;
	printf("STACK [ ");
	for (i = 0; i <= S->top; i++)
		printf("%d ", S->stack[i]);
	printf(" ]\ttop: %d\n", S->top);
}

// ���� ����, empty stack
void clear(Stack* S) {

	// Fill your code
	S->top = -1;//top�� -1�� ����Ű���� �ϸ� array������ ��� ��ҵ��� �ʱ�ȭ

}

