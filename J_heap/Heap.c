#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

// 공백 힙 생성, create a empty heap
Heap* createHeap() {
	Heap* h = (Heap*)malloc(sizeof(Heap));
	h->numOfData = 0;
	return h;
}

// 힙이 공백인지 검사, check if heap is empty			
int isEmpty(Heap* h) {
	return h->numOfData == 0 ? TRUE : FALSE;
}

// 힙의 적당한 위치에 원소 x 삽입, insert element x in appropriate position on heap
void insertHeap(Heap* h, HData x) {
	if (h->numOfData == MAX_SIZE) {
		printf("ERROR: Heap is FULL!!\n");
		return;
	}

	// Fill your code 
	/*===MAX_HEAP 삽입 연산===
	   ㄱ) 삽입할 원소를 우선순위가 가장 낮다고 가정
	   ㄴ) MAX_HEAP의 구조를 유지하기 위해 최상위 ROOT까지 비교 연산 진행*/
	int index = h->numOfData + 1;//힙 배열의 마지막 인덱스는 현재 가지고 있는 노드의 개수와 동일
	while (index != 1) {//최상위 root까지 삽입 위치 탐색
		if (x < h->heap[index / 2]) {
			h->heap[index] = h->heap[index / 2];
			index = index / 2;
		}
		else break;
	}
	h->heap[index] = x;
	h->numOfData++;
}

// 힙에서 키 값이 가장 작은 원소 삭제하고 반환, delete the element with the smallest key value from the heap and return it
HData deleteHeap(Heap* h) {
	if (isEmpty(h)) {
		printf("ERROR: Heap is EMPTY!!\n");
		return 0;
	}
	HData item = h->heap[1];//최우선순위 노드 반환
	HData lvalue = h->heap[h->numOfData];//마지막 노드를 최우선순위 노드라고 가정
	int pIdx = 1;//부모노드 
	int cIdx = 2;//자식노드

	// Fill your code
	/* == 최소힙 가정 ==
	 ㄱ) LOOP : 힙 구조 유지 위해 비교연산 수행
					  : 삭제한 노드를 채우기 위해 자식 노드간의 우선순위 비교 연산 수행  --> 우선순위 높은 자식 노드가 부모 노드로 이동
	 ㄴ) LOOP 탈출하면 우선순위가 높다고 가정한 마지막 노드가 들어갈 곳에 위치 , 삭제 노드 반환*/
	while (cIdx <= h->numOfData) {
		if (cIdx<h->numOfData && h->heap[cIdx] > h->heap[cIdx + 1]) {//자식 서브트리 비교, 오른쪽 자식노드가 우선순위 높으면 오른쪽으로 이동하도록 인덱스 갱신
			cIdx++;
		}
		if (lvalue <= h->heap[cIdx]) {//마지막노드의 값의 우선순위가 높으면(최소힙) 루프 탈출
			break;
		}
		h->heap[pIdx] = h->heap[cIdx];//우선순위 높은 자식노드는 부모노드로 이동
		pIdx = cIdx;//부모 위치, 자식 위치 갱신
		cIdx = getLChildIdx(cIdx);//왼쪽 서브트리로 이동할 경우 인덱스는 *2로 갱신
	}

	h->heap[pIdx] = lvalue;//우선순위가 높다고 가정한 마지막 노드는 힙 구조 유지를 위한 비교 연산을 통해 정해진 위치에 값 할당
	h->numOfData--;

	return item;
}

// 부모 노드의 인덱스 값 반환, returns the index value of the parent node
int getParentIdx(int idx) {
	return idx / 2;
}

// 왼쪽 자식 노드의 인덱스 값 반환, returns index value of left child node
int getLChildIdx(int idx) {
	return idx * 2;
}

// 오른쪽 자식 노드의 인덱스 값 반환, returns index value of right chlid node		
int getRChildIdx(int idx) {
	return idx * 2 + 1;
}

void displayHeap(Heap* h) {
	int i;
	for (i = 1; i <= h->numOfData; i++)
		printf("%d %d\n", i, h->heap[i]);
	printf("\n");
}
