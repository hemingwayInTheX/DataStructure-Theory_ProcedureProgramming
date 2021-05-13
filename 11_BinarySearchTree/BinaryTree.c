#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// 공백 이진 트리 생성 연산, empty binary tree generation operations
BinTree* createBT(){
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->key = EMPTY;
	bt->left = NULL;
	bt->right = NULL;
	return bt;
}

// 이진 트리가 비어있는지 검사하는 연산, operations to check if the binary tree is empty
int isBTEmpty(BinTree* bt) {
	if(bt->left == NULL && bt->right == NULL && bt->key == EMPTY)
		return TRUE;
	else
		return FALSE;
}

// 왼쪽 서브트리가 bt1, 오른쪽 서브트리가 bt2, x값을 가지는 노드를 루트로 하는 이진트리 반환, returns a binary tree rooted at a node whose left subtree is bt1, whose right subtree is bt2, x
BinTree* makeBT(BinTree* bt1, BTData x, BinTree* bt2) {
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->key = x;
	bt->left = bt1;
	bt->right = bt2;
	return bt;
}

// bt2를 bt1의 왼쪽 서브트리로 연결, connect bt2 to the left subtree of bt1
void makeLSubtree(BinTree* bt1, BinTree* bt2) {

	// Fill your code
	bt1->left = bt2;
}

// bt2를 bt1의 오른쪽 서브트리로 연결, connect bt2 to the right subtree of bt1
void makeRSubtree(BinTree* bt1, BinTree* bt2) {

	// Fill your code
	bt1->right = bt2;
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
	bt->key = x;
}

// bt의 root에 저장된 데이터를 반환, returns data stored in bt's root
BTData getData(BinTree* bt) {

	// Fill your code
	if (bt == NULL)return -1;
	else return bt->key;
}

// bt가 가리키는 노드를 루트로 하는 트리 전부 소멸, destroy all trees rooted at nodes bt points to
void deleteBT(BinTree* bt) {
	if(bt == NULL)
		return;
	
	deleteBT(bt->left);
	deleteBT(bt->right);
	
	printf("delete tree data: %d \n", bt->key);
	free(bt);
}

// 중위 순회, inorder traversal
void InorderTraverse(BinTree* bt, visitFuncPtr action) {

	// Fill your code
	if (bt != NULL) {
		InorderTraverse(bt->left, action);
		action(bt->key);
		InorderTraverse(bt->right, action);
	}

}

// 데이터 x가 저장된 노드 탐색, searching nodes where data x is stored
BinTree* searchBST(BinTree* bt, BTData x) {
	BinTree* p = bt;
	
	// Fill your code
	/* ===탐색  조건===
	 ㄱ)  탐색의 시작은 ROOT부터
	 ㄴ) Target < Root = 왼쪽 서브트리 이동
	       Target > Root = 오른쪽 서브트리 이동
	 ㄷ) 재귀적 방법 & 반복적 방법*/
	
	if (p == NULL)return NULL;//key value가 자료구조에 없으면 null 반환
	if (x == p->key)return p;//key value와 target value 일치하면 해당 노드 주소 반환 
	if (x < p->key) return searchBST(p->left, x);// key value < target value --> 왼쪽 서브트리 이동
	else return searchBST(p->right, x);// key value < target value --> 오른쪽 서브트리 이동
	
	return NULL;
}

// 데이터 x 저장, insert data x
void insertBST(BinTree* bt, BTData x) {
	BinTree* p = bt;
	BinTree* parent = NULL;	
	
	// 삽입할 노드 탐색, searching nodes to insert
	// Fill your code
	/*===BST 삽입연산 ===
	  ㄱ) 삽입할 위치 탐색 --> 탐색 실패한 위치의 부모노드 탐색(A)
	  ㄴ) 노드 생성 및 초기화
	  ㄷ) (A)와 새노드 연결*/
	while (p != NULL) {
		if (x == p->key)return;//중복된 Key value있으면 종료
		parent = p;//탐색 실패한 위치의 부모노드 정보 저장
		if (x < p->key)p = p->left;//루트보다 Key value 작으면 왼쪽 서브트리 이동
		else p = p->right;//        "  크면 오른쪽 서브트리 이동
	}

	// 삽입할 노드 생성, create node to insert
	// Fill your code
	BinTree* newNode = (BinTree*)malloc(sizeof(BinTree));
	newNode->key = x;
	newNode->left = NULL;
	newNode->right = NULL;

	// 삽입 노드 연결, connect insert node
	// Fill your code
	if (bt == NULL)//자료구조가 공백이면 최상위 루트와 새노드 연결
		bt = newNode;
	else if (newNode->key < parent->key)//새노드 Key value가 부모노드 보다 작으면 부모의 왼쪽으로 연결
		parent->left = newNode;
	else//             " 크면 부모의 오른쪽으로 연결
		parent->right = newNode;

}

// 데이터 x 노드 삭제, delete data x node
void deleteBST(BinTree* bt, BTData x) {

	// Fill your code
	
		
	// 삭제할 노드가 없는 경우, if there are no nodes to delete
	// Fill your code


	// CASE 1: 삭제할 노드의 차수가 0인 경우, CASE 1: if the node to be deleted has a degree of 0
	// Fill your code
	

	// CASE 2: 삭제할 노드의 차수가 1인 경우, CASE 2: if the node to be deleted has a degree of 1
	// Fill your code
	

	// CASE 3: 삭제할 노드의 차수가 2인 경우, CASE 3: if the node to be deleted has a degree of 2
	// Fill your code
	

}	

