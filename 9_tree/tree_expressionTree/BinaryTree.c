#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// ���� ���� Ʈ�� ���� ����, blank binary tree generation operations
BinTree* createBT(){
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	if (bt != NULL) {//������ ���� ����
		bt->data = EMPTY;
		bt->left = NULL;
		bt->right = NULL;
	}
	return bt;
}

// ���� Ʈ���� ����ִ��� �˻��ϴ� ����, operations to check if the binary tree is empty
int isBTEmpty(BinTree* bt) {
	if(bt->left == NULL && bt->right == NULL && bt->data == EMPTY)
		return TRUE;
	else
		return FALSE;
}

// ���� ����Ʈ���� bt1, ������ ����Ʈ���� bt2, x���� ������ ��带 ��Ʈ�� �ϴ� ����Ʈ�� ��ȯ, returns a binary tree rooted at a node whose left subtree is bt1, whose right subtree is bt2, x
BinTree* makeBT(BinTree* bt1, BTData x, BinTree* bt2) {
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	if (bt != NULL) {
		bt->data = x;
		bt->left = bt1;
		bt->right = bt2;
	}
	return bt;
}

// bt2�� bt1�� ���� ����Ʈ���� ����, connect bt2 to the left subtree of bt1
void makeLSubtree(BinTree* bt1, BinTree* bt2) {

	// Fill your code
	bt1->left = bt2;//�Ű������� ���ʸ�ũ�ʵ忡 �ڽĳ�� ����
}

// bt2�� bt1�� ������ ����Ʈ���� ����, connect bt2 to the right subtree of bt1
void makeRSubtree(BinTree* bt1, BinTree* bt2) {

	// Fill your code
	bt1->right = bt2;//�Ű������� �����ʸ�ũ�ʵ忡 �ڽĳ�� ����
}

// bt�� ���� ����Ʈ���� ��ȯ, returns the left subtree of bt
BinTree* getLSubtree(BinTree* bt) {

	// Fill your code
	return bt->left;//�Ű������� ���� ��ũ�ʵ带 ��ȯ
}

// bt�� ������ ����Ʈ���� ��ȯ, returns the right subtree of bt
BinTree* getRSubtree(BinTree* bt) {

	// Fill your code
	return bt->right;//�Ű������� ������ ��ũ�ʵ带 ��ȯ
}

// bt�� root ��忡 x �� ����, store x value in root node of bt
void setData(BinTree* bt, BTData x) {

	// Fill your code
	bt->data = x;
}

// bt�� root�� ����� �����͸� ��ȯ, ���� ������ -1 ��ȯ, retruns data stored in bt's root, returns -1 if no value exists
BTData getData(BinTree* bt) {

	// Fill your code
	if (bt == NULL) {
		return -1;
	}
	return bt->data;
}

// bt�� ����Ű�� ��带 ��Ʈ�� �ϴ� Ʈ�� ���� �Ҹ�, destroy all trees rooted at nodes bt points to
void deleteBT(BinTree* bt) {
	if(bt == NULL)
		return;
	
	deleteBT(bt->left);
	deleteBT(bt->right);
	
	printf("tree �� ����: %d \n", bt->data);	// delete tree data:
	free(bt);
}

// ���� ��ȸ, inorder
void InorderTraverse(BinTree* bt, visitFuncPtr action) {

	// Fill your code
	/*��ȸ = ��� ��带 �� ���� �湮
	           = ��ȸ���� ������ '���'
			   = ���� ������ �湮, �ش� ��忡�� �ٸ� ���� ����Ʈ�� ������ ���� ���� ���� ��尡 
			      ���� ������ ��� �ݺ� 
			   = ���� ��ȸ --> ���ʳ�� ��ȸ - �湮 - ������ ��� ��ȸ*/
	if (bt != NULL) {
		InorderTraverse(bt->left, action);// 1) L
		action(bt->data);//2)V
		InorderTraverse(bt->right, action);// 3) R
	}
}

// ���� ��ȸ, preorder
void PreorderTraverse(BinTree* bt, visitFuncPtr action) {

	// Fill your code
	/*���� ��ȸ --> �湮 - ���ʳ�� ��ȸ - �����ʳ�� ��ȸ*/
	if(bt!=NULL){
	action(bt->data);// 1) V
	InorderTraverse(bt->left, action); //2) L
	InorderTraverse(bt->right, action);// 3) R
	}
}

// ���� ��ȸ, postorder
void PostorderTraverse(BinTree* bt, visitFuncPtr action) {

	// Fill your code
	/*���� ��ȸ --> ���ʳ�� ��ȸ - ������ ��� ��ȸ*/
	if(bt!=NULL){
	InorderTraverse(bt->left, action);// 1) L
	InorderTraverse(bt->right, action);// 2) R
	action(bt->data);//3) V
	}
}

