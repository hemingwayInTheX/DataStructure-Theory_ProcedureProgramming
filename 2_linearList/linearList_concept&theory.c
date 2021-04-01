#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100		// �迭�� �ִ� ũ��

typedef int element;
typedef struct {
	element list[MAX_SIZE];	// �迭 ����
	int length;		// ���� �迭�� ����� �ڷ���� ����
}ArrayListType;

// ���� ó�� �Լ�
void error(char* message)
{
	printf("%s\n", message);
}

// ����Ʈ �ʱ�ȭ
void init(ArrayListType* L)
{	
	L->length = 0;
}

// �� ����Ʈ �˻�
// ����Ʈ�� ��� ������ 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ
int isEmpty(ArrayListType* L)
{
	return L->length == 0;
}

// ����Ʈ�� ��ȭ������ �˻�
// ����Ʈ�� ������ ������ 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ
int isFull(ArrayListType* L)
{
	return L->length == MAX_SIZE;
}

// ����Ʈ�� ��� ��� ���
void display(ArrayListType* L)
{
	int i;
	printf("===Print Lists===\n");
	for (i = 0; i < L->length; i++)
		printf("ArrayList[%d]: %d\n", i, L->list[i]);
}

// ���� �Լ� 
// pos: �����ϰ��� �ϴ� ��ġ
// item: �����ϰ��� �ϴ� �ڷ�
void insert(ArrayListType* L, int pos, element item)/*�ε����� ���� ���ö����� ������ �Ҵ�� ���Ұ� ��ĭ��(�ε��� ����) �ڷ� �̵�*/
{
	if (!isFull(L) && (pos >= 0) && (pos <= L->length)){/*����Ʈ�� ����ȭ �����Ӱ� ���ÿ� ��ȿ�� �ε����� ���� �Ҵ� �����ϸ� INSERT ����*/
		printf("ArrayList[0]�� %d ����\n", item);
		for (int i = (L->length - 1); i >= pos; i--)/*pos�� 0 and length(����Ʈ ���� �ڷ��� ����)�� 0�� ��� ù �ݺ��� ���� ����X --> ���� ���������ʰ� 60��° �ٿ��� �ٷ� �� �Ҵ�*/
			L->list[i + 1] = L->list[i];/*���� ������ �����ε����� �Ҵ�� ���Ұ� ���� �ε����� �̵��ϴ� LOOP -> EX) LOOP1 : arr[0]=10  -> LOOP2 : arr[0]=20 arr[1]=10*/
		L->list[pos] = item;
		L->length++;/*�� ������ �ڷ��� ���� ����*/
	}
	else {/*��ȿ���� ��Ż�� THROWING Message*/
		error("Index Error");
	}
}

// ����Ʈ �� �տ� ��� ����
void insertFirst(ArrayListType* L, element item)/*First�Լ����� pos �Ű�����(������ �ϰ����ϴ� �ε���)�� ���ٴ� ���� �����ϰ� ����*/
{
	/*LOOP�� ���� -> FROM { ������ �ε����� ���Һ��� ��ĭ�� �ڷ� �̵� } TO { ������ ù��° �ε����� �Ҵ�� ���ұ��� �̵����Ѿ��� } ===
	��, ������ �ε������� ù��° �ε������� ���������� ��ĭ�� �ڷ� �̵�*/
	if (!isFull(L)) {
		printf("ArrayList[0]�� %d ����\n", item);
		for (int i = (L->length - 1); i >= 0; i--){
			L->list[i + 1] = L->list[i];
		}
		L->list[0] = item;/*ù ��° �ε����� �� �Ҵ�*/
		L->length++;
	}
}

// ����Ʈ �� ���� ��� ����
void insertLast(ArrayListType* L, element item)
{
	if (!isFull(L)) {/*����Ʈ �ڷ��� ������ �� �� �ε����� ���� --> �ش� �ε����� ������ �Ҵ� */
		printf("ArrayList[%d]�� %d ����\n", L->length, item);
		L->list[L->length] = item;
		L->length++;
	}
}

// ���� �Լ�
// pos: �����ϰ��� �ϴ� ��ġ
// ��ȯ��: �����Ǵ� �ڷ�
element delete(ArrayListType* L, int pos){
	
	element item;

	if (isEmpty(L)) {
		error("List is empty");
	}
	else if ((pos < 0) || (pos >= L->length)) {
		error("Index Error");
	}
	else {/*STEP1 -> �����ϰ����ϴ� �ε����� ��� STEP2 -> ������ �ε����� ���� �ε����� ������ ��� === �ش� ������ �ݺ�*/
		item = L->list[pos];
		for (int i = pos; i < L->length-1; i++){/*FOR EXAMPLE) IF YOU WANT TO DELETE <INDEX 2> -> list[2] = list[3] --> �ε��� 3�� �ִ� ���Ұ� �ε��� 2�� �̵�*/
			L->list[i] = L->list[i+1];
		}
		L->length--;/*������ ����Ʈ �����Ͱ����� ����*/
		return item;
	}
}

// ����Ʈ�� ��� ��� ����
void clear(ArrayListType* L){
	
	L->length = 0;
}

// pos ��ġ�� ��Ҹ� item���� ��ü
void replace(ArrayListType* L, int pos, element item){
	
	int temp = 0;/*�ӽ��������*/

	if (isEmpty(L)) {
		error("List is empty");
	}
	else if ((pos < 0) || (pos >= L->length)) {
		error("Index Error");
	}
	else {
		for (int i = 0; i < L->length-1; i++){/*temp�� '�ٲ�'�� ���� �ε����� �����͸� ���� -> '�ٲٰ��� �ϴ� ������'�� ���� �־��� �ε����� temp ����*/
			temp = L->list[i + 1];
			L->list[pos] = item;
			L->list[i] = temp;
		}
	}
}

// item�� ����Ʈ�� �ִ��� �˻�
// ����Ʈ�� ������ 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ
int isList(ArrayListType* L, element item)
{
	int CHECK = 0;

	if (isEmpty(L)) {
		error("List is empty");
	}
	else {
		for (int i = 0; i < L->length; i++) {
			if (L->list[i] == item){/*Ž�� ����-->�ش� �ε����� ã�����ϴ� ������������ TRUE ��ȯ*/
				CHECK = 1;
			}
			else {
				CHECK = 0;
			}
		}
	}
	return CHECK;
}


// pos ��ġ�� ��Ҹ� ��ȯ
element getItem(ArrayListType* L, int pos)
{
	element returnItem = 0;/*pos ��ġ�� �ش��ϴ� �����͸� ���� --> return ������ ����*/

	if (isEmpty(L)) {/*CHECK EXCEPTION*/
		error("List is empty");
	}
	else if ((pos < 0) || (pos >= L->length)) {
		error("Index Error");
	}
	else {
		for (int i = 0; i < L->length; i++){
			if (L->list[pos] == L->list[i]) {/*�Ű������� �Ѿ�� ��ġ�ε����� �ش��ϴ� �����Ͱ� �´��� Ȯ��*/
				returnItem = L->list[i];/*Ȯ���� �ش� ��ġ�� �����͸� ���Ϻ����� ����*/
			}
		}
	}
	return returnItem;/*THROWING TO MAIN FUNCTION !*/
}

// ����Ʈ�� ����(�׸��� ����)�� ����
int getLength(ArrayListType* L)
{
	return L->length;
}


int main()
{
	ArrayListType* plist;
	
	// ListType�� �������� �����ϰ� ListType�� ����Ű�� 
	// �����͸� �Լ��� �Ķ���ͷ� �����Ѵ�.
	plist = (ArrayListType*)malloc(sizeof(ArrayListType));
	init(plist);

	int lengthResult;/*����Ʈ �ڷᰳ�� ���ϰ� ����*/
	int listChk;/*����Ʈ ���� ���� Ȯ���Լ� ���ϰ� ���� --> 1 or 0*/
	element takeItem;/*�ε��� ��ġ�� �ش��ϴ� ���� ���ϰ� ���� -> VALUE*/
	element deleteElementResult;/*������ �ε����� ������ ���ϰ� ����*/

	/*====insert �޼��� ȣ��=====*/
	insert(plist, 0, 10);
	insert(plist, 0, 20);

	/*====insertFirst �޼��� ȣ��=====*/
	insertFirst(plist, 5);

	/*====insertLast �޼��� ȣ��=====*/
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
		
	/*delete �޼��� ȣ��-->15���� ���� ��� ����*/
	for (int i = 0; i < plist->length; i++){
		if (plist->list[i] < 15) {
			delete(plist, i);
		}
	}
	/*SHOW THE PRESENT SITUATION*/
	display(plist); /*������ ����Ʈ ��Ȳ���*/

	/*replace �޼��� ȣ��*/
	replace(plist, 1, 20);
	display(plist);
	
	/*SHOW THE LENGTH*/
	lengthResult = getLength(plist);/*������ ����Ʈ �ڷ��� ���� ��� */
	printf("LENGTH IS %d\n", lengthResult);

	/*clear �޼��� ȣ��*/
	clear(plist);

	/*====CHECK SATURATION OF LIST*/
	if (isEmpty(plist)) {
		printf("IS EMPTY\n");
	}
	free(plist);

	return 0;
}
