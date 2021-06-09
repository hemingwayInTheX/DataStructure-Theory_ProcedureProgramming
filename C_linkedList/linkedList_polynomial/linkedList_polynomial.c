//2016211106_����Ź
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
	Node* newNode = (Node*)malloc(sizeof(Node));//�� �׿� ���� ��� ����
	newNode->coef = coef;
	newNode->exp = exp;
	newNode->link = NULL;//���Ḯ��Ʈ�� Ư¡ --> ������ ����� ��ũ���� NULL

	//last ���� Ȱ�� ���� : ���������� �����Ǵ� ������ ����Ŵ���ν� �� ������ ����
	if (PL->head == NULL) {//���� ����Ʈ�� ��� --> ����� �ּҰ��� ������� �ּҰ����� �ʱ�ȭ
		PL->head = newNode;
	}
	else {
		PL->last->link = newNode;//ù ��� ���Ŀ� ������ ������ last�� ���� ����
	}
	PL->last = newNode;//last�� ����带 ����Ű���� �ʱ�ȭ

}

polyList* subPoly(polyList* A, polyList* B) {
	polyList* C = initList();//C�� ���� �ʱ�ȭ
	Node* polyA = A->head;//NodeŸ���� �ּҸ� �����ϴ� polyA�� �ּҰ��� ����� �ּҰ����� �ʱ�ȭ
	Node* polyB = B->head;//NodeŸ���� �ּҸ� �����ϴ� polyB�� �ּҰ��� ����� �ּҰ����� �ʱ�ȭ
	int sub = 0;

	// Fill your code
	while (polyA && polyB) {//polyA->link�� ȥ���ؼ��� �ȵ�. why? �˻��ؾ� �� ��带 �����ϰ� �������� ���� �� �� �ֱ� ����. --> �ش� �ݺ����� ������ ����Ʈ�� �����ϴ� ������ �ִ� ������ �˻� 
		if (polyA->exp == polyB->exp) {//������ �����ϸ� ���� ������ ��� C�� �Ҵ�
			sub = polyA->coef - (polyB->coef);
			if (sub != 0) {
				appendTerm(C, sub, polyA->exp);
			}
			polyA = polyA->link;//�˻� ��� ����
			polyB = polyB->link;
		}
		else if (polyA->exp > polyB->exp) {//A�� ������ B�� �������� Ŭ ��� A���� C�� �Ҵ�
			appendTerm(C, polyA->coef, polyA->exp);
			polyA = polyA->link;//�˻� ��� ����
		}
		else {//B�� ������ A�� �������� Ŭ ��� B���� C�� �Ҵ�
			appendTerm(C, -(polyB->coef), polyB->exp);//B�� ������ ���׿����� --> B�� A�� ���� - �������� �ۿ��� �޴� ���̹Ƿ� ������ ��쿡�� �����, ����� ��쿡�� ������
			polyB = polyB->link;//�˻� ��� ����
		}


	}
	while (polyA != NULL) {//����׿� ���� �˻�
		appendTerm(C, polyA->coef, polyA->exp);
		polyA = polyA->link;
	}

	while (polyB != NULL) {//����׿� ���� �˻�
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
