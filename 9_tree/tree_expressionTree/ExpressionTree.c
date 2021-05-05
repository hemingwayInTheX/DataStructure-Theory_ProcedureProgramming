#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BinaryTree.h"
#include "LinkedStack.h"

BinTree* createExpTree(char exp[]) {
	Stack* S = createStack();
	BinTree* bNode;
	int expLen = strlen(exp);
	int i;
	
	// Fill your code
	for (i = 0; i < expLen; i++) {
		bNode = createBT();
		if (isdigit(exp[i])) {//피연산자면 push
			setData(bNode, exp[i] - '0');//char형 원소를 정수형으로 변환해 값 저장
		}
		else {//1) 연산자면 필요한 만큼 스택에서 pop
			makeRSubtree(bNode, pop(S));//2) pop한 연산자를 자식 노드로 연결해 tree 구성
			makeLSubtree(bNode, pop(S));
			setData(bNode, exp[i]);
		}
		push(S, bNode);//3) 구성한 tree를 다시 push
	}
	return pop(S);//4) 수식의 끝 만나면 tree 반환
}

//int evalExpTree(BinTree* bt) {
//	int op1, op2;
//	
//	// Fill your code
//	
//	
//
//}

void showNodeData(int x) {
	if(0<=x && x<=9)			// 피연산자 출력, operand output
		printf("%d ", x);
	else						// 연산자 출력, operator output
		printf("%c ", x);
}

void showPrefixExp(BinTree* bt) {

	// Fill your code
	if (bt != NULL) {//재귀 종료조건
	showNodeData(bt->data);		// 연산자 출력, operator output
	showPrefixExp(bt->left);		// 첫 번째 피연산자 출력, first operand output
	showPrefixExp(bt->right);	// 두 번째 피연산자 출력, second operand output
	}
}

void showInfixExp(BinTree* bt) {
	if(bt == NULL)
		return;
	
	if(bt->left != NULL || bt->right != NULL)
		printf(" ( ");
	
	showInfixExp(bt->left);		// 첫 번째 피연산자 출력, first operand output
	showNodeData(bt->data);		// 연산자 출력, operator output
	showInfixExp(bt->right);	// 두 번째 피연산자 출력, second operand output
	
	if(bt->left != NULL || bt->right != NULL)
		printf(" ) "); 
}

void showPostfixExp(BinTree* bt) {

	// Fill your code
	if (bt != NULL) {
		showPostfixExp(bt->left);		// 첫 번째 피연산자 출력, first operand output
		showPostfixExp(bt->right);	// 두 번째 피연산자 출력, second operand output	
		showNodeData(bt->data);		// 연산자 출력, operator output
	}
}
