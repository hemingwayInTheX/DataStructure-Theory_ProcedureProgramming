/*2016211106_이현탁*/
#include <stdio.h>

typedef struct {
	int row;
	int col;
	int value;
}matrix;

void transposeSM(matrix a[], matrix b[]) {
	// Fill you code
	/*1.희소행렬 -> 행렬에서 0인 아닌 값만 추출한 압축행렬
				 -> 구조체 배열의 첫번째 인덱스([0])는 행,열,데이터의 개수를 표시
	  2.전치행렬 -> 기존 행렬에서 열과 행이 바뀐행렬
	  3.임시구조체배열(temp)에 reverse한 원본의 데이터 대입
	  4.행과 열의 뒤바뀜 고려 --> 전체 loop문 종료조건 : 원본행렬의 열 개수만큼 수행하도록, 내부 loop문 종료조건 : 전체 데이터 개수만큼 수행하도록*/
	matrix temp[11];
	int posB = 1;/*b구조체배열의 인덱스*/
	int totalNum = a[0].value;/*전체 데이터 개수 --> 내부반복문 종료조건*/
	
	b[0].row = a[0].col;/*행렬의 정보를 나타내는 데이터는 loop문 밖에서 초기화*/
	b[0].col = a[0].row;
	b[0].value = a[0].value;

	for (int i = 0; i < 11; i++){/*temp구조체 배열에 원본의 데이터를 reverse해서 초기화 */
		temp[i].row = a[i].col;
		temp[i].col = a[i].row;
		temp[i].value = a[i].value;
	}

	for (int i = 0; i < a[0].col; i++){/*열의 개수(전치행렬에서는 행에 해당)만큼 수행*/
		for (int j = 1; j <= totalNum; j++){/*전체 데이터 개수만큼 수행*/
			if (temp[j].row == i) {
				b[posB].row = temp[j].row;
				b[posB].col = temp[j].col;
				b[posB].value = temp[j].value;
				posB++;/*값할당후 위치인덱스 증가*/
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

	