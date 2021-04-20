//2016211106_����Ź
#include <stdio.h>
#include "dsHomework7_SLinkedList.h"

int main(){
	linkedList* L;
	listNode* p;

	printf("\n(1)���鸮��Ʈ �����ϱ�\n");

	// Fill your code
	int total = 0;
	int length;//getLength��ȯ�� ����
	int result = 0;//deleteNode��ȯ�� ����(TRUE OF FALSE)
	L = initList();//�ʱ�ȭ ����
	displayList(L);
	length = getLength(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", length);

	printf("\n(2)����Ʈ�� 10, 50 ��带 ������� �����ϱ�\n");

	// Fill your code
	p = L->head;//P�� �ּҰ��� ����� �ּҰ����� �ʱ�ȭ --> P�� ù��尡 �ǵ���

	//insert(L, p, 10);
	insertFirst(L, 10);
	insertLast(L, 50);

	displayList(L);
	length = getLength(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", length);

	printf("\n(3)����Ʈ�� �������� 80 ��带 �߰��ϱ�\n");

	// Fill your code
	//insertLast(L, 80); //������� ���� �� --> �ð����⵵ O(N)
	p = search(L, 50);//������� ���� ������ ������ ��� ���� --> �ð����⵵ - O(1)
	insert(L, p, 80);
	displayList(L);
	displayList(L);
	length = getLength(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", length);

	printf("\n(4)����Ʈ���� 50 ��� Ž���ϱ�\n");

	// Fill your code
	p = search(L, 50);
	if (p->data == 50) {
		printf("%d��带 ã�ҽ��ϴ�.\n", p->data);
	}
	else {
		printf("ã�� �����Ͱ� �����ϴ�.\n");
	}


	printf("\n(5)50 ��� �ڿ� 60 ��� �����ϱ�\n");

	// Fill your code
	p = search(L, 50);//������ �ʵ�� 50�� ������ ��� Ž���� �� �ʱ�ȭ --> �� ��尡 �����ǰ� ������ ��ġ�� �ľ��ϱ� ����
	insert(L, p, 60);
	displayList(L);
	length = getLength(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", length);

	printf("\n(6)����Ʈ���� 80 ��� �����ϱ�( node ��� )\n");

	// Fill your code
	p = search(L, 80);//������ �ʵ�� 80�� ������ ��� Ž���� �� �ʱ�ȭ --> �ش� ����� �ּҰ� ����
	result = deleteNode(L, p);
	if (result == 1) {
		printf("��� ���� ����!\n");
	}
	else {
		printf("��� ���� ����!\n");
	}
	displayList(L);
	length = getLength(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", length);

	printf("\n(7)����Ʈ���� 50 ��� �����ϱ�( element ��� )\n");

	// Fill your code
	result = deleteData(L, 50);
	if (result == 1) {
		printf("��� ���� ����!\n");
	}
	else {
		printf("��� ���� ����!\n");
	}
	displayList(L);
	length = getLength(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", length);

	total = sum(L);
	printf("���� ����� �������� �� = %d\n", total);
	clear(L);

	return 0;
}
