#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

// ���� �� ����, create a empty heap
Heap* createHeap() {
	Heap* h = (Heap*)malloc(sizeof(Heap));
	h->numOfData = 0;
	return h;
}

// ���� �������� �˻�, check if heap is empty			
int isEmpty(Heap* h) {
	return h->numOfData == 0 ? TRUE : FALSE;
}

// ���� ������ ��ġ�� ���� x ����, insert element x in appropriate position on heap
void insertHeap(Heap* h, HData x) {
	if (h->numOfData == MAX_SIZE) {
		printf("ERROR: Heap is FULL!!\n");
		return;
	}

	// Fill your code 
	/*===MAX_HEAP ���� ����===
	   ��) ������ ���Ҹ� �켱������ ���� ���ٰ� ����
	   ��) MAX_HEAP�� ������ �����ϱ� ���� �ֻ��� ROOT���� �� ���� ����*/
	int index = h->numOfData + 1;//�� �迭�� ������ �ε����� ���� ������ �ִ� ����� ������ ����
	while (index != 1) {//�ֻ��� root���� ���� ��ġ Ž��
		if (x < h->heap[index / 2]) {
			h->heap[index] = h->heap[index / 2];
			index = index / 2;
		}
		else break;
	}
	h->heap[index] = x;
	h->numOfData++;
}

// ������ Ű ���� ���� ���� ���� �����ϰ� ��ȯ, delete the element with the smallest key value from the heap and return it
HData deleteHeap(Heap* h) {
	if (isEmpty(h)) {
		printf("ERROR: Heap is EMPTY!!\n");
		return 0;
	}
	HData item = h->heap[1];//�ֿ켱���� ��� ��ȯ
	HData lvalue = h->heap[h->numOfData];//������ ��带 �ֿ켱���� ����� ����
	int pIdx = 1;//�θ��� 
	int cIdx = 2;//�ڽĳ��

	// Fill your code
	/* == �ּ��� ���� ==
	 ��) LOOP : �� ���� ���� ���� �񱳿��� ����
					  : ������ ��带 ä��� ���� �ڽ� ��尣�� �켱���� �� ���� ����  --> �켱���� ���� �ڽ� ��尡 �θ� ���� �̵�
	 ��) LOOP Ż���ϸ� �켱������ ���ٰ� ������ ������ ��尡 �� ���� ��ġ , ���� ��� ��ȯ*/
	while (cIdx <= h->numOfData) {
		if (cIdx<h->numOfData && h->heap[cIdx] > h->heap[cIdx + 1]) {//�ڽ� ����Ʈ�� ��, ������ �ڽĳ�尡 �켱���� ������ ���������� �̵��ϵ��� �ε��� ����
			cIdx++;
		}
		if (lvalue <= h->heap[cIdx]) {//����������� ���� �켱������ ������(�ּ���) ���� Ż��
			break;
		}
		h->heap[pIdx] = h->heap[cIdx];//�켱���� ���� �ڽĳ��� �θ���� �̵�
		pIdx = cIdx;//�θ� ��ġ, �ڽ� ��ġ ����
		cIdx = getLChildIdx(cIdx);//���� ����Ʈ���� �̵��� ��� �ε����� *2�� ����
	}

	h->heap[pIdx] = lvalue;//�켱������ ���ٰ� ������ ������ ���� �� ���� ������ ���� �� ������ ���� ������ ��ġ�� �� �Ҵ�
	h->numOfData--;

	return item;
}

// �θ� ����� �ε��� �� ��ȯ, returns the index value of the parent node
int getParentIdx(int idx) {
	return idx / 2;
}

// ���� �ڽ� ����� �ε��� �� ��ȯ, returns index value of left child node
int getLChildIdx(int idx) {
	return idx * 2;
}

// ������ �ڽ� ����� �ε��� �� ��ȯ, returns index value of right chlid node		
int getRChildIdx(int idx) {
	return idx * 2 + 1;
}

void displayHeap(Heap* h) {
	int i;
	for (i = 1; i <= h->numOfData; i++)
		printf("%d %d\n", i, h->heap[i]);
	printf("\n");
}
