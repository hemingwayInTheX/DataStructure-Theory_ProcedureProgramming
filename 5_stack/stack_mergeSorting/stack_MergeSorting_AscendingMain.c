#include <stdio.h>
#include "stack_MergeSorting_Ascending.h"

int main() {
	Stack* A;
	Stack* B;
	element item;
	int i;

	printf("\n(1) ���� ���� �����ϱ�\n");	// (1) To create a blank stack

	// Fill your code
	A = create();//�ʱ�ȭ
	displayStack(A);
	B = create();//�ʱ�ȭ
	displayStack(B);

	printf("\n(2) ����A�� TOP�� 8�� ����Ű���� ������������ ����\n");	// (2) Insert 10, 20 into the stack in order

	// Fill your code
	push(A, 10);//ù ��° PUSH
	displayStack(A);
	push(A, 9);
	displayStack(A);
	push(A, 8);
	displayStack(A);

	printf("\n(3) ����B�� TOP�� 5�� ����Ű���� ������������ ����\n");	// (2) Insert 10, 20 into the stack in order

	// Fill your code
	push(B, 11);//ù ��° PUSH
	displayStack(B);
	push(B, 7);
	displayStack(B);
	push(B, 5);
	displayStack(B);

	printf("\n(4) ����D�� ����A�� ����B�� �������� ������ ����\n");	// (2) Insert 10, 20 into the stack in order
	mergeSortedStacks(A, B);

	printf("\n(5) ���� ����\n");	// (8) Empty stack

	// Fill your code
	clear(A);
	displayStack(A);

	clear(B);
	displayStack(B);

	free(A);//�����޸� ����	A = create();//�ʱ�ȭ
	free(B);//�����޸� ����	A = create();//�ʱ�ȭ
	return 0;
}
