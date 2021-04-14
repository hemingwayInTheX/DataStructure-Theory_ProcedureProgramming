//2016211106_이현탁
#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

linkedList* initList() {
	linkedList* L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;
	return L;
}

int getLength(linkedList* L) {
	return L->length;
}


void insert(linkedList* L, listNode* pre, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));//1. 노드생성
	newNode->data = x;//2. 데이터필드에 값 할당

	// Fill your code

	newNode->rlink = pre->rlink;//새노드의 오른쪽링크에 왼쪽 노드의 오른쪽링크값 대입 --> 왼쪽 노드의 오른쪽링크는 새노드의 오른쪽 노드를 가리키기 때문
	pre->rlink = newNode;//왼쪽 노드의 오른쪽 링크에 새노드의 주소 대입 --> 왼쪽 노드와 새노드를 연결
	newNode->llink = pre;//새노드의 왼쪽 링크에 왼쪽노드 주소 대입 --> 이중 연결 리스트의 특징 : 양방향으로 연결
	//제약 이유 --> 마지막 노드에 들어올 경우와, 기존 노드들 사이에 들어올 경우를 고려 : 중간에 들어왔을 경우, 새노드의 rlink는
	//그 다음 노드를 가리키도록 해야함. 하지만 마지막 노드에 삽입될 경우에는 새노드의 링크값이 NULL이어야함
	//만약 제약이 없을 경우, 마지막 위치에 새노드가 삽입된다면 메모리에 존재하지 않는 곳에 새노드의 주소값이 할당되어 예외가 발생.
	if (newNode->rlink != NULL) {
		newNode->rlink->llink = newNode;//새노드의 다음노드(오른쪽 노드)의 왼쪽링크필드에 새노드의 주소값을 저장
	}

	L->length++;

}

void insertFirst(linkedList* L, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));//1. 노드생성
	newNode->data = x;//2. 데이터필드에 값 할당

	// Fill your code
	if (L->head == NULL) {//헤드가 가리키는게 없다면 
		newNode->llink = NULL;//새노드의 왼쪽링크값과 오른쪽링크값을 NULL값으로 --> 왼쪽링크가 NULL이라는건 첫노드를 의미
		newNode->rlink = NULL;
		L->head = newNode;//헤드값을 새노드의 주소로 초기화 ---> 새노드와 헤드를 연결
	}
	L->length++;//요소 개수 증가
}

void insertLast(linkedList* L, element x) {
	listNode* newNode, * temp;//temp는 링크필드로 NULL을 가지는 노드 탐색을 위한 변수 --> 마지막 노드 삽입 위치를 탐색해야 하기 때문
	newNode = (listNode*)malloc(sizeof(listNode));//1. 노드생성
	newNode->data = x;//2. 데이터필드에 값 할당

	// Fill your code
	temp = L->head;//temp를 첫노드의 주소값으로 초기화
	while (temp->rlink != NULL) {//temp의 링크값이 NULL만나면 ESCAPE LOOP
		temp = temp->rlink;//검사 대상 노드 갱신
	}
	newNode->rlink = NULL;//NULL값 탐지 이후 --> 새노드의 오른쪽링크는 NULL --> 링크드리스트의 특징(마지막노드의 링크필드는 NULL값이다)
	newNode->llink = temp;//새노드의 왼쪽링크는 기존의 마지막 노드의 주소와 연결
	temp->rlink = newNode;//마지막노드의 오른쪽 링크필드는 새노드의 주소와 연결 --> 이중연결리스트의 특징(양방향으로 주소값이 연결)

	L->length++;

}

int deleteNode(linkedList* L, listNode* p) {

	// Fill your code
	if (L->head == NULL) {//공백리스트일 경우 수행X
		return FALSE;
	}
	if (p == NULL) {//삭제할 노드가 없는 경우
		return FALSE;
	}
	if (p->llink == NULL) {//첫노드가 삭제될 경우
		L->head = p->rlink;//헤드값에 삭제될 노드의 오른쪽 링크필드값을 대입 --> 삭제노드의 오른쪽 링크필드는 그 다음 노드를 가리키고 있기 때문
	}
	else {
		p->llink->rlink = p->rlink;//삭제될 노드 기준으로 왼쪽 노드의 오른쪽 링크필드에 삭제될 노드의 오른쪽 링크필드값으로 치환 --> 삭제 후에도 기존의 노드들의 연결을 유지하기 위함
	}
	if (p->rlink != NULL) {//삭제노드가 마지막노드가 아닐 경우 --> rlink의 값이 NULL아니라면 
		p->rlink->llink = p->llink;
	}
	free(p);
	L->length--;
	return TRUE;

}

listNode* search(linkedList* L, element x) {
	listNode* temp = L->head;

	while (temp != NULL) {
		if (temp->data == x)
			return temp;
		else
			temp = temp->rlink;
	}
	return temp;
}

void displayList(linkedList* L) {
	listNode* p;
	printf("L=(");
	p = L->head;
	while (p != NULL) {
		printf("%d", p->data);
		p = p->rlink;
		if (p != NULL) printf(", ");
	}
	printf(")\n");
}

void swapNode(linkedList* L, listNode* M) {
	/*P,Q,R 각각 다른 노드를 가리킨다고 가정 --> P = M의 이전노드  Q = M의 다음노드  R = 두번째 노드
	   이를 활용해 별도의 변수선언 없이 SWAP기능 구현*/
	listNode* p = M->llink;
	listNode* q = M->rlink;
	listNode* r = L->head->rlink;

	L->head = M;// A)  55노드의 주소를 헤드가 가리키도록
	M->llink = NULL;//  55노드의 왼쪽 링크필드를 NULL값으로
	M->rlink = r;//         55노드가 10노드 다음노드를 가리키도록

	r->llink->llink = p;//  B)  10노드의 왼쪽 링크가 55노드 이전노드를 가리키도록
	p->rlink = r->llink;//        55노드 이전노드가 10노드를 가리키도록
	
	r->llink->rlink = q;//   C)  10노드가 55노드 다음노드를 가리키도록
	q->llink = r->llink;//          55노드 다음노드가 10노드를 가리키도록

	r->llink = M;//            D)   10노드 다음노드가 바뀐 첫노드를 가리키도록
}

void clear(linkedList* L) {
	listNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->rlink;
		free(p);
		p = NULL;
	}
}

