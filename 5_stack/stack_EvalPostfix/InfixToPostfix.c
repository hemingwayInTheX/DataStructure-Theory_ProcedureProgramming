#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"
#include "InfixToPostfix.h"

// 연산자, 피연산자, 괄호 -> enueration type 변환, operator, operand, parenthesis -> enueration type transform
precedence getToken(char ch) {
	//precedence로 지정된 token변수에서 ( ~ %사이가 입력되면 그에 상응하는 type내 인자 출력
	//0~8
	precedence token;
	switch(ch) {
		case '(':	token = lparen;		break;
		case ')': 	token = rparen;		break;
		case '+':	token = plus;		break;
		case '-':	token = minus;		break;
		case '*':	token = multiply;	break;
		case '/':	token = divide;		break;
		case '%':	token = mod;		break;
		case '\0':	token = eos;		break;
		default:	token = operand;
	}
	
	return token;
}

// enumeration type에 따라 연산자, 괄호 출력, operator, parenthesis display according to enumeration type
char printToken(precedence token) {
	char ch;
	switch(token) {
		case lparen:	ch = '(';	break;
		case rparen:	ch = ')';	break;
		case plus:		ch = '+';	break;
		case minus:		ch = '-';	break;
		case multiply:	ch = '*';	break;
		case divide:	ch = '/';	break;
		case mod:		ch = '%';	break; 
	}
	
	return ch;
}

// 연산자 우선순위 계산: 괄호 < +, - < *, /, %, calculate operator priority : parentheses < +, - < *, /, %
int prec(precedence symbol) {
	switch(symbol) {
		case lparen:
		case rparen:	return 0;
		case plus:
		case minus:	return 1;
		case multiply:
		case divide:
		case mod:		return 2;
	}
}

// 중위표기식 -> 후위표기식 변환 연산, inflix notation -> postfix notation transform operation
char* toPostfix(Stack* S, char* exp) {
	static char result[256] = "";
	int len = 0, n = 0;
	char symbol = exp[0];
	precedence token = getToken(symbol);		// 연산자의 종류 기록, recording the type of operator
	
	// Fill your code
	/*n = 연산자 인덱스, len = 피연산자 인덱스*/
	element getStackData = "";//peek할 스텍 데이터 저장
	precedence compareToken = 0;//peek한 데이터 enum값으로  변환(스택에 있는 데이터)
	
	while (token != 7) {
		if (token == 8) {// 1. 피연산자일 경우 그대로 출력
			result[len++] = symbol;
		}
		else {//2. 연산자일 경우 조건 확인
			if (S->top == NULL) {//2-a. 스택이 공백이면 push
				push(S, symbol);
			}
			else {//2-b. 스택이 공백이 아니면 peek연산 수행 후 우선순위 비교
				getStackData = peek(S);
				compareToken = getToken(getStackData);
				if (token > compareToken) {//2-b-ㄱ. 수식(연산자)  >  스택(연산자) = push
					push(S, symbol);
				}
				else if (token <= compareToken) {//2-b-ㄴ.  수식(연산자)  <  스택(연산자) = pop&print
					if (token == 0) {
						push(S, symbol);
					}
					else if (token == 1) {// ' ) ' 만나면 스택에서 연산자 pop -->  ' ( ' 만나면 버리고 pop한 연산자 print
						 while (1) {//MAKE LOOP
							 element ignoreData = pop(S);//  pop한 요소 저장
							 if (ignoreData == '(') {// ' ( ' 만나면 무시하고 ESCAPE LOOP
								 break;
							 }
							 else {// ' ( ' 아니면 출력 후 인덱스 증가(후위연산자) --> len 과 n 사용 혼돈했음
								 result[len++] = ignoreData;
							 }
						}
					}
					 else {// 괄호 조건 없을 경우 pop한 요소 출력 후 push
						 result[len++] = pop(S);
						 push(S, symbol);
					 }
				}
			}
		}
		symbol = exp[++n];//갱신 작업 == LOOP 한 바퀴 끝내기 전, 포인터 배열의 다음 요소값 검사 위해
		token = getToken(symbol);//우선순위 대소비교 위한 precedence타입으로 casting
	}//LOOP END

	if (token == 7) {//스택에 남아있는 데이터 모두 출력
		for (int i = len; S->top!=NULL ; i++){//스택 공백일 경우 ESCAPE LOOP
			result[i] = pop(S);
		}
	}
	return result;
}

// 후위표기식의 계산 연산, computation of postfix notaion
float evalPostfix(Stack* S, char* exp) {
	int op1, op2;
	int n = 0;
	char symbol = exp[0];
	precedence token = getToken(symbol);
	
	// Fill your code
	int inputStackData = 0;

	while (exp[n] != '\0') {
		if (token == 8) {// 1. 피연산자일 경우 스택에 push
			inputStackData = symbol - '0';
			push(S, inputStackData);
		}
		else {// 2. 연산자일 경우 필요한만큼 피연산자 pop,  조건에 맞는 연산 수행 후 다시 push
			op1 = pop(S);
			op2 = pop(S) ;
			
			switch (token){
			case 2:push(S , op1 + op2); break;
			case 3:push(S, op1 - op2); break;
			case 4:push(S, op1 * op2); break;
			case 5:push(S, op1 / op2); break;
			case 6:push(S, op1 % op2); break;
			default:break;
			}
		}
		symbol = exp[++n];//갱신 작업 == LOOP 한 바퀴 끝내기 전, 포인터 배열의 다음 요소값 검사 위해
		token = getToken(symbol);//우선순위 대소비교 위한 precedence타입으로 casting
	}
	return pop(S);
}
