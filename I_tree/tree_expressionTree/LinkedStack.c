#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

// 공백스택 생성, create a empty stack
Stack* createStack() {

	// Fill your code
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = NULL;
	return S;
}

// 스택이 포화상태인지 확인하는 연산, operations to determine if the stack is full
int isFull(Stack* S) {

	// Fill your code
	return 0;
}

// 스택이 공백상태인지 확인하는 연산, operations to determine if the stack is empty
int isEmpty(Stack* S) {

	// Fill your code
	return 	S->top == NULL;
}

// 스택의 top에 요소를 추가하는 연산, operations that add elements to top of stack
void push(Stack* S, element x) {

	// Fill your code
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));//1) 노드생성
	newNode->data = x;//2) 데이터할당
	newNode->link = S->top;//3)새노드 링크필드 초기화
	S->top = newNode;//4)top이 새노드 가리키도록
}

// 스택에서 마지막에 저장된 요소 삭제 및 반환하는 연산, operations to delete and return the last stored element on the stack
element pop(Stack* S) {

	// Fill your code
	stackNode* temp;
	element item;
	if (isEmpty(S)) {//자료구조가 공백이면 에러값 반환
	printf("[ERROR] Stack is EMPTY!!\n");
	return ERROR;
	}
	else {
		temp = S->top;//1) 삭제노드 준비
		item = temp->data;//2) 삭제노드의 데이터값 반환 준비
		S->top = temp->link;//3) 삭제노드의 다음 노드를 top이 가리키도록 초기화
		free(temp);//4) 메모리 해제
	}
	return item;//5) 반환
}

// 스택에서 마지막에 저장된 요소를 반환하는 연산, operations that return the last stored element in the stack
element peek(Stack* S) {

	// Fill your code
	if (isEmpty(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}
	return S->top->data;
}

// 스택의 모든 요소 출력, output all elements in the stack
void displayStack(Stack* S) {
	stackNode* p = S->top;
	printf("STACK [ ");
	while(p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// 스택 비우기, empth stack
void clear(Stack* S) {
	stackNode* p;
	while(S->top) {
		p = S->top;
		S->top = S->top->link;
		free(p);
		p = NULL;
	}
}				


