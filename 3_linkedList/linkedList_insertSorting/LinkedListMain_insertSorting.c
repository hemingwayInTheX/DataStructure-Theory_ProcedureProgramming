//2016211106_����Ź
#include <stdio.h>
#include "dsHomework8_SLinkedList2.h"

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)���鸮��Ʈ �����ϱ�\n");

	// Fill your code
	//char*�� �ǹ��ϴ� elementŸ������ �迭�� ���� --> �迭�� �� ��Ҵ� �ش� ���ڿ��� �ּҰ��� ������ ���ϰ� ����.
	//day[0]=�� , day[1]=ȭ ,,,,,,, ���� �޼����� ���ڷ� �迭�� throwing
	element day[] = { "��","ȭ","��","��","��","��","��"};//
	int length;//getLength��ȯ�� ����
	int result = 0;//deleteNode��ȯ�� ����(TRUE OF FALSE)
	L = initList();//�ʱ�ȭ ����
	displayList(L);
	length = getLength(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", length);
	
	printf("\n(2)����Ʈ�� ��, ȭ, �� ��带 ������� �����ϱ�\n");

	// Fill your code
	p = L->head;//P�� �ּҰ��� ����� �ּҰ����� �ʱ�ȭ --> P�� ù��尡 �ǵ���

	insertFirst(L, day[0]);
	insertLast(L, day[1]);
	insertLast(L, day[3]);

	displayList(L);
	length = getLength(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", length);

	 
	printf("\n(3)����Ʈ�� ���� �������� �� ��� ���� �ϱ�\n");

	// Fill your code
	insertLast(L, day[6]);

	displayList(L);
	length = getLength(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", length);

	printf("\n(4)ȭ ��� �ڿ� �� ��� �����ϱ�\n");

	//Fill your code
	p = search(L, day[1]);
	insert(L, p, day[2]);
	displayList(L);
	length = getLength(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", length);
	
	printf("\n(5)����Ʈ���� �� ��� Ž���ϱ�\n");

	// Fill your code
	p = search(L, day[5]);
	if (p == NULL) {
		printf("ã�� �����Ͱ� �����ϴ�.\n");
	}
	else {
		
		printf("%s��带 ã�ҽ��ϴ�.\n", p->data);
	}
	
	
	printf("\n(6)����Ʈ ������ �������� �ٲٱ�\n");

	// Fill your code
	reverse(L);
	displayList(L);
	length = getLength(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", length);

	printf("\n(7)����Ʈ���� ȭ ��� �����ϱ�\n");

	//Fill your code

	p = search(L, day[1]);//������ �ʵ�� 80�� ������ ��� Ž���� �� �ʱ�ȭ --> �ش� ����� �ּҰ� ����
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

