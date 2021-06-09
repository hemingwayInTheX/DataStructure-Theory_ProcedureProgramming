#include <stdio.h>
#include <stdlib.h>
#include "stack_MergeSorting_Ascending.h"

// 공백스택 생성, create a empty stack
Stack* create() {

	// Fill your code
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = -1;//공백상태의 stack에서 top이 가리키고 있는 데이터가 없기 때문에 -1로 초기화
	return S;
}

// 스택이 포화상태인지 확인하는 연산, operations to determine if the stack is full
int isFull(Stack* S) {

	// Fill your code
	return S->top == MAX_SIZE - 1;
}

// 스택이 공백상태인지 확인하는 연산, operations to determine if the stack is empty			
int isEmpty(Stack* S) {

	// Fill your codee
	return S->top == -1;//top이 -1을 가리킨다는건 데이터가 없다는 의미
}

// 스택의 top에 요소를 추가하는 연산, operations to add elements to the top of a stack
void push(Stack* S, element x) {

	// Fill your code
	if (isFull(S)) {//포화상태일 경우 더 이상 데이터를 삽입할 수 없음
		printf("[ERROR] Stack is FULL\n");
		return ERROR;
	}
	else {
		/*S->top += 1;
		S->stack[S->top] = x;*/
		S->stack[++(S->top)] = x;//전위연산자 --> 먼저 값 증가시키고 다음 값 할당
	}

}

// 스택에서 마지막에 저장된 요소 삭제 및 반환하는 연산, operations that delete and return the last stored element in the stack	
element pop(Stack* S) {

	// Fill your code
	if (isEmpty(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}
	else {
		/*element e = S->stack[S->top];
		S->top -= 1;*/
		return S->stack[(S->top)--];//후위연산자-->먼저 값을 반환한 다음에 TOP감소
	}
}

// 스택에서 마지막에 저장된 요소를 반환하는 연산, operations that return the last stored element in the stack
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
	Stack* C = create();/*A,B 요소 비교해 작은 요소부터 PUSH한 임시 스택*/
	Stack* D = create();/*C의 TOP요소를 차례대로 PUSH한 TOP이 최소값을 가지는 결과 스택 */

	element itemA = 0;/*A스택 TOP이 가리키는 원소*/
	element itemB = 0;/*B스택 TOP이 가리키는 원소*/
	element itemC = 0;/*C스택 TOP이 가리키는 원소*/
	
	/* 1) 스택 A, 스택 B TOP 비교, 작은 요소 스택C 에 저장*/
	while (1) {
		itemA = peek(A);
		itemB = peek(B);

		if (itemA > itemB) {/*A가 B보다 크면 B스택 POP하고 C로 PUSH*/
			itemB = pop(B);
			push(C,itemB);
			if (isEmpty(B)) {break;}/*공백이면 ESCAPE LOOP*/
			itemB = peek(B);/*POP연산 이후 다음 비교대상 갱신위해 PEEK*/
		}
		else if (itemA < itemB) {/*B가 A보다 크면 A스택 POP하고 C로 PUSH*/
			itemA = pop(A);
			push(C, itemA);
			if (isEmpty(A)) {break;}/*공백이면 ESCAPE LOOP*/
			itemA = peek(A);/*POP연산 이후 다음 비교대상 갱신위해 PEEK*/
		}
	}/*LOOP1*/
	
	 /* 2) 가장 큰 요소가 스택 A에 남아있으면 C로 PUSH*/
	if (!isEmpty(A)) {
		element a = pop(A);
		push(C, a);
	}
	/* 3) 가장 큰 요소가 스택 B에 남아있으면 C로 PUSH*/
	else if (!isEmpty(B)) {
		element b = pop(B);
		push(C, b);
	}

	/* 4) 스택 C의 TOP요소를 스택D에 차례대로 PUSH*/
	while (!isEmpty(C)) {
		itemC = pop(C);
		push(D, itemC);
	}
	displayStack(D);

}

// 스택의 모든 요소 출력, display all elements in the stack
void displayStack(Stack* S) {
	int i;
	printf("STACK [ ");
	for (i = 0; i <= S->top; i++)
		printf("%d ", S->stack[i]);
	printf(" ]\ttop: %d\n", S->top);
}

// 스택 비우기, empty stack
void clear(Stack* S) {

	// Fill your code
	S->top = -1;//top이 -1을 가리키도록 하면 array내부의 모든 요소들이 초기화

}

