#include <stdio.h>
#include "stack_MergeSorting_Ascending.h"

int main() {
	Stack* A;
	Stack* B;
	element item;
	int i;

	printf("\n(1) 공백 스택 생성하기\n");	// (1) To create a blank stack

	// Fill your code
	A = create();//초기화
	displayStack(A);
	B = create();//초기화
	displayStack(B);

	printf("\n(2) 스택A에 TOP이 8을 가리키도록 오름차순으로 삽입\n");	// (2) Insert 10, 20 into the stack in order

	// Fill your code
	push(A, 10);//첫 번째 PUSH
	displayStack(A);
	push(A, 9);
	displayStack(A);
	push(A, 8);
	displayStack(A);

	printf("\n(3) 스택B에 TOP이 5를 가리키도록 오름차순으로 삽입\n");	// (2) Insert 10, 20 into the stack in order

	// Fill your code
	push(B, 11);//첫 번째 PUSH
	displayStack(B);
	push(B, 7);
	displayStack(B);
	push(B, 5);
	displayStack(B);

	printf("\n(4) 스택D에 스택A와 스택B를 오름차순 정열로 병합\n");	// (2) Insert 10, 20 into the stack in order
	mergeSortedStacks(A, B);

	printf("\n(5) 스택 비우기\n");	// (8) Empty stack

	// Fill your code
	clear(A);
	displayStack(A);

	clear(B);
	displayStack(B);

	free(A);//동적메모리 해제	A = create();//초기화
	free(B);//동적메모리 해제	A = create();//초기화
	return 0;
}
