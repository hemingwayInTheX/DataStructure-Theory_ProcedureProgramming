#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// ���� ���� Ʈ�� ���� ����, empty binary tree generation operations
BinTree* createBT(){
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->key = EMPTY;
	bt->left = NULL;
	bt->right = NULL;
	return bt;
}

// ���� Ʈ���� ����ִ��� �˻��ϴ� ����, operations to check if the binary tree is empty
int isBTEmpty(BinTree* bt) {
	if(bt->left == NULL && bt->right == NULL && bt->key == EMPTY)
		return TRUE;
	else
		return FALSE;
}

// ���� ����Ʈ���� bt1, ������ ����Ʈ���� bt2, x���� ������ ��带 ��Ʈ�� �ϴ� ����Ʈ�� ��ȯ, returns a binary tree rooted at a node whose left subtree is bt1, whose right subtree is bt2, x
BinTree* makeBT(BinTree* bt1, BTData x, BinTree* bt2) {
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->key = x;
	bt->left = bt1;
	bt->right = bt2;
	return bt;
}

// bt2�� bt1�� ���� ����Ʈ���� ����, connect bt2 to the left subtree of bt1
void makeLSubtree(BinTree* bt1, BinTree* bt2) {

	// Fill your code
	bt1->left = bt2;
}

// bt2�� bt1�� ������ ����Ʈ���� ����, connect bt2 to the right subtree of bt1
void makeRSubtree(BinTree* bt1, BinTree* bt2) {

	// Fill your code
	bt1->right = bt2;
}

// bt�� ���� ����Ʈ���� ��ȯ, returns the left subtree of bt
BinTree* getLSubtree(BinTree* bt) {

	// Fill your code
	return bt->left;
}

// bt�� ������ ����Ʈ���� ��ȯ, returns the right subtree of bt
BinTree* getRSubtree(BinTree* bt) {

	// Fill your code
	return bt->right;
}

// bt�� root ��忡 x �� ����, store x value in root node of bt
void setData(BinTree* bt, BTData x) {

	// Fill your code
	bt->key = x;
}

// bt�� root�� ����� �����͸� ��ȯ, returns data stored in bt's root
BTData getData(BinTree* bt) {

	// Fill your code
	if (bt == NULL)return -1;
	else return bt->key;
}

// bt�� ����Ű�� ��带 ��Ʈ�� �ϴ� Ʈ�� ���� �Ҹ�, destroy all trees rooted at nodes bt points to
void deleteBT(BinTree* bt) {
	if(bt == NULL)
		return;
	
	deleteBT(bt->left);
	deleteBT(bt->right);
	
	printf("delete tree data: %d \n", bt->key);
	free(bt);
}

// ���� ��ȸ, inorder traversal
void InorderTraverse(BinTree* bt, visitFuncPtr action) {

	// Fill your code
	if (bt != NULL) {
		InorderTraverse(bt->left, action);
		action(bt->key);
		InorderTraverse(bt->right, action);
	}

}

// ������ x�� ����� ��� Ž��, searching nodes where data x is stored
BinTree* searchBST(BinTree* bt, BTData x) {
	BinTree* p = bt;
	
	// Fill your code
	/* ===Ž��  ����===
	 ��)  Ž���� ������ ROOT����
	 ��) Target < Root = ���� ����Ʈ�� �̵�
	       Target > Root = ������ ����Ʈ�� �̵�
	 ��) ����� ��� & �ݺ��� ���*/
	
	if (p == NULL)return NULL;//key value�� �ڷᱸ���� ������ null ��ȯ
	if (x == p->key)return p;//key value�� target value ��ġ�ϸ� �ش� ��� �ּ� ��ȯ 
	if (x < p->key) return searchBST(p->left, x);// key value < target value --> ���� ����Ʈ�� �̵�
	else return searchBST(p->right, x);// key value < target value --> ������ ����Ʈ�� �̵�
	
	return NULL;
}

// ������ x ����, insert data x
void insertBST(BinTree* bt, BTData x) {
	BinTree* p = bt;
	BinTree* parent = NULL;	
	
	// ������ ��� Ž��, searching nodes to insert
	// Fill your code
	/*===BST ���Կ��� ===
	  ��) ������ ��ġ Ž�� --> Ž�� ������ ��ġ�� �θ��� Ž��(A)
	  ��) ��� ���� �� �ʱ�ȭ
	  ��) (A)�� ����� ����*/
	while (p != NULL) {
		if (x == p->key)return;//�ߺ��� Key value������ ����
		parent = p;//Ž�� ������ ��ġ�� �θ��� ���� ����
		if (x < p->key)p = p->left;//��Ʈ���� Key value ������ ���� ����Ʈ�� �̵�
		else p = p->right;//        "  ũ�� ������ ����Ʈ�� �̵�
	}

	// ������ ��� ����, create node to insert
	// Fill your code
	BinTree* newNode = (BinTree*)malloc(sizeof(BinTree));
	newNode->key = x;
	newNode->left = NULL;
	newNode->right = NULL;

	// ���� ��� ����, connect insert node
	// Fill your code
	if (bt == NULL)//�ڷᱸ���� �����̸� �ֻ��� ��Ʈ�� ����� ����
		bt = newNode;
	else if (newNode->key < parent->key)//����� Key value�� �θ��� ���� ������ �θ��� �������� ����
		parent->left = newNode;
	else//             " ũ�� �θ��� ���������� ����
		parent->right = newNode;

}

// ������ x ��� ����, delete data x node
void deleteBST(BinTree* bt, BTData x) {

	// Fill your code
	
		
	// ������ ��尡 ���� ���, if there are no nodes to delete
	// Fill your code


	// CASE 1: ������ ����� ������ 0�� ���, CASE 1: if the node to be deleted has a degree of 0
	// Fill your code
	

	// CASE 2: ������ ����� ������ 1�� ���, CASE 2: if the node to be deleted has a degree of 1
	// Fill your code
	

	// CASE 3: ������ ����� ������ 2�� ���, CASE 3: if the node to be deleted has a degree of 2
	// Fill your code
	

}	
