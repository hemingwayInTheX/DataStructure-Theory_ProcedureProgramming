#include <stdio.h>
/*ㄱ) 4개를 옮기는 문제 -> 3개를 옮기는 문제
  ->2개를 옮기는 문제 -> 1개를 옮기는 문제
  N-1개로 줄어든다!!POINT
   ㄴ) 일단 위에 3개를 올겨야함*/
void HanoiTowerMove(int num, char from, char by, char to);

int main(void) {

	HanoiTowerMove(3, 'A', 'B', 'C');
	return 0;
}

void HanoiTowerMove(int num, char from, char by, char to) {

	if (num == 1) {
		printf("원반1을 %c에서 %c로 이동\n", from, to);
	}
	else {
		HanoiTowerMove(num - 1, from, to, by);
		printf("원반%d을 %c에서 %c로 이동\n",num-1, by, from, to);
		HanoiTowerMove(num - 1, by, from, to);
	}
}

