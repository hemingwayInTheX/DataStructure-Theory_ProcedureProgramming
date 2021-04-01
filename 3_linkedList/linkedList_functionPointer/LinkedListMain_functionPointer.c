//2016211106_����Ź
#include <stdio.h>
#include "dsHomework9_SLinkedList3.h"

int whoIsPrecede(element d1, element d2) {
	return d1 > d2 ? 0 : 1;
}

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)���鸮��Ʈ �����ϱ�\n");

	// Fill your code
	int length;//getLength��ȯ�� ����
	int result = 0;//deleteNode��ȯ�� ����(TRUE OF FALSE)
	L = initList();//�ʱ�ȭ ����
	displayList(L);
	length = getLength(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", length);
	
	setSortRule(L, whoIsPrecede);	// ����Ʈ�� ���� ������ �Ǵ� �Լ� ���

	printf("\n(2)����Ʈ�� 10, 80, 50 ��带 �����ϵ� ������������ ������ �ϱ�\n");

	// Fill your code (sortInsert() ���� �̿�)
	p = L->head;//�ʱ�ȭ
	sortInsert(L, 10);
	displayList(L);
	sortInsert(L, 80);
	displayList(L);
	sortInsert(L, 50);
	displayList(L);
	length = getLength(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", length);
	
	printf("\n(3)����Ʈ���� 50 ��� Ž���ϱ�\n");

	// Fill your code (SLinkedListMain.c �� ����)
	p = search(L, 50);
	if (p == NULL) {
		printf("ã�� �����Ͱ� �����ϴ�.\n");
	}
	else {

		printf("%d��带 ã�ҽ��ϴ�.\n", p->data);
	}
	
	printf("\n(4)40 ��� �����ϱ�(��������)\n");

	// Fill your code (sortInsert() ���� �̿�)
	sortInsert(L, 40);
	displayList(L);
	length = getLength(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", length);
	
	printf("\n(5)����Ʈ���� 50 ��� �����ϱ�\n");

	// Fill your code (SLinkedListMain.c �� ����)
	p = search(L, 50);//50��带 �������ִ� ����� �ּҰ��� Ž��
	result = delete(L, p);
	if (result == 1) {
		printf("��� ���� ����!\n");
	}
	else {
		printf("��� ���� ����!\n");
	}
	displayList(L);
	length = getLength(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", length);
	
	clear(L);

	return 0;
}

