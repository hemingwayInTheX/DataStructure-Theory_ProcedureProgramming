#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

// ���齺�� ����, create a empty stack
Stack* create() {
	
	// Fill your code


}

// ������ ��ȭ�������� Ȯ���ϴ� ����, operations to determine if the stack is full
int isFull(Stack* S) {

	// Fill your code
	

}

// ������ ����������� Ȯ���ϴ� ����, operations to determine if the stack is empty			
int isEmpty(Stack* S) {

	// Fill your code
	

}

// ������ top�� ��Ҹ� �߰��ϴ� ����, operations to add elements to the top of a stack
void push(Stack* S, element x) {

	// Fill your code
	

}

// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����, operations that delete and return the last stored element in the stack	
element pop(Stack* S) {

	// Fill your code
	

}

// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����, operations that return the last stored element in the stack
element peek(Stack* S) {

	// Fill your code
	

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


}				

