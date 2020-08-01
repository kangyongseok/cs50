#include <stdio.h>
#define MAX 5
#define TRUE 1
#define FALSE 0

void selectSort(int *arr);
void bubbleSort(int *arr);
void mergeSort(int *arr); 
void swap(int x, int y, int tmp, int *arr);
void compare(int *x, int *y);

int selectSort_1[MAX] = {1, 2, 3, 4, 5};
int selectSort_2[MAX] = {5, 4, 3, 2, 1};
int bubbleSort_1[MAX] = {1, 4, 2, 5, 8};
int bubbleSort_2[MAX] = {2, 5, 4, 3, 1};
int recursive_1[MAX] = {1, 1, 1, 3, 2};
int recursive_2[MAX] = {2, 1, 1, 3, 1};

int main(void) {

    selectSort(selectSort_1);
    selectSort(selectSort_2);
    bubbleSort(bubbleSort_1);
    bubbleSort(bubbleSort_2);
    mergeSort(recursive_1);
    mergeSort(recursive_2);

    compare(selectSort_1, selectSort_2);
    compare(bubbleSort_1, bubbleSort_2);
    compare(recursive_1, recursive_2);

}

void selectSort(int *arr) {
    // 선택정렬
    // n개의 배열중 가장 작은값을 찾아 0부터 n-1 번째까지 반복문 돌면서 0번 인덱스부터 스왑
    for (int i = 0; i < MAX - 1; i++) {
        int minIndex = i;
        int tmp;
        for (int j = i + 1; j < MAX; j++) {
            if (arr[i] > arr[j]) {
                minIndex = j;
            }
        }
        if (i != minIndex) { // 자기 자신이 최소값일때 swap 하지않음
            swap(i, minIndex, tmp, arr);
        }
    }
}

void bubbleSort(int *arr) {
    // 버블정렬
    // n 개의 배열을 돌면서 n 과 n + 1 의 값을 비교하여 n + 1 이 더 작다면 swap
    // 정렬이 진행될때마다 제일 오른쪽 배열부터는 더이상 비교할 필요가 없어 그만큼 비교횟수를 -1 해줘야한다.
    int tmp;
    for(int i = 0; i < MAX -1; i ++) {
        for (int j = 0; j < MAX - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(j, j + 1, tmp, arr);
            }
        }
    }
}

void mergeSort(int *arr) {
    // 재귀정렬
    
}


// 기타 사용 함수
void swap(int x, int y, int tmp, int *arr) {
    tmp = arr[x];
    arr[x] = arr[y];
    arr[y] = tmp;
}

void compare(int *x, int *y) {
    int result;
    for (int i = 0; i < MAX; i++) {
        if (x[i] != y[i]) {
            result = FALSE;
        } else {
            result = TRUE;
        }
    }
    printf("입력값: %d%d%d%d%d, %d%d%d%d%d", x[0], x[1], x[2], x[3], x[4], y[0], y[1], y[2], y[3], y[4]);
    printf("출력값: %s\n", result == 0 ? "False" : "True");
}
