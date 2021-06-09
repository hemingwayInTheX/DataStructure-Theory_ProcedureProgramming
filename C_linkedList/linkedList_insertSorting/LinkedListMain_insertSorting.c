//2016211106_이현탁
#include <stdio.h>
#include "dsHomework8_SLinkedList2.h"

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)공백리스트 생성하기\n");

	// Fill your code
	//char*를 의미하는 element타입으로 배열을 선언 --> 배열의 각 요소는 해당 문자열의 주소값을 가지고 지니고 있음.
	//day[0]=월 , day[1]=화 ,,,,,,, 연산 메서드의 인자로 배열을 throwing
	element day[] = { "월","화","수","목","금","토","일"};//
	int length;//getLength반환값 저장
	int result = 0;//deleteNode반환값 저장(TRUE OF FALSE)
	L = initList();//초기화 진행
	displayList(L);
	length = getLength(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", length);
	
	printf("\n(2)리스트에 월, 화, 목 노드를 순서대로 삽입하기\n");

	// Fill your code
	p = L->head;//P의 주소값을 헤드의 주소값으로 초기화 --> P가 첫노드가 되도록

	insertFirst(L, day[0]);
	insertLast(L, day[1]);
	insertLast(L, day[3]);

	displayList(L);
	length = getLength(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", length);

	 
	printf("\n(3)리스트의 가장 마지막에 일 노드 삽입 하기\n");

	// Fill your code
	insertLast(L, day[6]);

	displayList(L);
	length = getLength(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", length);

	printf("\n(4)화 노드 뒤에 수 노드 삽입하기\n");

	//Fill your code
	p = search(L, day[1]);
	insert(L, p, day[2]);
	displayList(L);
	length = getLength(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", length);
	
	printf("\n(5)리스트에서 토 노드 탐색하기\n");

	// Fill your code
	p = search(L, day[5]);
	if (p == NULL) {
		printf("찾는 데이터가 없습니다.\n");
	}
	else {
		
		printf("%s노드를 찾았습니다.\n", p->data);
	}
	
	
	printf("\n(6)리스트 순서를 역순으로 바꾸기\n");

	// Fill your code
	reverse(L);
	displayList(L);
	length = getLength(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", length);

	printf("\n(7)리스트에서 화 노드 삭제하기\n");

	//Fill your code

	p = search(L, day[1]);//데이터 필드로 80을 가지는 노드 탐색후 값 초기화 --> 해당 노드의 주소값 갱신
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

