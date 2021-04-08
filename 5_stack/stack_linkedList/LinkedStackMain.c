#include <stdio.h>
#include "LinkedStack.h"

int main() {
	Stack* S;
	element item;
	int i;
	
	printf("\n(1) 공백 스택 생성하기\n");	// (1) To create a empty stack

	// Fill your code
	S = create();//스택 초기화
	displayStack(S);
	
	printf("\n(2) 스택에 10, 20을 차례로 삽입\n");	// (2) Insert 10, 20 into the stack in order

	// Fill your code
	push(S, 10);//맨 처음으로 들어가는 데이터 10
	displayStack(S);
	push(S, 20);//두 번째로 들어가는 데이터 20, 10위에 쌓인다고 생각
	displayStack(S);

	printf("\n(3) 현재 top의 요소를 출력\n");	// (3) displays elements of the current top

	// Fill your code	// Elements stored in top: 
	
	item = peek(S);//TOP에 있는 요소를 반환
	printf("top에 저장된 요소 : %d\n", item);

	printf("\n(4) 스택에서 요소 삭제\n");	// (4) Deleting an element from the stack

	// Fill your code	// elimination
	element eliminationData1 = pop(S);//TOP이 가리키는 노드의 데이터를 POP1
	printf("%d 삭제\n", eliminationData1);
	displayStack(S);

	printf("\n(5) 스택에서 요소 삭제\n");	// (5) Deleting an element from the stack

	// Fill your code	// elimination
	element eliminationData2 = pop(S);//TOP이 가리키는 노드의 데이터를 POP2
	printf("%d 삭제\n", eliminationData2);
	displayStack(S);

	printf("\n(6) 스택에서 요소 삭제\n");	// (6) Deleting an element from the stack
	
	// Fill your code
	element eliminationData3 = pop(S);//TOP이 가리키는 노드의 데이터를 POP3
	//printf("%d 삭제\n", eliminationData1);
	displayStack(S);

	printf("\n(7) 스택에 1부터 10까지 자연수를 차례로 삽입\n");	// (7) Insert natural numbers from 1 to 10 into the stack in order

	// Fill your code
	for ( i = 1; i < 11; i++){//LOOP_1~10까지 노드 생성후 데이터 PUSH
		push(S, i);
	}
	displayStack(S);

	printf("\n(8) 스택 비우기\n");	// (8) Empty stack

	// Fill your code
	clear(S);
	displayStack(S);

	return 0;
}

