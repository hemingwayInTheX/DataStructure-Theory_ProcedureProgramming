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
		if (isdigit(exp[i])) {//�ǿ����ڸ� push
			setData(bNode, exp[i] - '0');//char�� ���Ҹ� ���������� ��ȯ�� �� ����
		}
		else {//1) �����ڸ� �ʿ��� ��ŭ ���ÿ��� pop
			makeRSubtree(bNode, pop(S));//2) pop�� �����ڸ� �ڽ� ���� ������ tree ����
			makeLSubtree(bNode, pop(S));
			setData(bNode, exp[i]);
		}
		push(S, bNode);//3) ������ tree�� �ٽ� push
	}
	return pop(S);//4) ������ �� ������ tree ��ȯ
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
	if(0<=x && x<=9)			// �ǿ����� ���, operand output
		printf("%d ", x);
	else						// ������ ���, operator output
		printf("%c ", x);
}

void showPrefixExp(BinTree* bt) {

	// Fill your code
	if (bt != NULL) {//��� ��������
	showNodeData(bt->data);		// ������ ���, operator output
	showPrefixExp(bt->left);		// ù ��° �ǿ����� ���, first operand output
	showPrefixExp(bt->right);	// �� ��° �ǿ����� ���, second operand output
	}
}

void showInfixExp(BinTree* bt) {
	if(bt == NULL)
		return;
	
	if(bt->left != NULL || bt->right != NULL)
		printf(" ( ");
	
	showInfixExp(bt->left);		// ù ��° �ǿ����� ���, first operand output
	showNodeData(bt->data);		// ������ ���, operator output
	showInfixExp(bt->right);	// �� ��° �ǿ����� ���, second operand output
	
	if(bt->left != NULL || bt->right != NULL)
		printf(" ) "); 
}

void showPostfixExp(BinTree* bt) {

	// Fill your code
	if (bt != NULL) {
		showPostfixExp(bt->left);		// ù ��° �ǿ����� ���, first operand output
		showPostfixExp(bt->right);	// �� ��° �ǿ����� ���, second operand output	
		showNodeData(bt->data);		// ������ ���, operator output
	}
}
