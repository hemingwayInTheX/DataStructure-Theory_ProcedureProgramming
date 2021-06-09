//2016211106_����Ź
#include <stdio.h>
#include <stdlib.h>
#include "dsHomework7_SLinkedList.h"

linkedList* initList() {
	linkedList* L;//linkedList Ÿ���� �ּҸ� �����ϴ� ������ ���� L����
	L = (linkedList*)malloc(sizeof(linkedList));//���� L�� �������� �������� ������ �޸��� ù��° �ּҰ��� ����
	L->head = NULL;//����� �ּҰ��� NULL�̶�°� ����Ű�� ��尡 ���ٴ� �ǹ� --> ���鸮��Ʈ
	L->length = 0;//���鸮��Ʈ�� �ڷ��� ������ 0��
	return L;
}

int getLength(linkedList* L) {

	// Fill your code
	return L->length;
}

void insert(linkedList* L, listNode* pre, element x) {
	listNode* newNode;//listNode Ÿ���� �ּҸ� �����ϴ� ������ ���� newNode���� --> ��ũ�帮��Ʈ���� ������ �� ��� ù ��° �ܰ谡 ������
	newNode = (listNode*)malloc(sizeof(listNode));//���� newNode�� �������� �������� ������ �޸��� ù��° �ּҰ��� ����

	// Fill your code (�� ��忡 ������ ����), input data to new node
	newNode->data = x;//��ũ�帮��Ʈ���� ���� ������ ���� �� ��� �ι�° �ܰ�� �������ʵ忡 �����Ͱ��� �Ҵ�

	// Fill your code (ù ��° ���� ���ԵǴ� ���), input first node
	if (L->head == NULL) {//��尡 ����Ű�°� ���ٸ�
		newNode->link = NULL;//���� ������ ����� ��ũ���� �ΰ����� why? ��ũ�帮��Ʈ�� Ư¡: ������ ����� ��ũ�ʵ尪�� null��
		L->head = newNode;//���� ������ ����� �ּҰ��� ��忡 ����
	}
	/*else if (pre == NULL) {
		newNode->link = L->head ;
		L->head = newNode;
	}*/
	// Fill your code (�߰� ���� ���ԵǴ� ���), input middle node
	else{
		newNode->link = pre->link;//���λ����� ��ũ�ʵ尪�� ���Ե� ��ġ�� �ճ���� ��ũ������ ���� 
		pre->link = newNode;//���Ե� ��ġ�� �տ� �ִ� ����� ��ũ�ʵ带 ���Ե� ����� �ּҰ����� ����
	}

	// Fill your code (������ ���� ����), increased number of data
	L->length++;

}

void insertFirst(linkedList* L, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));

	// Fill your code
	newNode->data = x;//�����Ͱ� �Ҵ�
	newNode->link = L->head;//������ ����� ��ũ�ʵ忡 ��尡 ����Ű�� �ִ� ����� �ּҰ����� ����
	L->head = newNode;//��尡 ���� ������ ��带 ����Ű����
	L->length++;

}

void insertLast(linkedList* L, element x) {
	listNode *newNode, *temp;
	newNode = (listNode*)malloc(sizeof(listNode));

	// Fill your code
	newNode->data = x;
	newNode->link = NULL;

	if (L->head == NULL) {
		L->head = newNode;
	}
	else{
		temp = L->head;//temp�� ù����� �ּҰ����� �ʱ�ȭ
		while (temp->link!=NULL){//temp�� ����Ű�� ����� ��ũ���� null�� ������ �ݺ��� ����
			temp = temp->link;//���� ����� �ּҰ����� ����
		}
		temp->link = newNode;
	}
	L->length++;

}

int deleteNode(linkedList* L, listNode* p) {
	listNode* pre;
	
	// Fill your code (���� ����Ʈ�� ���), if null list
	if (L->head == NULL) {
		return FALSE;
	}

	// Fill your code (������ ��尡 ���� ���), if 
	if (p == NULL) {
		return FALSE;
	}

	// Fill your code (ù ��° ��尡 ������ ����� ���), if first node is deleted node
	//������ ����� �ּҰ��� head�� �ּҿ� ���� ��� --> head�� �ּҰ��� ������ ����� ��ũ������ ����
	//why? head�� ������ �ִ� �ּҰ��� ù��带 ����Ű�� ��. ���� ����� �ּҰ��� ���� �� �����ڸ� �̿���
	//Ž���� �� ����, Ž�� �����ϸ� ��尡 ����Ű�� �� p�� ��ũ��, �� ������ ����� ���� ��带 ����Ű���� ����
	if (p == L->head) {
		L->head = p->link;
		free(p);
	}

	// Fill your code (�� �̿��� ���), else~
	else {
		pre = L->head;
		while (pre->link != p) {
			pre = pre->link;
			if (pre == NULL) {
				return FALSE;
			}
		}
		pre->link = p->link;
		free(p);
	}
	// Fill your code (������ ���� ����), decreased number of data
	L->length--;
	return TRUE;
}

int deleteData(linkedList* L, element x) {
	listNode* pre;

	// Fill your code (���� ����Ʈ�� ���), if null list
	pre = L->head;
	listNode* a=NULL;/*�����ϰ��� �ϴ� ����� �� ��� �ּ� ��� ����*/
	if (L->head == NULL) {
		return FALSE;
	}

	// Fill your code (������ ��尡 ���� ���), if no nodes to delete
	if (pre == NULL) {
		return FALSE;
	}
	// Fill your code (ù ��° ��尡 ������ ����� ���), if first node is deleted node
	if (pre->data == x){
		L->head = pre->link;
		free(pre);
		
	}

	// Fill your code (�� �̿��� ���), else
	//1. �����ϰ��ڴ� �����Ͱ� ����ִ� ��� Ž��(������ ã�� ������ ������ �ݺ�)
	//2. ������ Ž�� ������, ���� a���� ���� ��� ������ ��� �ּҰ��� ����
	//3. pre �ּҸ� ��������� �ּҰ��� ġȯ
	//4. free�� ���� ���� ����� �޸� ����
	else {
		while (pre->data != x) {//���� ������ ã�� ������ ������ ����
			a = pre;//����� �ּ� ����
			pre = pre->link;//���� ����� �ּҰ����� ����
			if (pre == NULL) {
				return FALSE;
			}
		}
		a->link = pre->link;//���� �������� ��ũ�ʵ�(���� ��� ������ ��带 ����Ű�� �ּ�)�� ���� ������ �տ� ��ġ�� ����� ��ũ�ʵ�� �ʱ�ȭ --> ���� ���Ŀ���
							//����Ʈ�� ���������� ���� �� �� �ֵ��� ����
		free(pre);
	}

	// Fill your code (������ ���� ����), decreased number of data
	L->length--;

	return TRUE;
}


listNode* search(linkedList* L, element x) {
	listNode* temp = L->head;
	
	// Fill your code
	while (temp != NULL) {//���鸮��Ʈ�� �۾� ���� ���ϰ� ���� Ż��
		if (temp->data == x) {//���ϴ� �� Ž�� ������ �ش� ����� �ּҰ� ��ȯ
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

int sum(linkedList* L) {
	listNode* p = L->head;
	int result = 0;

	while (p != NULL) {
		result += p->data;
		p = p->link;
	}
	return result;
}



