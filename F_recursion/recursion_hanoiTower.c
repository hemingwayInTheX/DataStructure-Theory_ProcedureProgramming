#include <stdio.h>
/*��) 4���� �ű�� ���� -> 3���� �ű�� ����
  ->2���� �ű�� ���� -> 1���� �ű�� ����
  N-1���� �پ���!!POINT
   ��) �ϴ� ���� 3���� �ðܾ���*/
void HanoiTowerMove(int num, char from, char by, char to);

int main(void) {

	HanoiTowerMove(3, 'A', 'B', 'C');
	return 0;
}

void HanoiTowerMove(int num, char from, char by, char to) {

	if (num == 1) {
		printf("����1�� %c���� %c�� �̵�\n", from, to);
	}
	else {
		HanoiTowerMove(num - 1, from, to, by);
		printf("����%d�� %c���� %c�� �̵�\n",num-1, by, from, to);
		HanoiTowerMove(num - 1, by, from, to);
	}
}

