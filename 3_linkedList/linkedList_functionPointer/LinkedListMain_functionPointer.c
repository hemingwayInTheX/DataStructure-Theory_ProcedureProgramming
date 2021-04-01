//2016211106_이현탁
#include <stdio.h>
#include "dsHomework9_SLinkedList3.h"

int whoIsPrecede(element d1, element d2) {
	return d1 > d2 ? 0 : 1;
}

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)공백리스트 생성하기\n");

	// Fill your code
	int length;//getLength반환값 저장
	int result = 0;//deleteNode반환값 저장(TRUE OF FALSE)
	L = initList();//초기화 진행
	displayList(L);
	length = getLength(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", length);
	
	setSortRule(L, whoIsPrecede);	// 리스트의 정렬 기준이 되는 함수 등록

	printf("\n(2)리스트에 10, 80, 50 노드를 삽입하되 내림차순으로 들어가도록 하기\n");

	// Fill your code (sortInsert() 연산 이용)
	p = L->head;//초기화
	sortInsert(L, 10);
	displayList(L);
	sortInsert(L, 80);
	displayList(L);
	sortInsert(L, 50);
	displayList(L);
	length = getLength(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", length);
	
	printf("\n(3)리스트에서 50 노드 탐색하기\n");

	// Fill your code (SLinkedListMain.c 와 동일)
	p = search(L, 50);
	if (p == NULL) {
		printf("찾는 데이터가 없습니다.\n");
	}
	else {

		printf("%d노드를 찾았습니다.\n", p->data);
	}
	
	printf("\n(4)40 노드 삽입하기(내림차순)\n");

	// Fill your code (sortInsert() 연산 이용)
	sortInsert(L, 40);
	displayList(L);
	length = getLength(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", length);
	
	printf("\n(5)리스트에서 50 노드 삭제하기\n");

	// Fill your code (SLinkedListMain.c 와 동일)
	p = search(L, 50);//50노드를 가지고있는 노드의 주소값을 탐색
	result = delete(L, p);
	if (result == 1) {
		printf("노드 삭제 성공!\n");
	}
	else {
		printf("노드 삭제 실패!\n");
	}
	displayList(L);
	length = getLength(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", length);
	
	clear(L);

	return 0;
}

