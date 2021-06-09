#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100		// 배열의 최대 크기

typedef int element;
typedef struct {
	element list[MAX_SIZE];	// 배열 정의
	int length;		// 현재 배열에 저장된 자료들의 개수
}ArrayListType;

// 오류 처리 함수
void error(char* message)
{
	printf("%s\n", message);
}

// 리스트 초기화
void init(ArrayListType* L)
{	
	L->length = 0;
}

// 빈 리스트 검사
// 리스트가 비어 있으면 1을 반환
// 그렇지 않으면 0을 반환
int isEmpty(ArrayListType* L)
{
	return L->length == 0;
}

// 리스트가 포화상태인 검사
// 리스트가 가득차 있으면 1을 반환
// 그렇지 않으면 0을 반환
int isFull(ArrayListType* L)
{
	return L->length == MAX_SIZE;
}

// 리스트의 모든 요소 출력
void display(ArrayListType* L)
{
	int i;
	printf("===Print Lists===\n");
	for (i = 0; i < L->length; i++)
		printf("ArrayList[%d]: %d\n", i, L->list[i]);
}

// 삽입 함수 
// pos: 삽입하고자 하는 위치
// item: 삽입하고자 하는 자료
void insert(ArrayListType* L, int pos, element item)/*인덱스에 값이 들어올때마다 기존에 할당된 원소가 한칸씩(인덱스 기준) 뒤로 이동*/
{
	if (!isFull(L) && (pos >= 0) && (pos <= L->length)){/*리스트가 불포화 상태임과 동시에 유효한 인덱스에 원소 할당 가능하면 INSERT 가능*/
		printf("ArrayList[0]에 %d 삽입\n", item);
		for (int i = (L->length - 1); i >= pos; i--)/*pos가 0 and length(리스트 내의 자료의 개수)가 0일 경우 첫 반복문 조건 성립X --> 루프 실행하지않고 60번째 줄에서 바로 값 할당*/
			L->list[i + 1] = L->list[i];/*값이 들어오면 기존인덱스에 할당된 원소가 다음 인덱스로 이동하는 LOOP -> EX) LOOP1 : arr[0]=10  -> LOOP2 : arr[0]=20 arr[1]=10*/
		L->list[pos] = item;
		L->length++;/*값 들어오면 자료의 개수 증가*/
	}
	else {/*유효범위 이탈시 THROWING Message*/
		error("Index Error");
	}
}

// 리스트 맨 앞에 요소 삽입
void insertFirst(ArrayListType* L, element item)/*First함수에는 pos 매개변수(삽입을 하고자하는 인덱스)가 없다는 것을 인지하고 들어가자*/
{
	/*LOOP의 조건 -> FROM { 마지막 인덱스의 원소부터 한칸씩 뒤로 이동 } TO { 기존에 첫번째 인덱스에 할당된 원소까지 이동시켜야함 } ===
	즉, 마지막 인덱스부터 첫번째 인덱스까지 순차적으로 한칸씩 뒤로 이동*/
	if (!isFull(L)) {
		printf("ArrayList[0]에 %d 삽입\n", item);
		for (int i = (L->length - 1); i >= 0; i--){
			L->list[i + 1] = L->list[i];
		}
		L->list[0] = item;/*첫 번째 인덱스에 값 할당*/
		L->length++;
	}
}

// 리스트 맨 끝에 요소 삽입
void insertLast(ArrayListType* L, element item)
{
	if (!isFull(L)) {/*리스트 자료의 개수가 맨 끝 인덱스와 동일 --> 해당 인덱스에 데이터 할당 */
		printf("ArrayList[%d]에 %d 삽입\n", L->length, item);
		L->list[L->length] = item;
		L->length++;
	}
}

// 삭제 함수
// pos: 삭제하고자 하는 위치
// 반환값: 삭제되는 자료
element delete(ArrayListType* L, int pos){
	
	element item;

	if (isEmpty(L)) {
		error("List is empty");
	}
	else if ((pos < 0) || (pos >= L->length)) {
		error("Index Error");
	}
	else {/*STEP1 -> 삭제하고자하는 인덱스를 비움 STEP2 -> 삭제한 인덱스의 다음 인덱스를 앞으로 댕김 === 해당 과정을 반복*/
		item = L->list[pos];
		for (int i = pos; i < L->length-1; i++){/*FOR EXAMPLE) IF YOU WANT TO DELETE <INDEX 2> -> list[2] = list[3] --> 인덱스 3에 있던 원소가 인덱스 2로 이동*/
			L->list[i] = L->list[i+1];
		}
		L->length--;/*삭제후 리스트 데이터개수를 감소*/
		return item;
	}
}

// 리스트의 모든 요소 삭제
void clear(ArrayListType* L){
	
	L->length = 0;
}

// pos 위치의 요소를 item으로 교체
void replace(ArrayListType* L, int pos, element item){
	
	int temp = 0;/*임시저장공간*/

	if (isEmpty(L)) {
		error("List is empty");
	}
	else if ((pos < 0) || (pos >= L->length)) {
		error("Index Error");
	}
	else {
		for (int i = 0; i < L->length-1; i++){/*temp에 '바뀜'을 당할 인덱스의 데이터를 저장 -> '바꾸고자 하는 데이터'가 원래 있었던 인덱스에 temp 대입*/
			temp = L->list[i + 1];
			L->list[pos] = item;
			L->list[i] = temp;
		}
	}
}

// item이 리스트에 있는지 검사
// 리스트에 있으면 1을 반환
// 그렇지 않으면 0을 반환
int isList(ArrayListType* L, element item)
{
	int CHECK = 0;

	if (isEmpty(L)) {
		error("List is empty");
	}
	else {
		for (int i = 0; i < L->length; i++) {
			if (L->list[i] == item){/*탐색 시작-->해당 인덱스에 찾고자하는 데이터있으면 TRUE 반환*/
				CHECK = 1;
			}
			else {
				CHECK = 0;
			}
		}
	}
	return CHECK;
}


// pos 위치의 요소를 반환
element getItem(ArrayListType* L, int pos)
{
	element returnItem = 0;/*pos 위치에 해당하는 데이터를 저장 --> return 변수로 선언*/

	if (isEmpty(L)) {/*CHECK EXCEPTION*/
		error("List is empty");
	}
	else if ((pos < 0) || (pos >= L->length)) {
		error("Index Error");
	}
	else {
		for (int i = 0; i < L->length; i++){
			if (L->list[pos] == L->list[i]) {/*매개변수로 넘어온 위치인덱스에 해당하는 데이터가 맞는지 확인*/
				returnItem = L->list[i];/*확인후 해당 위치의 데이터를 리턴변수에 저장*/
			}
		}
	}
	return returnItem;/*THROWING TO MAIN FUNCTION !*/
}

// 리스트의 길이(항목의 개수)를 구함
int getLength(ArrayListType* L)
{
	return L->length;
}


int main()
{
	ArrayListType* plist;
	
	// ListType를 동적으로 생성하고 ListType를 가리키는 
	// 포인터를 함수의 파라미터로 전달한다.
	plist = (ArrayListType*)malloc(sizeof(ArrayListType));
	init(plist);

	int lengthResult;/*리스트 자료개수 리턴값 저장*/
	int listChk;/*리스트 원소 유무 확인함수 리턴값 저장 --> 1 or 0*/
	element takeItem;/*인덱스 위치에 해당하는 원소 리턴값 저장 -> VALUE*/
	element deleteElementResult;/*삭제한 인덱스의 데이터 리턴값 저장*/

	/*====insert 메서드 호출=====*/
	insert(plist, 0, 10);
	insert(plist, 0, 20);

	/*====insertFirst 메서드 호출=====*/
	insertFirst(plist, 5);

	/*====insertLast 메서드 호출=====*/
	insertLast(plist, 30);

	/*====CHECK EXCEPTION=====*/
	insert(plist, -1, 3);

	/*====CHECK SATURATION OF LIST*/
	if (!isFull(plist)) {
		printf("IS NOT FULL\n");
	}

	/*SHOW THE PRESENT SITUATION*/
	display(plist);

	/*=====CHECK ISLIST=====*/
	listChk = isList(plist, 30);
	printf("IS THERE 30 IN THE LIST? ");
	if (listChk == 1) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}

	/*=====CHECK POS=====*/
	takeItem = getItem(plist, 2);
	printf("%d is in INDEX_2\n", takeItem);

	/*SHOW THE LENGTH*/
	lengthResult = getLength(plist);
	printf("LENGTH IS %d\n", lengthResult);
	lengthResult = 0;
		
	/*delete 메서드 호출-->15보다 작은 요소 삭제*/
	for (int i = 0; i < plist->length; i++){
		if (plist->list[i] < 15) {
			delete(plist, i);
		}
	}
	/*SHOW THE PRESENT SITUATION*/
	display(plist); /*삭제후 리스트 현황출력*/

	/*replace 메서드 호출*/
	replace(plist, 1, 20);
	display(plist);
	
	/*SHOW THE LENGTH*/
	lengthResult = getLength(plist);/*삭제후 리스트 자료의 개수 출력 */
	printf("LENGTH IS %d\n", lengthResult);

	/*clear 메서드 호출*/
	clear(plist);

	/*====CHECK SATURATION OF LIST*/
	if (isEmpty(plist)) {
		printf("IS EMPTY\n");
	}
	free(plist);

	return 0;
}
