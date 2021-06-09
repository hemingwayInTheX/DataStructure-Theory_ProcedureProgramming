#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

// 공백스택 생성, create a empty stack
Stack* create() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = NULL;
	return S;
}


// 스택이 공백상태인지 확인하는 연산, operations to determine if the stack is empty		
int isEmpty(Stack* S) {

	// Fill your code
	return S->top == NULL;//TOP이 가리키는게 없다면 리스트는 공백상태

}

// 스택의 top에 요소를 추가하는 연산, operations that add elements to top of stack		
void push(Stack* S, element x) {

	// Fill your code
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));//1. make newNode
	newNode->data = x;//2. fill data in newNode's dataField

	newNode->link = S->top;//새노드의 링크필드에 기존 첫노드의 주소값을 대입해 연결
	S->top = newNode;//TOP이 새노드를 가리키도록

}

// 스택에서 마지막에 저장된 요소 삭제 및 반환하는 연산, operations to delete and return the last stored element on the stack
element pop(Stack* S) {

	// Fill your code
	stackNode* temp;//POP하고자 하는 노드의 주소값을 저장하는 포인터 변수
	element e;
	if (isEmpty(S)) {//리스트가 공백이면 검사제외
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}

	else {
		temp = S->top;//POP할려는 노드의 주소값을 TEMP에 저장
		e = temp->data;//POP하는 노드의 데이터값을 반환변수에 저장
		S->top = temp->link;//TOP이 POP노드 다음노드를 가리키도록
		free(temp);
	}
	return e;

}

// 스택 비우기, empty stack
void clear(Stack* S) {
	stackNode* p;
	while(S->top) {
		p = S->top;
		S->top = S->top->link;
		free(p);
		p = NULL;
	}
}				


