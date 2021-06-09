#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"
#include "InfixToPostfix.h"

// ������, �ǿ�����, ��ȣ -> enueration type ��ȯ, operator, operand, parenthesis -> enueration type transform
precedence getToken(char ch) {
	//precedence�� ������ token�������� ( ~ %���̰� �ԷµǸ� �׿� �����ϴ� type�� ���� ���
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

// enumeration type�� ���� ������, ��ȣ ���, operator, parenthesis display according to enumeration type
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

// ������ �켱���� ���: ��ȣ < +, - < *, /, %, calculate operator priority : parentheses < +, - < *, /, %
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

// ����ǥ��� -> ����ǥ��� ��ȯ ����, inflix notation -> postfix notation transform operation
char* toPostfix(Stack* S, char* exp) {
	static char result[256] = "";
	int len = 0, n = 0;
	char symbol = exp[0];
	precedence token = getToken(symbol);		// �������� ���� ���, recording the type of operator
	
	// Fill your code
	/*n = ������ �ε���, len = �ǿ����� �ε���*/
	element getStackData = "";//peek�� ���� ������ ����
	precedence compareToken = 0;//peek�� ������ enum������  ��ȯ(���ÿ� �ִ� ������)
	
	while (token != 7) {
		if (token == 8) {// 1. �ǿ������� ��� �״�� ���
			result[len++] = symbol;
		}
		else {//2. �������� ��� ���� Ȯ��
			if (S->top == NULL) {//2-a. ������ �����̸� push
				push(S, symbol);
			}
			else {//2-b. ������ ������ �ƴϸ� peek���� ���� �� �켱���� ��
				getStackData = peek(S);
				compareToken = getToken(getStackData);
				if (token > compareToken) {//2-b-��. ����(������)  >  ����(������) = push
					push(S, symbol);
				}
				else if (token <= compareToken) {//2-b-��.  ����(������)  <  ����(������) = pop&print
					if (token == 0) {
						push(S, symbol);
					}
					else if (token == 1) {// ' ) ' ������ ���ÿ��� ������ pop -->  ' ( ' ������ ������ pop�� ������ print
						 while (1) {//MAKE LOOP
							 element ignoreData = pop(S);//  pop�� ��� ����
							 if (ignoreData == '(') {// ' ( ' ������ �����ϰ� ESCAPE LOOP
								 break;
							 }
							 else {// ' ( ' �ƴϸ� ��� �� �ε��� ����(����������) --> len �� n ��� ȥ������
								 result[len++] = ignoreData;
							 }
						}
					}
					 else {// ��ȣ ���� ���� ��� pop�� ��� ��� �� push
						 result[len++] = pop(S);
						 push(S, symbol);
					 }
				}
			}
		}
		symbol = exp[++n];//���� �۾� == LOOP �� ���� ������ ��, ������ �迭�� ���� ��Ұ� �˻� ����
		token = getToken(symbol);//�켱���� ��Һ� ���� precedenceŸ������ casting
	}//LOOP END

	if (token == 7) {//���ÿ� �����ִ� ������ ��� ���
		for (int i = len; S->top!=NULL ; i++){//���� ������ ��� ESCAPE LOOP
			result[i] = pop(S);
		}
	}
	return result;
}

// ����ǥ����� ��� ����, computation of postfix notaion
float evalPostfix(Stack* S, char* exp) {
	int op1, op2;
	int n = 0;
	char symbol = exp[0];
	precedence token = getToken(symbol);
	
	// Fill your code
	int inputStackData = 0;

	while (exp[n] != '\0') {
		if (token == 8) {// 1. �ǿ������� ��� ���ÿ� push
			inputStackData = symbol - '0';
			push(S, inputStackData);
		}
		else {// 2. �������� ��� �ʿ��Ѹ�ŭ �ǿ����� pop,  ���ǿ� �´� ���� ���� �� �ٽ� push
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
		symbol = exp[++n];//���� �۾� == LOOP �� ���� ������ ��, ������ �迭�� ���� ��Ұ� �˻� ����
		token = getToken(symbol);//�켱���� ��Һ� ���� precedenceŸ������ casting
	}
	return pop(S);
}
