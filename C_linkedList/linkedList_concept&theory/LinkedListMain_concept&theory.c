//2016211106_이현탁
#include <stdio.h>
#include "dsHomework7_SLinkedList.h"

int main(){
	linkedList* L;
	listNode* p;

	printf("\n(1)공백리스트 생성하기\n");

	// Fill your code
	int total = 0;
	int length;//getLength반환값 저장
	int result = 0;//deleteNode반환값 저장(TRUE OF FALSE)
	L = initList();//초기화 진행
	displayList(L);
	length = getLength(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", length);

	printf("\n(2)리스트에 10, 50 노드를 순서대로 삽입하기\n");

	// Fill your code
	p = L->head;//P의 주소값을 헤드의 주소값으로 초기화 --> P가 첫노드가 되도록

	//insert(L, p, 10);
	insertFirst(L, 10);
	insertLast(L, 50);

	displayList(L);
	length = getLength(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", length);

	printf("\n(3)리스트에 마지막에 80 노드를 추가하기\n");

	// Fill your code
	//insertLast(L, 80); //이전노드 정보 모름 --> 시간복잡도 O(N)
	p = search(L, 50);//이전노드 정보 제공해 마지막 노드 삽입 --> 시간복잡도 - O(1)
	insert(L, p, 80);
	displayList(L);
	displayList(L);
	length = getLength(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", length);

	printf("\n(4)리스트에서 50 노드 탐색하기\n");

	// Fill your code
	p = search(L, 50);
	if (p->data == 50) {
		printf("%d노드를 찾았습니다.\n", p->data);
	}
	else {
		printf("찾는 데이터가 없습니다.\n");
	}


	printf("\n(5)50 노드 뒤에 60 노드 삽입하기\n");

	// Fill your code
	p = search(L, 50);//데이터 필드로 50을 가지는 노드 탐색후 값 초기화 --> 새 노드가 생성되고 삽입할 위치를 파악하기 위함
	insert(L, p, 60);
	displayList(L);
	length = getLength(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", length);

	printf("\n(6)리스트에서 80 노드 삭제하기( node 사용 )\n");

	// Fill your code
	p = search(L, 80);//데이터 필드로 80을 가지는 노드 탐색후 값 초기화 --> 해당 노드의 주소값 갱신
	result = deleteNode(L, p);
	if (result == 1) {
		printf("노드 삭제 성공!\n");
	}
	else {
		printf("노드 삭제 실패!\n");
	}
	displayList(L);
	length = getLength(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", length);

	printf("\n(7)리스트에서 50 노드 삭제하기( element 사용 )\n");

	// Fill your code
	result = deleteData(L, 50);
	if (result == 1) {
		printf("노드 삭제 성공!\n");
	}
	else {
		printf("노드 삭제 실패!\n");
	}
	displayList(L);
	length = getLength(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", length);

	total = sum(L);
	printf("현재 저장된 데이터의 합 = %d\n", total);
	clear(L);

	return 0;
}
