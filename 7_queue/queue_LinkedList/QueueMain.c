#include <stdio.h>
#include "LinkedQueue.h"

int main() {
	Queue* Q;
	element item;
	int i;
	
	printf("(1) 공백 큐 생성하기\n");
	Q = create();
	displayQueue(Q);
	
	printf("\n(2) 큐에 10, 20, 30을 차례로 삽입\n");
	enqueue(Q, 10);
	displayQueue(Q);
	enqueue(Q, 20);
	displayQueue(Q); 
	enqueue(Q, 30);
	displayQueue(Q);
	
	printf("\n(3) 가장 먼저 삽입된 요소를 출력\n");
	item = peek(Q);
	if(item != ERROR)
		printf("가장 먼저 삽입된 요소: %d\n", item);
	displayQueue(Q);
	
	printf("\n(4) 데이터 삭제 4번 수행\n");
	for(i=0; i<4; i++){
		item = dequeue(Q);
		if(item != ERROR) {
			printf("%d 삭제\n", item);
			displayQueue(Q);
		}
		else {
			displayQueue(Q);
			break;
		}
	}
	
	printf("\n(5) 큐 비우기\n");
	clear(Q);
	displayQueue(Q);
	
	return 0;	
}

