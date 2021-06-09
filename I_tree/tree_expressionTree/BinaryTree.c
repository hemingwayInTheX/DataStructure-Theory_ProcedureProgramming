#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// 공백 이진 트리 생성 연산, blank binary tree generation operations
BinTree* createBT(){
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	if (bt != NULL) {//역참조 오류 방지
		bt->data = EMPTY;
		bt->left = NULL;
		bt->right = NULL;
	}
	return bt;
}

// 이진 트리가 비어있는지 검사하는 연산, operations to check if the binary tree is empty
int isBTEmpty(BinTree* bt) {
	if(bt->left == NULL && bt->right == NULL && bt->data == EMPTY)
		return TRUE;
	else
		return FALSE;
}

// 왼쪽 서브트리가 bt1, 오른쪽 서브트리가 bt2, x값을 가지는 노드를 루트로 하는 이진트리 반환, returns a binary tree rooted at a node whose left subtree is bt1, whose right subtree is bt2, x
BinTree* makeBT(BinTree* bt1, BTData x, BinTree* bt2) {
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	if (bt != NULL) {
		bt->data = x;
		bt->left = bt1;
		bt->right = bt2;
	}
	return bt;
}

// bt2를 bt1의 왼쪽 서브트리로 연결, connect bt2 to the left subtree of bt1
void makeLSubtree(BinTree* bt1, BinTree* bt2) {

	// Fill your code
	bt1->left = bt2;//매개변수의 왼쪽링크필드에 자식노드 연결
}

// bt2를 bt1의 오른쪽 서브트리로 연결, connect bt2 to the right subtree of bt1
void makeRSubtree(BinTree* bt1, BinTree* bt2) {

	// Fill your code
	bt1->right = bt2;//매개변수의 오른쪽링크필드에 자식노드 연결
}

// bt의 왼쪽 서브트리를 반환, returns the left subtree of bt
BinTree* getLSubtree(BinTree* bt) {

	// Fill your code
	return bt->left;//매개변수의 왼쪽 링크필드를 반환
}

// bt의 오른쪽 서브트리를 반환, returns the right subtree of bt
BinTree* getRSubtree(BinTree* bt) {

	// Fill your code
	return bt->right;//매개변수의 오른쪽 링크필드를 반환
}

// bt의 root 노드에 x 값 저장, store x value in root node of bt
void setData(BinTree* bt, BTData x) {

	// Fill your code
	bt->data = x;
}

// bt의 root에 저장된 데이터를 반환, 값이 없으면 -1 반환, retruns data stored in bt's root, returns -1 if no value exists
BTData getData(BinTree* bt) {

	// Fill your code
	if (bt == NULL) {
		return -1;
	}
	return bt->data;
}

// bt가 가리키는 노드를 루트로 하는 트리 전부 소멸, destroy all trees rooted at nodes bt points to
void deleteBT(BinTree* bt) {
	if(bt == NULL)
		return;
	
	deleteBT(bt->left);
	deleteBT(bt->right);
	
	printf("tree 값 삭제: %d \n", bt->data);	// delete tree data:
	free(bt);
}

// 중위 순회, inorder
void InorderTraverse(BinTree* bt, visitFuncPtr action) {

	// Fill your code
	/*순회 = 모든 노드를 한 번씩 방문
	           = 순회에서 연산은 '출력'
			   = 왼쪽 노드부터 방문, 해당 노드에게 다른 왼쪽 서브트리 있으면 간선 따라서 왼쪽 노드가 
			      없을 때까지 재귀 반복 
			   = 중위 순회 --> 왼쪽노드 순회 - 방문 - 오른쪽 노드 순회*/
	if (bt != NULL) {
		InorderTraverse(bt->left, action);// 1) L
		action(bt->data);//2)V
		InorderTraverse(bt->right, action);// 3) R
	}
}

// 전위 순회, preorder
void PreorderTraverse(BinTree* bt, visitFuncPtr action) {

	// Fill your code
	/*전위 순회 --> 방문 - 왼쪽노드 순회 - 오른쪽노드 순회*/
	if(bt!=NULL){
	action(bt->data);// 1) V
	InorderTraverse(bt->left, action); //2) L
	InorderTraverse(bt->right, action);// 3) R
	}
}

// 후위 순회, postorder
void PostorderTraverse(BinTree* bt, visitFuncPtr action) {

	// Fill your code
	/*후위 순회 --> 왼쪽노드 순회 - 오른쪽 노드 순회*/
	if(bt!=NULL){
	InorderTraverse(bt->left, action);// 1) L
	InorderTraverse(bt->right, action);// 2) R
	action(bt->data);//3) V
	}
}

