#include <stdio.h>
#include <stdlib.h>

void swap(int x, int y, int tmp, int *arr);
void selectSort(int *arr, int N);

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
        numArr[i] = tmp;
    }
    selectSort(numArr, N);

    for (int j = 0; j < N; j++) {
        printf("%d ", numArr[j]);
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