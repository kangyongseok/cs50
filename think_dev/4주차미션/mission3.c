// 의사코드 작성

/*
반복 싸이클
만약 기존 배열에 값이 없을때까지
가장 빠른 두사람이 이동한다. 
sum += 둘중에 가장 느린사람
넘어간 사람중에 가장 빠른 사람이 되돌아온다.
sum += 둘중에 가장 빠른사람
가장 느린사람 두명이 넘어간다.
sum += 둘중에 가장 느린사람
넘어간 사람중에 가장 빠른 사람이 되돌아온다.
sum += 둘중에 가장 빠른사람

** 주의: 총원이 홀수일때와 짝수일때 다름
만약 총원이 홀수라면 건너기 전의 배열이 세개가 남았을때 건너야할 두명은
가장 작은값과 가장 큰값 이 건너야 되돌아건너올 값이 가장 작은값이 성립됨

즉 남은 사람이 3명이 될때까지는 싸이클대로 성립 만약 3명이 남았다면 가장 작은값과 가장 큰값이 건너야 하는 로직을 추가해야함

*/

/*
짝수일때

예제1)
총원 4
건너는 속도 {1, 2, 5, 10}

결과1)
모두 건너는데 걸리는 최소시간  17
가장 빠른 두사람이 이동한다. (1, 2)
넘어간 사람중에 가장 빠른 사람이 되돌아온다. (1)
가장 느린사람 두명이 넘어간다. (5, 10)
넘어간 사람중에 가장 빠른 사람이 되돌아온다. (2)
가장 빠른 두사람이 이동한다. (1, 2)

예제2)
총원 6
건너는 속도 {1, 2, 3, 7, 9, 10}

결과2)
모두 건너는데 걸리는 최소시간  29
가장 빠른 두사람이 이동한다. (1, 2)
넘어간 사람중에 가장 빠른 사람이 되돌아온다. (1)
가장 느린사람 두명이 넘어간다. (9, 10)
넘어간 사람중에 가장 빠른 사람이 되돌아온다. (2)

가장 빠른 두사람이 이동한다. (1, 2)
넘어간 사람중에 가장 빠른 사람이 되돌아온다. (1)
가장 느린사람 두명이 넘어간다. (3, 7)
넘어간 사람중에 가장 빠른 사람이 되돌아온다. (2)

가장 빠른 두사람이 이동한다. (1, 2)
*/

#include <stdio.h>
#include <string.h>
#define RIGHT 0
#define LEFT 1

void printArr(int arr[], int count, int derection);
void viewPrint(int left[], int right[], int count);
void inputZero(int left[], int right[], int count, int direction);

int left_1[4] = {1, 2, 5, 10}; // 17 / 1, 2 / 1 / 5, 10 / 2 / 1, 2
int left_2[5] = {1, 3, 5, 7, 10}; // 26 / 1, 3 / 1 / 7, 10 / 3 / 1, 5 / 1 / 1, 3
int left_3[6] = {1, 2, 3, 7, 9, 10}; // 29 / 1, 2 / 1 / 9, 10 / 2 / 1, 2 / 1 / 3, 7 / 2 / 1, 2
int left_4[7] = {1, 2, 3, 4, 7, 9, 10}; // 33 / 1, 2 / 1 / 9, 10 / 2 / 1, 2 / 1 / 4, 7 / 2 / 1, 3 / 1 / 1, 2

int right_1[4];
int right_2[5];
int right_3[6];
int right_4[7];

int sum = 0;

int main(void) {
    /*
        memmove(인자1, 인자2, 인자3)
        인자1: 붙여넣기가 될 공간의 첫번째 시작 주소
        인자2: 복사할 메모리의 첫번째 시작 주소
        인자3: 복사할 크기
    */
    int length_1 = sizeof(left_1) / sizeof(int);
    int length_2 = sizeof(left_2) / sizeof(int);
    int length_3 = sizeof(left_3) / sizeof(int);
    int length_4 = sizeof(left_4) / sizeof(int);

    if (length_1 % 2 == 0) {
        // 짝수
        
    } else {
        // 홀수

    }

    test(right_3, left_3, sizeof(int));

    memmove(right_3, left_3, sizeof(int)*2);
    inputZero(left_3, right_3, length_3, LEFT);
    viewPrint(left_3, right_3, length_3);
    

    memmove(left_3, right_3, sizeof(int));
    inputZero(left_3, right_3, length_3, RIGHT);
    viewPrint(left_3, right_3, length_3);

    memmove(right_3 + (length_3 - 2), left_3 + (length_3 - 2), sizeof(int)*2);
    inputZero(left_3, right_3, length_3, LEFT);
    viewPrint(left_3, right_3, length_3);

    memmove(left_3 + 1, right_3 + 1, sizeof(int));
    inputZero(left_3, right_3, length_3, RIGHT);
    viewPrint(left_3, right_3, length_3);

    memmove(right_3, left_3, sizeof(int)*2);
    inputZero(left_3, right_3, length_3, LEFT);
    viewPrint(left_3, right_3, length_3);

    // memmove(right_1, left_1, sizeof(int)*2);
    // inputZero(left_1, right_1, length_1, LEFT);
    // viewPrint(left_1, right_1, length_1);
    

    // memmove(left_1, right_1, sizeof(int));
    // inputZero(left_1, right_1, length_1, RIGHT);
    // viewPrint(left_1, right_1, length_1);

    // memmove(right_1 + (length_1 - 2), left_1 + (length_1 - 2), sizeof(int)*2);
    // inputZero(left_1, right_1, length_1, LEFT);
    // viewPrint(left_1, right_1, length_1);

    // memmove(left_1 + 1, right_1 + 1, sizeof(int));
    // inputZero(left_1, right_1, length_1, RIGHT);
    // viewPrint(left_1, right_1, length_1);

    // memmove(right_1, left_1, sizeof(int)*2);
    // inputZero(left_1, right_1, length_1, LEFT);
    // viewPrint(left_1, right_1, length_1);

    printf("%d\n", sum);
}


// 이동 후 왼쪽 배열에 오른쪽으로 옮겨간 만큼의 숫자를 0으로 비움
void inputZero(int left[], int right[], int count, int direction) {
    if (direction) {
        printf("오른쪽으로 건너간 사람: ");
        int big;
        for (int i = 0; i < count; i++) {
            if (left[i] == right[i]) {
                printf("%d ", left[i]);
                big = left[i];
                left[i] = 0;
            }
        }
        sum += big;
    } else {
        printf("왼쪽으로 건너간 사람: ");
        for (int i = 0; i < count; i++) {
            if (left[i] == right[i]) {
                printf("%d ", left[i]);
                sum += left[i];
                right[i] = 0;
            }
        }
    }
    printf("\n");
}

// =====================================================================//

// 이동 후 왼쪽과 오른쪽에 남은 값 보여주기 위한 print 함수 입니다.
void printArr(int arr[], int count, int derection) {
    printf("%s: ", derection ? "왼쪽" : "오른쪽");
    for(int i = 0; i < count; i++) {
        printf("%d ",arr[i]);
    }
}

// printArr 함수에 의존성을 갖고 보기좋게 출력하기 위한 출력함수입니다.
void viewPrint(int left[], int right[], int count) {
    printf("=================================================\n");
    printArr(left, count, LEFT);
    printArr(right, count, RIGHT);
    printf("\n");
    printf("=================================================\n");
    printf("\n");
}