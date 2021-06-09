//2016211106_이현탁
#include <stdio.h>
#include <stdlib.h>
#include "dsHomework9_SLinkedList3.h"

linkedList* initList() {
	linkedList* L;//linkedList 타입의 주소를 저장하는 포인터 변수 L선언
	L = (linkedList*)malloc(sizeof(linkedList));//변수 L은 힙영역에 동적으로 생성된 메모리의 첫번째 주소값을 저장
	L->head = NULL;//헤드의 주소값이 NULL이라는건 가리키는 노드가 없다는 의미 --> 공백리스트
	L->length = 0;//공백리스트는 자료의 개수가 0개
	//L->comp = NULL;
	return L;
}

int getLength(linkedList* L) {		// SLinkedList.c와 동일

	// Fill your code
	return L->length;

}

void displayList(linkedList* L) {
	listNode* p;
	printf("L=(");
	p = L->head;
	while(p != NULL) {
		printf("%d", p->data);
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

void setSortRule(linkedList* L, int (*comp)(element d1, element d2)){
	L->comp = comp;		// 리스트의 멤버 comp를 초기화
}

void sortInsert(linkedList* L, element x) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	
	// Fill your code (공백리스트인 경우)
	listNode* pre = L->head;
	listNode* temp = NULL;//루프 돌때 전노드 주소저장 변수
	listNode* y = NULL;
	if (L->head == NULL) {
		L->head = newNode;
		newNode->link = NULL;
	}

	// Fill your code (공백리스트가 아닌 경우 정렬 기준에 맞춰 들어가기 위한 위치 찾아서 삽입)
	//<함수 포인터의 선언> --> 함수의 주소도 포인터에 저장하고 사용 가능
	//1. how to 함수에 대한 포인터 선언? 함수 포인터가 가리킬 '원형'필요
	//ex) int(*pf)(int,int) = &get_gcd or get_gcd --> 배열의 이름이 배열의 주소값을 의미하는 것과 같이 함수의 이름을 함수 포인터 변수 pf의 주소값으로 초기화 가능
	//2. linkedList의 멤버 comp는 함수의 주소값을 저장 할 수 있는 포인터 변수
	//3. 원형함수 whoIsPrecede의 주소값으로 초기화된 comp는 원형함수의 반환값 1 혹은 0의 값을 가질 수 있다.
	//4. 인자로 첫노드의 데이터값과 새노드의 데이터값을 전달 --> 원형함수에서 비교연산을 통해 반환값 전달.
	else {
		if ((L->comp(pre->data, newNode->data)) == 1) {//기존 데이터가 새로운 값보다 작으면 --> 가장 큰 데이터가 삽입되면 무조건 첫노드로 위치
			newNode->link = pre;//새노드의 링크필드에 기존 노드(첫노드)의 주소값을 저장
			L->head = newNode;//헤드가 새노드의 주소를 가리키도록
		}
		else {
			while ((L->comp(pre->data, newNode->data)) != 1) {//기존 데이터가 새로운 값보다 작으면 ESCAPE LOOP --> 새노드의 데이터값이 비교대상 노드의 데이터값보다 클 경우를 탐색
				temp = pre;//temp에 전노드 주소 저장
				pre = pre->link;//다음 비교대상 노드 주소로 갱신
			}
			newNode->link = pre;//새노드의 데이터값이 비교대상의 데이터값보다 클 경우를 발견 --> 작은 데이터를 가지고 있는 노드의 주소값을 새노드의 링크필드로 갱신
			temp ->link = newNode;//삽입 노드 전 노드의 링크값에 새노드의 주소를 연결
		}
	}
	
	// Fill your code (데이터 개수 증가)
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

	// Fill your code (데이터 개수 감소)
	pre->link = p->link;
	free(p);
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




