#include <stdio.h>
#include <stdlib.h>

/*
시간복잡도
시간복잡도는 선택정렬 사용했기떄문에 일단 정렬에서 기본적으로 O(n2) 의 복잡도를 가질것이고
여기에 추가로 사용자값을 입력받을때마다 배열의 처음부터 끝까지 입력한값과 중복된 값이 있는지 찾기때문에 여기서 한번더 O(n2) 의 시간 복잡도를 갖습니다.
당연히 제 구현체보다 빠른 답이 있을거라고 생각합니다.

c 언어가 익숙하지않고 아직 재귀와 연결리스트의 개념을 완벽히 숙지하지못해 익숙한 방법으로 구현했고
리팩토링이나 좀더 빠른 시간복잡도를 갖는 구현방법은 제출후에 좀더 시간을 갖고 고민해보려고 합니다.
*/


void swap(int x, int y, int tmp, int *arr);
void selectSort(int *arr, int N);
int overlabCheck(int *arr, int i, int getNum);

int main(void) {
    int N;
    int *numArr;
    printf("input N: ");
    scanf("%d", &N);
    numArr = malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        int tmp;
        printf("input random number: ");
        scanf("%d", &tmp);
        int checkResult = overlabCheck(numArr, i, tmp);
        if (checkResult == 0) {
            i += -1;
        } else {
            numArr[i] = tmp;
        }
    }
    selectSort(numArr, N);

    for (int j = 0; j < N; j++) {
        printf("%d ", numArr[j]);
    }
    return 0;
}

int overlabCheck(int *arr, int i, int getNum) {
    // 배열에 값이 추가 될때마다 추가된 배열과 입력된 값을 비교하여 사용자 입력단계에서 중복값이 있는 index 체크
    if (i > 0) {
        for (int j = 0; j < i; j++) {
            if (arr[j] == getNum) {
                printf("There are duplicate values. Please re-enter");
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        return 1;
    }
}


void selectSort(int *arr, int N) {
    // 선택정렬
    // n개의 배열중 가장 작은값을 찾아 0부터 n-1 번째까지 반복문 돌면서 0번 인덱스부터 스왑
    for (int i = 0; i < N - 1; i++) {
        int minIndex = i;
        int tmp;
        for (int j = i + 1; j < N; j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        if (i != minIndex) { // 자기 자신이 최소값일때 swap 하지않음
            swap(i, minIndex, tmp, arr);
        }
    }
}

void swap(int x, int y, int tmp, int *arr) {
    tmp = arr[x];
    arr[x] = arr[y];
    arr[y] = tmp;
}