//2016211106_이현탁
#include <stdio.h>
#include <stdlib.h>
#include "dsHomework8_SLinkedList2.h"

linkedList* initList() {
	linkedList* L;//linkedList 타입의 주소를 저장하는 포인터 변수 L선언
	L = (linkedList*)malloc(sizeof(linkedList));//변수 L은 힙영역에 동적으로 생성된 메모리의 첫번째 주소값을 저장
	L->head = NULL;//헤드의 주소값이 NULL이라는건 가리키는 노드가 없다는 의미 --> 공백리스트
	L->length = 0;//공백리스트는 자료의 개수가 0개
	return L;
}

int getLength(linkedList* L) {		// SLinkedList.c와 동일

	// Fill your code
	return L->length;
}

void insert(linkedList* L, listNode* pre, element x) {	// SLinkedList.c와 동일
	listNode* newNode;//listNode 타입의 주소를 저장하는 포인터 변수 newNode선언 --> 링크드리스트에서 삽입을 할 경우 첫 번째 단계가 노드생성
	newNode = (listNode*)malloc(sizeof(listNode));//변수 newNode는 힙영역에 동적으로 생성된 메모리의 첫번째 주소값을 저장

	// Fill your code (새 노드에 데이터 저장)
	newNode->data = x;//링크드리스트에서 삽입 연산을 진행 할 경우 두번째 단계로 데이터필드에 데이터값을 할당
	
	// Fill your code (공백 리스트인 경우)
	if (L->head == NULL) {//헤드가 가리키는게 없다면
		newNode->link = NULL;//새로 생성된 노드의 링크값을 널값으로 why? 링크드리스트의 특징: 마지막 노드의 링크필드값은 null값
		L->head = newNode;//새로 생성된 노드의 주소값을 헤드에 연결
	}

	// Fill your code (첫 번째 노드로 삽입되는 경우)
	else if (pre == NULL) {
		newNode->link = L->head ;
		L->head = newNode;
	}

	// Fill your code (중간 노드로 삽입되는 경우)
	else {
		newNode->link = pre->link;//새로생성된 링크필드값에 삽입될 위치의 앞노드의 링크값으로 갱신 
		pre->link = newNode;//삽입될 위치의 앞에 있는 노드의 링크필드를 삽입될 노드의 주소값으로 갱신
	}

	// Fill your code (데이터 개수 증가)
	L->length++;
	}

void insertFirst(linkedList* L, element x) {	// SLinkedList.c와 동일
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));

	// Fill your code
	newNode->data = x;//데이터값 할당
	newNode->link = L->head;//삽입할 노드의 링크필드에 헤드가 가리키고 있는 노드의 주소값으로 갱신
	L->head = newNode;//헤드가 새로 생성된 노드를 가리키도록
	L->length++;
}

void insertLast(linkedList* L, element x) {	// SLinkedList.c와 동일
	listNode *newNode, *temp;
	newNode = (listNode*)malloc(sizeof(listNode));

	// Fill your code
	newNode->data = x;//데이터값 할당
	newNode->link = NULL;

	if (L->head == NULL) {
		L->head = newNode;
	}
	else {
		temp = L->head;//temp를 첫노드의 주소값으로 초기화
		while (temp->link != NULL) {//temp가 가리키는 노드의 링크값이 null일 때가지 반복문 수행
			temp = temp->link;//다음 노드의 주소값으로 갱신
		}
		temp->link = newNode;
	}
	L->length++;
}

int delete(linkedList* L, listNode* p) {		// SLinkedList.c와 동일
	listNode* pre;
	
	// Fill your code (공백 리스트인 경우)
	if (L->head == NULL) {
		return FALSE;
	}

	// Fill your code (삭제할 노드가 없는 경우)
	if (p == NULL) {
		return FALSE;
	}

	// Fill your code (첫 번째 노드가 삭제할 노드인 경우)
	//삭제할 노드의 주소값이 head의 주소와 같을 경우 --> head의 주소값은 삭제할 노드의 링크값으로 갱신
	//why? head가 가지고 있는 주소값은 첫노드를 가리키는 것. 따라서 헤드의 주소값에 대한 비교 연산자를 이용해
	//탐색을 한 이후, 탐색 성공하면 헤드가 가리키는 건 p의 링크값, 즉 삭제할 노드의 다음 노드를 가리키도록 구현
	if (p == L->head) {
		L->head = p->link;
		free(p);
	}

	// Fill your code (그 이외의 경우)
	pre = L->head;
	while (pre->link != p) {
		pre = pre->link;
		if (pre == NULL) {
			return FALSE;
		}
	}
	pre->link = p->link;
	free(p);

	// Fill your code (데이터 개수 감소)
	L->length--;

	return TRUE;
}

listNode* search(linkedList* L, element x) {	// SLinkedList.c와 동일
	listNode* temp = L->head;
	
	// Fill your code
	while (temp != NULL) {
		if (temp->data == x) {
			return temp;
		}
		else {
			temp = temp->link;
		}
	}

	return temp;
}

void displayList(linkedList* L) {
	listNode* p;
	printf("L=(");
	p = L->head;
	while(p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if(p != NULL) printf(", ");
	}
	printf(")\n");
}

void clear(linkedList* L) {
	listNode* p;
	while(L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

void reverse(linkedList* L) {

	// Fill your code
	listNode* p, * q, * r;

	p = L->head; /*헤드가 가지고 있는 주소값으로 초기화 --> 첫 노드를 의미*/
	q = NULL;
	while (p != NULL) { /*마지막 노드를 만날때까지 loop수행 --> 단일 연결리스트의 특징 : 끝노드의 링크값은 null*/
		r = q; /*임시저장공간*/
		q = p; /*역순작업 수행*/
		p = p->link; /*다음으로 역순할 노드 탐색*/
		q->link = r; /*연결작업 수행*/
		L->head = q; /*헤드가 첫노드를 인지하도록*/
	}

}
