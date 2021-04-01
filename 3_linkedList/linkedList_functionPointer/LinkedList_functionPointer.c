//2016211106_����Ź
#include <stdio.h>
#include <stdlib.h>
#include "dsHomework9_SLinkedList3.h"

linkedList* initList() {
	linkedList* L;//linkedList Ÿ���� �ּҸ� �����ϴ� ������ ���� L����
	L = (linkedList*)malloc(sizeof(linkedList));//���� L�� �������� �������� ������ �޸��� ù��° �ּҰ��� ����
	L->head = NULL;//����� �ּҰ��� NULL�̶�°� ����Ű�� ��尡 ���ٴ� �ǹ� --> ���鸮��Ʈ
	L->length = 0;//���鸮��Ʈ�� �ڷ��� ������ 0��
	//L->comp = NULL;
	return L;
}

int getLength(linkedList* L) {		// SLinkedList.c�� ����

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
	L->comp = comp;		// ����Ʈ�� ��� comp�� �ʱ�ȭ
}

void sortInsert(linkedList* L, element x) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	
	// Fill your code (���鸮��Ʈ�� ���)
	listNode* pre = L->head;
	listNode* temp = NULL;//���� ���� ����� �ּ����� ����
	listNode* y = NULL;
	if (L->head == NULL) {
		L->head = newNode;
		newNode->link = NULL;
	}

	// Fill your code (���鸮��Ʈ�� �ƴ� ��� ���� ���ؿ� ���� ���� ���� ��ġ ã�Ƽ� ����)
	//<�Լ� �������� ����> --> �Լ��� �ּҵ� �����Ϳ� �����ϰ� ��� ����
	//1. how to �Լ��� ���� ������ ����? �Լ� �����Ͱ� ����ų '����'�ʿ�
	//ex) int(*pf)(int,int) = &get_gcd or get_gcd --> �迭�� �̸��� �迭�� �ּҰ��� �ǹ��ϴ� �Ͱ� ���� �Լ��� �̸��� �Լ� ������ ���� pf�� �ּҰ����� �ʱ�ȭ ����
	//2. linkedList�� ��� comp�� �Լ��� �ּҰ��� ���� �� �� �ִ� ������ ����
	//3. �����Լ� whoIsPrecede�� �ּҰ����� �ʱ�ȭ�� comp�� �����Լ��� ��ȯ�� 1 Ȥ�� 0�� ���� ���� �� �ִ�.
	//4. ���ڷ� ù����� �����Ͱ��� ������� �����Ͱ��� ���� --> �����Լ����� �񱳿����� ���� ��ȯ�� ����.
	else {
		if ((L->comp(pre->data, newNode->data)) == 1) {//���� �����Ͱ� ���ο� ������ ������ --> ���� ū �����Ͱ� ���ԵǸ� ������ ù���� ��ġ
			newNode->link = pre;//������� ��ũ�ʵ忡 ���� ���(ù���)�� �ּҰ��� ����
			L->head = newNode;//��尡 ������� �ּҸ� ����Ű����
		}
		else {
			while ((L->comp(pre->data, newNode->data)) != 1) {//���� �����Ͱ� ���ο� ������ ������ ESCAPE LOOP --> ������� �����Ͱ��� �񱳴�� ����� �����Ͱ����� Ŭ ��츦 Ž��
				temp = pre;//temp�� ����� �ּ� ����
				pre = pre->link;//���� �񱳴�� ��� �ּҷ� ����
			}
			newNode->link = pre;//������� �����Ͱ��� �񱳴���� �����Ͱ����� Ŭ ��츦 �߰� --> ���� �����͸� ������ �ִ� ����� �ּҰ��� ������� ��ũ�ʵ�� ����
			temp ->link = newNode;//���� ��� �� ����� ��ũ���� ������� �ּҸ� ����
		}
	}
	
	// Fill your code (������ ���� ����)
	L->length++;

}

int delete(linkedList* L, listNode* p) {		// SLinkedList.c�� ����
	listNode* pre;
	
	// Fill your code (���� ����Ʈ�� ���)
	if (L->head == NULL) {
		return FALSE;
	}


	// Fill your code (������ ��尡 ���� ���)
	if (p == NULL) {
		return FALSE;
	}

	// Fill your code (ù ��° ��尡 ������ ����� ���)
	//������ ����� �ּҰ��� head�� �ּҿ� ���� ��� --> head�� �ּҰ��� ������ ����� ��ũ������ ����
	//why? head�� ������ �ִ� �ּҰ��� ù��带 ����Ű�� ��. ���� ����� �ּҰ��� ���� �� �����ڸ� �̿���
	//Ž���� �� ����, Ž�� �����ϸ� ��尡 ����Ű�� �� p�� ��ũ��, �� ������ ����� ���� ��带 ����Ű���� ����
	if (p == L->head) {
		L->head = p->link;
		free(p);
	}

	// Fill your code (�� �̿��� ���)
	pre = L->head;
	while (pre->link != p) {
		pre = pre->link;
		if (pre == NULL) {
			return FALSE;
		}
	}

	// Fill your code (������ ���� ����)
	pre->link = p->link;
	free(p);
	L->length--;

	return TRUE;
}

listNode* search(linkedList* L, element x) {	// SLinkedList.c�� ����
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




