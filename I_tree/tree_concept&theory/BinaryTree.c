#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// 공백 이진 트리 생성 연산, blank binary tree generation operations
BinTree* createBT(){
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->data = EMPTY;
	bt->left = NULL;
	bt->right = NULL;
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
	bt->data = x;
	bt->left = bt1;
	bt->right = bt2;
	return bt;
}

// bt2를 bt1의 왼쪽 서브트리로 연결, connect bt2 to the left subtree of bt1
void makeLSubtree(BinTree* bt1, BinTree* bt2) {

	// Fill your code
	bt1->left = bt2;//최상위 root의 왼쪽에 bt1연결
}

// bt2를 bt1의 오른쪽 서브트리로 연결, connect bt2 to the right subtree of bt1
void makeRSubtree(BinTree* bt1, BinTree* bt2) {

	// Fill your code
	bt1->right = bt2;// 최상위 root의 오른쪽에 bt2연결
}

// bt의 왼쪽 서브트리를 반환, returns the left subtree of bt
BinTree* getLSubtree(BinTree* bt) {

	// Fill your code
	return bt->left;
}

// bt의 오른쪽 서브트리를 반환, returns the right subtree of bt
BinTree* getRSubtree(BinTree* bt) {

	// Fill your code
	return bt->right;
}

// bt의 root 노드에 x 값 저장, store x value in root node of bt
void setData(BinTree* bt, BTData x) {

	// Fill your code
	bt->data = x;
}

// bt의 root에 저장된 데이터를 반환, 값이 없으면 -1 반환, retruns data stored in bt's root, returns -1 if no value exists
BTData getData(BinTree* bt) {

	// Fill your code
	if (bt == NULL) {//메모리에 해당 노드가 없다면 -1 반환
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
	
	printf("tree 값 삭제: %d \n", bt->data);	// delete tree data: %d 
	free(bt);
}

// 중위 순회 , inorder
void InorderTraverse(BinTree* bt, visitFuncPtr action) {

	// Fill your code
	if (bt != NULL) {
		InorderTraverse(bt->left, action);
		action(bt->data);
		InorderTraverse(bt->right, action);
	}
}

// 전위 순회, preorder
void PreorderTraverse(BinTree* bt, visitFuncPtr action) {

	// Fill your code
	if (bt != NULL) {
		action(bt->data);
		PreorderTraverse(bt->left, action);
		PreorderTraverse(bt->right, action);
	}
}

// 후위 순회, postorder
void PostorderTraverse(BinTree* bt, visitFuncPtr action) {

	// Fill your code
	if (bt != NULL) {
		PostorderTraverse(bt->left, action);
		PostorderTraverse(bt->right, action);
		action(bt->data);
	}
}

