/*USE RECURSION TO FIND OUT TARGET INDEX_USE BSearch*/
#include <stdio.h>

int BSearch(int* getArr, int first, int last, int target);

int main(void) {

	int arr[] = { 2,4,6,9,10,12,14,17,20};
	int start = 0;
	int final = sizeof(arr) / sizeof(arr[0]) - 1;
	int result;

	if (result == -1) {
		printf("ERROR MESSAGE");
	}
	printf("target index >> %d\n", result);

	system("pause");
	return 0;
}

int BSearch(int* getArr, int first, int last, int target) {
	
	int mid;

	if (first > last) {return -1;}
	
	mid = (first + last) / 2;
	if (target == getArr[mid]) {
		return mid;
	}
	else if (target < getArr[mid]) {
		BSearch(getArr, first, mid - 1, target);
	}
	else {
		BSearch(getArr, mid + 1, last, target);
	}
}















