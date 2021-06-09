#include <stdio.h>
#pragma warning ( disable : 4996 )

#define MAX_TERMS 20


typedef struct {    // 구조체 term 정의
    float coef; // 다항식의 각 항의 계수를 저장할 변수
    int exp;    // 다항식의 각 항의 차수를 저장할 변수
} term;

void addTerm(term* A, term* B, term* C) {
    /*1. LOOP 탈출조건 고려 : 구조체배열A,B의 크기-->MAX-TERMS(20)으로 초기화 --> 계수와 차수가 할당된 인덱스까지 작업이 수행되도록 반복문 구현
      2. A,B 최고차항(차수)의 대소비교 : 덧셈결과가 저장되는 C에 차수를 기준으로 내림차순 결과가 나오도록 구현 --> A,B exp(차수)의 모든 요소들이
         C에 반영되도록 구현
      3. A,B중 차수가 0인경우(상수항) : 0이상 차수간의 대소비교 검사 종료후 독립된 반복문을 통해 C에 상수항 할당*/
    int endIndexA = 0;/*구조체배열A의 차수와 계수가 몇 인덱스까지 할당되어있는지 CHECK하는 변수 --> 차수대소비교 반복문 종료조건*/
    int endIndexB = 0;/*구조체배열B의 차수와 계수가 몇 인덱스까지 할당되어있는지 CHECK하는 변수 --> 차수대소비교 반복문 종료조건*/
    int i = 0;/*A식*/
    int j = 0;/*B식*/
    int k = 0;/*C식*/
    /*1. 차수와 계수가 없는 인덱스는 모두 0으로 초기화되어있다는 점을 고려
      2. 차수와 계수의 합이 0이상이라는 것은 두멤버중 하나라도 데이터가 존재한다는 점을 고려
      3. 순차적으로 탐색을 시도해 차수와 계수의 합이 0이상이면 endIndexA, endIndexB의 값을 1씩증가
      4. 조건 부합하지 않으면 루프문 탈출 ---> 해당 변수값에는 조건에 부합할 때까지 증가된 endIndexA,endIndexB의 값이 저장*/
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
    /*1. 3가지 조건에 따라 결과항에 어떤항이 복사되는지 선택
      2. A,B,C각 항의 차수를 대소비교해 C에 할당하는 작업을 위해 각각의 인덱스가 부여(후위연산자 사용)
         EX) LOOP1) IF<i=0,j=0;k=0> 
            ~ A[0].EXP > B[0].EXP = TRUE
            ~ C[0] = A[0] --> 0에 대입하고 그 다음에 인덱스값이 증가
            ~값 할당후 K=1/I=1*/
    while (i < endIndexA && j < endIndexB) {
        if (A[i].exp > B[j].exp) {/*1. A차수가 클경우 C에 A의 계수와 차수를 복사*/
            C[k++] = A[i++];
        }
        else if (A[i].exp==B[j].exp) {/*2. A차수와 B차수가 동일한 경우 C에 두항의 계수를 더한것을 저장*/
            C[k].coef = A[i].coef + B[i].coef;
            C[k].exp = A[i].exp;
            k++;
            i++;
            j++;
        }
        else{/*3. B차수가 클경우 C에 B의 계수와 차수를 복사*/
            C[k++] = B[j++]; 
        }
   }/*LOOP_3*/
    /*A에 상수항이 있을경우, B에 상수항이 있을경우 두가지를 고려해 할당*/
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