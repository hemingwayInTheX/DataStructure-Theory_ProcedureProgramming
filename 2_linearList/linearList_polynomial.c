#include <stdio.h>
#pragma warning ( disable : 4996 )

#define MAX_TERMS 20


typedef struct {    // ����ü term ����
    float coef; // ���׽��� �� ���� ����� ������ ����
    int exp;    // ���׽��� �� ���� ������ ������ ����
} term;

void addTerm(term* A, term* B, term* C) {
    /*1. LOOP Ż������ ��� : ����ü�迭A,B�� ũ��-->MAX-TERMS(20)���� �ʱ�ȭ --> ����� ������ �Ҵ�� �ε������� �۾��� ����ǵ��� �ݺ��� ����
      2. A,B �ְ�����(����)�� ��Һ� : ��������� ����Ǵ� C�� ������ �������� �������� ����� �������� ���� --> A,B exp(����)�� ��� ��ҵ���
         C�� �ݿ��ǵ��� ����
      3. A,B�� ������ 0�ΰ��(�����) : 0�̻� �������� ��Һ� �˻� ������ ������ �ݺ����� ���� C�� ����� �Ҵ�*/
    int endIndexA = 0;/*����ü�迭A�� ������ ����� �� �ε������� �Ҵ�Ǿ��ִ��� CHECK�ϴ� ���� --> ������Һ� �ݺ��� ��������*/
    int endIndexB = 0;/*����ü�迭B�� ������ ����� �� �ε������� �Ҵ�Ǿ��ִ��� CHECK�ϴ� ���� --> ������Һ� �ݺ��� ��������*/
    int i = 0;/*A��*/
    int j = 0;/*B��*/
    int k = 0;/*C��*/
    /*1. ������ ����� ���� �ε����� ��� 0���� �ʱ�ȭ�Ǿ��ִٴ� ���� ���
      2. ������ ����� ���� 0�̻��̶�� ���� �θ���� �ϳ��� �����Ͱ� �����Ѵٴ� ���� ���
      3. ���������� Ž���� �õ��� ������ ����� ���� 0�̻��̸� endIndexA, endIndexB�� ���� 1������
      4. ���� �������� ������ ������ Ż�� ---> �ش� ���������� ���ǿ� ������ ������ ������ endIndexA,endIndexB�� ���� ����*/
    for (int i = 0; i < MAX_TERMS; i++){
        if (A[i].coef + A[i].exp > 0) {
            endIndexA++;
        }
        else {
            break;
        }
    }/*LOOP_1*/

    for (int i = 0; i < MAX_TERMS; i++) {
        if (B[i].coef + B[i].exp > 0) {
            endIndexB++;
        }
        else {
            break;
        }
     }/*LOOP_2*/
    /*1. 3���� ���ǿ� ���� ����׿� ����� ����Ǵ��� ����
      2. A,B,C�� ���� ������ ��Һ��� C�� �Ҵ��ϴ� �۾��� ���� ������ �ε����� �ο�(���������� ���)
         EX) LOOP1) IF<i=0,j=0;k=0> 
            ~ A[0].EXP > B[0].EXP = TRUE
            ~ C[0] = A[0] --> 0�� �����ϰ� �� ������ �ε������� ����
            ~�� �Ҵ��� K=1/I=1*/
    while (i < endIndexA && j < endIndexB) {
        if (A[i].exp > B[j].exp) {/*1. A������ Ŭ��� C�� A�� ����� ������ ����*/
            C[k++] = A[i++];
        }
        else if (A[i].exp==B[j].exp) {/*2. A������ B������ ������ ��� C�� ������ ����� ���Ѱ��� ����*/
            C[k].coef = A[i].coef + B[i].coef;
            C[k].exp = A[i].exp;
            k++;
            i++;
            j++;
        }
        else{/*3. B������ Ŭ��� C�� B�� ����� ������ ����*/
            C[k++] = B[j++]; 
        }
   }/*LOOP_3*/
    /*A�� ������� �������, B�� ������� ������� �ΰ����� ����� �Ҵ�*/
    while (i < endIndexA) {C[k++] = A[i++];}/*LOOP_4*/

    while (j < endIndexB) {C[k++] = B[j++];}/*LOOP_5*/


}


void printTerm(term* p) {
    int i = 0;
    while (p[i].exp != 0 || p[i].coef != 0) {
        printf("%3.0fx^%d", p[i].coef, p[i].exp);
        i++;
        if (p[i].exp != -1 && p[i].coef > 0)
            printf(" +");
    }
    printf("\n");
}

int main() {
    term A[MAX_TERMS] = { {3,19}, {4,5}, {1,0} };
    term B[MAX_TERMS] = { {5,8}, {7,5}, {1,1} };
    term C[MAX_TERMS] = { 0 };
    addTerm(A, B, C);

    printf("\n A(x)="); printTerm(A);
    printf("\n B(x)="); printTerm(B);
    printf("\n C(x)="); printTerm(C);
    
    return 0;
}