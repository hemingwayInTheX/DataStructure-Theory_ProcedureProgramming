//2016211106_����Ź
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
	newNode = (listNode*)malloc(sizeof(listNode));//1. ������
	newNode->data = x;//2. �������ʵ忡 �� �Ҵ�

	// Fill your code

	newNode->rlink = pre->rlink;//������� �����ʸ�ũ�� ���� ����� �����ʸ�ũ�� ���� --> ���� ����� �����ʸ�ũ�� ������� ������ ��带 ����Ű�� ����
	pre->rlink = newNode;//���� ����� ������ ��ũ�� ������� �ּ� ���� --> ���� ���� ����带 ����
	newNode->llink = pre;//������� ���� ��ũ�� ���ʳ�� �ּ� ���� --> ���� ���� ����Ʈ�� Ư¡ : ��������� ����
	//���� ���� --> ������ ��忡 ���� ����, ���� ���� ���̿� ���� ��츦 ��� : �߰��� ������ ���, ������� rlink��
	//�� ���� ��带 ����Ű���� �ؾ���. ������ ������ ��忡 ���Ե� ��쿡�� ������� ��ũ���� NULL�̾����
	//���� ������ ���� ���, ������ ��ġ�� ����尡 ���Եȴٸ� �޸𸮿� �������� �ʴ� ���� ������� �ּҰ��� �Ҵ�Ǿ� ���ܰ� �߻�.
	if (newNode->rlink != NULL) {
		newNode->rlink->llink = newNode;//������� �������(������ ���)�� ���ʸ�ũ�ʵ忡 ������� �ּҰ��� ����
	}

	L->length++;

}

void insertFirst(linkedList* L, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));//1. ������
	newNode->data = x;//2. �������ʵ忡 �� �Ҵ�

	// Fill your code
	if (L->head == NULL) {//��尡 ����Ű�°� ���ٸ� 
		newNode->llink = NULL;//������� ���ʸ�ũ���� �����ʸ�ũ���� NULL������ --> ���ʸ�ũ�� NULL�̶�°� ù��带 �ǹ�
		newNode->rlink = NULL;
		L->head = newNode;//��尪�� ������� �ּҷ� �ʱ�ȭ ---> ������ ��带 ����
	}
	L->length++;//��� ���� ����
}

void insertLast(linkedList* L, element x) {
	listNode* newNode, * temp;//temp�� ��ũ�ʵ�� NULL�� ������ ��� Ž���� ���� ���� --> ������ ��� ���� ��ġ�� Ž���ؾ� �ϱ� ����
	newNode = (listNode*)malloc(sizeof(listNode));//1. ������
	newNode->data = x;//2. �������ʵ忡 �� �Ҵ�

	// Fill your code
	temp = L->head;//temp�� ù����� �ּҰ����� �ʱ�ȭ
	while (temp->rlink != NULL) {//temp�� ��ũ���� NULL������ ESCAPE LOOP
		temp = temp->rlink;//�˻� ��� ��� ����
	}
	newNode->rlink = NULL;//NULL�� Ž�� ���� --> ������� �����ʸ�ũ�� NULL --> ��ũ�帮��Ʈ�� Ư¡(����������� ��ũ�ʵ�� NULL���̴�)
	newNode->llink = temp;//������� ���ʸ�ũ�� ������ ������ ����� �ּҿ� ����
	temp->rlink = newNode;//����������� ������ ��ũ�ʵ�� ������� �ּҿ� ���� --> ���߿��Ḯ��Ʈ�� Ư¡(��������� �ּҰ��� ����)

	L->length++;

}

int deleteNode(linkedList* L, listNode* p) {

	// Fill your code
	if (L->head == NULL) {//���鸮��Ʈ�� ��� ����X
		return FALSE;
	}
	if (p == NULL) {//������ ��尡 ���� ���
		return FALSE;
	}
	if (p->llink == NULL) {//ù��尡 ������ ���
		L->head = p->rlink;//��尪�� ������ ����� ������ ��ũ�ʵ尪�� ���� --> ��������� ������ ��ũ�ʵ�� �� ���� ��带 ����Ű�� �ֱ� ����
	}
	else {
		p->llink->rlink = p->rlink;//������ ��� �������� ���� ����� ������ ��ũ�ʵ忡 ������ ����� ������ ��ũ�ʵ尪���� ġȯ --> ���� �Ŀ��� ������ ������ ������ �����ϱ� ����
	}
	if (p->rlink != NULL) {//������尡 ��������尡 �ƴ� ��� --> rlink�� ���� NULL�ƴ϶�� 
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
	/*P,Q,R ���� �ٸ� ��带 ����Ų�ٰ� ���� --> P = M�� �������  Q = M�� �������  R = �ι�° ���
	   �̸� Ȱ���� ������ �������� ���� SWAP��� ����*/
	listNode* p = M->llink;
	listNode* q = M->rlink;
	listNode* r = L->head->rlink;

	L->head = M;// A)  55����� �ּҸ� ��尡 ����Ű����
	M->llink = NULL;//  55����� ���� ��ũ�ʵ带 NULL������
	M->rlink = r;//         55��尡 10��� ������带 ����Ű����

	r->llink->llink = p;//  B)  10����� ���� ��ũ�� 55��� ������带 ����Ű����
	p->rlink = r->llink;//        55��� ������尡 10��带 ����Ű����
	
	r->llink->rlink = q;//   C)  10��尡 55��� ������带 ����Ű����
	q->llink = r->llink;//          55��� ������尡 10��带 ����Ű����

	r->llink = M;//            D)   10��� ������尡 �ٲ� ù��带 ����Ű����
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

