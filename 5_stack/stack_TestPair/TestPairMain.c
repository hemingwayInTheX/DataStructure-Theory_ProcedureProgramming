#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

int testPair(char* exp) {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S = create();
	char symbol, lparen;
	int i, length = strlen(exp);

	// Fill your code
	for (i = 0; i < length; i++) {
		symbol = exp[i];
		switch (symbol) {
		case '(':case '{':case '[':// 1. 왼쪽 연산자일 경우 push
			push(S, symbol);
			break;
		case ')':// 2. 오른쪽 연산자일 경우 pop 이후, 검사 진행
			if (isEmpty(S)) { return FALSE; }// 2-a) 스택이 공백이면 false
			lparen = pop(S);
			if (symbol != lparen + 1) {// 2-b) 짝이 맞지 않으면 false --> ASCII =  '(' : 40 && ')' : 41 
				return FALSE;
			}
			break;
		case'}':case']':// 2. 오른쪽 연산자일 경우 pop 이후, 검사 진행
			if (isEmpty(S)) { return FALSE; }// 2-a) 스택이 공백이면 false
			lparen = pop(S);
			if (symbol != lparen + 2) {// 2-b) 짝이 맞지 않으면 false --> ASCII =  '[' : 93 && ']' : 95 '{' : 123 && '}' : 125
				return FALSE;
			}
			break;
		}
	}//END LOOP

	if (!isEmpty(S)) {//스택이 비어있지 않다는건, 괄호의 짝이 맞지 않다는 것.
		return FALSE;
	}
	return TRUE;//공백 스택일 경우 true

}

int main() {
	int i;
	char* x[4] = {"(A - B) * C) + D", "(A - B) * C + ( D", "A [ B ( C ] )", "{A / (B - C)}"};
	
	for(i=0; i<4; i++) {
		printf("%s ", x[i]);
		if(testPair(x[i]))
			printf("-> 수식의 괄호가 올바르게 사용되었습니다!\n");
		else
			printf("-> 수식의 괄호가 틀렸습니다!\n");
	}
	
	return 0;
}
