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
		case '(':case '{':case '[':// 1. ���� �������� ��� push
			push(S, symbol);
			break;
		case ')':// 2. ������ �������� ��� pop ����, �˻� ����
			if (isEmpty(S)) { return FALSE; }// 2-a) ������ �����̸� false
			lparen = pop(S);
			if (symbol != lparen + 1) {// 2-b) ¦�� ���� ������ false --> ASCII =  '(' : 40 && ')' : 41 
				return FALSE;
			}
			break;
		case'}':case']':// 2. ������ �������� ��� pop ����, �˻� ����
			if (isEmpty(S)) { return FALSE; }// 2-a) ������ �����̸� false
			lparen = pop(S);
			if (symbol != lparen + 2) {// 2-b) ¦�� ���� ������ false --> ASCII =  '[' : 93 && ']' : 95 '{' : 123 && '}' : 125
				return FALSE;
			}
			break;
		}
	}//END LOOP

	if (!isEmpty(S)) {//������ ������� �ʴٴ°�, ��ȣ�� ¦�� ���� �ʴٴ� ��.
		return FALSE;
	}
	return TRUE;//���� ������ ��� true

}

int main() {
	int i;
	char* x[4] = {"(A - B) * C) + D", "(A - B) * C + ( D", "A [ B ( C ] )", "{A / (B - C)}"};
	
	for(i=0; i<4; i++) {
		printf("%s ", x[i]);
		if(testPair(x[i]))
			printf("-> ������ ��ȣ�� �ùٸ��� ���Ǿ����ϴ�!\n");
		else
			printf("-> ������ ��ȣ�� Ʋ�Ƚ��ϴ�!\n");
	}
	
	return 0;
}
