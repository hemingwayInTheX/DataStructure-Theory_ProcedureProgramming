//2016211106_이현탁
#include <stdio.h>
#include <stdlib.h>
#include "linkedList_polynomial.h"


polyList* initList() {
	polyList* PL = (polyList*)malloc(sizeof(polyList));
	PL->head = NULL;
	PL->last = NULL;
	return PL;
}

void appendTerm(polyList* PL, float coef, int exp) {

	// Fill your code
	Node* newNode = (Node*)malloc(sizeof(Node));//각 항에 대한 노드 생성
	newNode->coef = coef;
	newNode->exp = exp;
	newNode->link = NULL;//연결리스트의 특징 --> 마지막 노드의 링크값은 NULL

	//last 변수 활용 이유 : 순차적으로 생성되는 노드들을 가리킴으로써 각 노드들을 연결
	if (PL->head == NULL) {//공백 리스트일 경우 --> 헤드의 주소값을 새노드의 주소값으로 초기화
		PL->head = newNode;
	}
	else {
		PL->last->link = newNode;//첫 노드 이후에 들어오는 노드들을 last를 통해 연결
	}
	PL->last = newNode;//last가 새노드를 가리키도록 초기화

}

polyList* subPoly(polyList* A, polyList* B) {
	polyList* C = initList();//C에 대한 초기화
	Node* polyA = A->head;//Node타입의 주소를 저장하는 polyA의 주소값은 헤드의 주소값으로 초기화
	Node* polyB = B->head;//Node타입의 주소를 저장하는 polyB의 주소값은 헤드의 주소값으로 초기화
	int sub = 0;

	// Fill your code
	while (polyA && polyB) {//polyA->link랑 혼동해서는 안됨. why? 검사해야 할 노드를 누락하고 루프문이 끝날 수 도 있기 때문. --> 해당 반복문의 조건은 리스트에 존재하는 노드들이 있는 곳까지 검사 
		if (polyA->exp == polyB->exp) {//차수가 동일하면 연산 수행후 결과 C에 할당
			sub = polyA->coef - (polyB->coef);
			if (sub != 0) {
				appendTerm(C, sub, polyA->exp);
			}
			polyA = polyA->link;//검사 대상 갱신
			polyB = polyB->link;
		}
		else if (polyA->exp > polyB->exp) {//A의 차수가 B의 차수보다 클 경우 A항을 C에 할당
			appendTerm(C, polyA->coef, polyA->exp);
			polyA = polyA->link;//검사 대상 갱신
		}
		else {//B의 차수가 A의 차수보다 클 경우 B항을 C에 할당
			appendTerm(C, -(polyB->coef), polyB->exp);//B의 차수에 단항연산자 --> B는 A에 의해 - 연산자의 작용을 받는 식이므로 음수일 경우에는 양수로, 양수일 경우에는 음수로
			polyB = polyB->link;//검사 대상 갱신
		}


	}
	while (polyA != NULL) {//상수항에 대한 검사
		appendTerm(C, polyA->coef, polyA->exp);
		polyA = polyA->link;
	}

	while (polyB != NULL) {//상수항에 대한 검사
		appendTerm(C, -(polyB->coef), polyB->exp);
		polyB = polyB->link;

	}

	return C;
}

void displayPoly(polyList* PL) {
	Node* p = PL->head;
	for (; p; p = p->link) {
		if (p->coef > 0)
			printf("\t+");
		else
			printf("\t");
		printf("%.0fx^%d", p->coef, p->exp);
	}
	printf("\n");
}
