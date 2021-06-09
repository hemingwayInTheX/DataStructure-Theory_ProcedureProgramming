#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__

#define MAX_STACK_SIZE 10
#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Stack을 구조체로 정의, define stack as structure
typedef struct ArrayStack {
	element stack[MAX_STACK_SIZE];
	int top;
}Stack;

Stack* createStack();					// 공백스택 생성, create empty stack
int isFullStack(Stack* S);				// 스택이 포화상태인지 확인하는 연산, operations to determine if the stack is full
int isEmptyStack(Stack* S);				// 스택이 공백상태인지 확인하는 연산, operations to determine if the stack is empty
void push(Stack* S, element x);			// 스택의 top에 요소를 추가하는 연산, operations that add elements to top of stack
element pop(Stack* S);					// 스택에서 마지막에 저장된 요소 삭제 및 반환하는 연산, operations that delete and return the last stored element in a stack
element peek(Stack* S);					// 스택에서 마지막에 저장된 요소를 반환하는 연산, operations that return the last stored element in the stack
void displayStack(Stack* S);			// 스택의 모든 요소 출력, display all elements in the stack
void clearStack(Stack* S);				// 스택 비우기, empty stack

#endif

