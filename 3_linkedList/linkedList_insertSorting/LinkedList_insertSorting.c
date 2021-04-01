//2016211106_����Ź
#include <stdio.h>
#include <stdlib.h>
#include "dsHomework8_SLinkedList2.h"

linkedList* initList() {
	linkedList* L;//linkedList Ÿ���� �ּҸ� �����ϴ� ������ ���� L����
	L = (linkedList*)malloc(sizeof(linkedList));//���� L�� �������� �������� ������ �޸��� ù��° �ּҰ��� ����
	L->head = NULL;//����� �ּҰ��� NULL�̶�°� ����Ű�� ��尡 ���ٴ� �ǹ� --> ���鸮��Ʈ
	L->length = 0;//���鸮��Ʈ�� �ڷ��� ������ 0��
	return L;
}

int getLength(linkedList* L) {		// SLinkedList.c�� ����

	// Fill your code
	return L->length;
}

void insert(linkedList* L, listNode* pre, element x) {	// SLinkedList.c�� ����
	listNode* newNode;//listNode Ÿ���� �ּҸ� �����ϴ� ������ ���� newNode���� --> ��ũ�帮��Ʈ���� ������ �� ��� ù ��° �ܰ谡 ������
	newNode = (listNode*)malloc(sizeof(listNode));//���� newNode�� �������� �������� ������ �޸��� ù��° �ּҰ��� ����

	// Fill your code (�� ��忡 ������ ����)
	newNode->data = x;//��ũ�帮��Ʈ���� ���� ������ ���� �� ��� �ι�° �ܰ�� �������ʵ忡 �����Ͱ��� �Ҵ�
	
	// Fill your code (���� ����Ʈ�� ���)
	if (L->head == NULL) {//��尡 ����Ű�°� ���ٸ�
		newNode->link = NULL;//���� ������ ����� ��ũ���� �ΰ����� why? ��ũ�帮��Ʈ�� Ư¡: ������ ����� ��ũ�ʵ尪�� null��
		L->head = newNode;//���� ������ ����� �ּҰ��� ��忡 ����
	}

	// Fill your code (ù ��° ���� ���ԵǴ� ���)
	else if (pre == NULL) {
		newNode->link = L->head ;
		L->head = newNode;
	}

	// Fill your code (�߰� ���� ���ԵǴ� ���)
	else {
		newNode->link = pre->link;//���λ����� ��ũ�ʵ尪�� ���Ե� ��ġ�� �ճ���� ��ũ������ ���� 
		pre->link = newNode;//���Ե� ��ġ�� �տ� �ִ� ����� ��ũ�ʵ带 ���Ե� ����� �ּҰ����� ����
	}

	// Fill your code (������ ���� ����)
	L->length++;
	}

void insertFirst(linkedList* L, element x) {	// SLinkedList.c�� ����
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));

	// Fill your code
	newNode->data = x;//�����Ͱ� �Ҵ�
	newNode->link = L->head;//������ ����� ��ũ�ʵ忡 ��尡 ����Ű�� �ִ� ����� �ּҰ����� ����
	L->head = newNode;//��尡 ���� ������ ��带 ����Ű����
	L->length++;
}

void insertLast(linkedList* L, element x) {	// SLinkedList.c�� ����
	listNode *newNode, *temp;
	newNode = (listNode*)malloc(sizeof(listNode));

	// Fill your code
	newNode->data = x;//�����Ͱ� �Ҵ�
	newNode->link = NULL;

	if (L->head == NULL) {
		L->head = newNode;
	}
	else {
		temp = L->head;//temp�� ù����� �ּҰ����� �ʱ�ȭ
		while (temp->link != NULL) {//temp�� ����Ű�� ����� ��ũ���� null�� ������ �ݺ��� ����
			temp = temp->link;//���� ����� �ּҰ����� ����
		}
		temp->link = newNode;
	}
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
	pre->link = p->link;
	free(p);

	// Fill your code (������ ���� ����)
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

	p = L->head; /*��尡 ������ �ִ� �ּҰ����� �ʱ�ȭ --> ù ��带 �ǹ�*/
	q = NULL;
	while (p != NULL) { /*������ ��带 ���������� loop���� --> ���� ���Ḯ��Ʈ�� Ư¡ : ������� ��ũ���� null*/
		r = q; /*�ӽ��������*/
		q = p; /*�����۾� ����*/
		p = p->link; /*�������� ������ ��� Ž��*/
		q->link = r; /*�����۾� ����*/
		L->head = q; /*��尡 ù��带 �����ϵ���*/
	}

}
