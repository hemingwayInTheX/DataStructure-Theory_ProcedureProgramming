/*2016211106_����Ź*/
#include <stdio.h>

typedef struct {
	int row;
	int col;
	int value;
}matrix;

void transposeSM(matrix a[], matrix b[]) {
	// Fill you code
	/*1.������ -> ��Ŀ��� 0�� �ƴ� ���� ������ �������
				 -> ����ü �迭�� ù��° �ε���([0])�� ��,��,�������� ������ ǥ��
	  2.��ġ��� -> ���� ��Ŀ��� ���� ���� �ٲ����
	  3.�ӽñ���ü�迭(temp)�� reverse�� ������ ������ ����
	  4.��� ���� �ڹٲ� ��� --> ��ü loop�� �������� : ��������� �� ������ŭ �����ϵ���, ���� loop�� �������� : ��ü ������ ������ŭ �����ϵ���*/
	matrix temp[11];
	int posB = 1;/*b����ü�迭�� �ε���*/
	int totalNum = a[0].value;/*��ü ������ ���� --> ���ιݺ��� ��������*/
	
	b[0].row = a[0].col;/*����� ������ ��Ÿ���� �����ʹ� loop�� �ۿ��� �ʱ�ȭ*/
	b[0].col = a[0].row;
	b[0].value = a[0].value;

	for (int i = 0; i < 11; i++){/*temp����ü �迭�� ������ �����͸� reverse�ؼ� �ʱ�ȭ */
		temp[i].row = a[i].col;
		temp[i].col = a[i].row;
		temp[i].value = a[i].value;
	}

	for (int i = 0; i < a[0].col; i++){/*���� ����(��ġ��Ŀ����� �࿡ �ش�)��ŭ ����*/
		for (int j = 1; j <= totalNum; j++){/*��ü ������ ������ŭ ����*/
			if (temp[j].row == i) {
				b[posB].row = temp[j].row;
				b[posB].col = temp[j].col;
				b[posB].value = temp[j].value;
				posB++;/*���Ҵ��� ��ġ�ε��� ����*/
			}
		}
	}
}
			
int main() {
	int i, j;
	matrix a[11] = {	{8,7,10}, 
						{0,2,2},
						{0,6,12},
						{1,4,7},
						{2,0,23},
						{3,3,31},
						{4,1,14},
						{4,5,25},
						{5,6,6},
						{6,0,52},
						{7,4,11}
	};
	matrix b[11] = {0, };
	transposeSM(a, b);
	
	printf("Matrix a\n");
	for(i=0; i<11; i++)
		printf("%d: %d %d %d\n", i, a[i].row, a[i].col, a[i].value);
	printf("Transpose Matrix b\n");
	for(i=0; i<11; i++)
		printf("%d: %d %d %d\n", i, b[i].row, b[i].col, b[i].value);
	return 0;
}

	