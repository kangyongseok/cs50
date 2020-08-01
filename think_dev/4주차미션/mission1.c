#include <stdio.h>
#define MAX 5
#define TRUE 1
#define FALSE 0

void selectSort(int *arr);
void bubbleSort(int *arr);
void mergeSort(int *arr, int start, int end);
void swap(int x, int y, int tmp, int *arr);
void compare(int *x, int *y);
void merge(int *arr, int start, int mid, int end);

int selectSort_1[MAX] = {1, 0, 3, 4, 5};
int selectSort_2[MAX] = {5, 4, 3, 0, 1};
int bubbleSort_1[MAX] = {1, 4, 2, 5, 8};
int bubbleSort_2[MAX] = {2, 5, 4, 3, 1};
int recursive_1[MAX] = {1, 1, 1, 3, 2};
int recursive_2[MAX] = {2, 1, 1, 3, 1};
int mergeSortResult[MAX]; // 병합정렬된 배열이 들어갈 변수

int main(void) {

    selectSort(selectSort_1);
    selectSort(selectSort_2);
    bubbleSort(bubbleSort_1);
    bubbleSort(bubbleSort_2);
    mergeSort(recursive_1, 0, MAX - 1); // 배열데이터와함께 시작 과 끝 인텍스값을 넘기기때문에 MAX - 1 을 넘겨줍니다.
    mergeSort(recursive_2, 0, MAX - 1);

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
            if (arr[minIndex] > arr[j]) {
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
        if (result == 0) break;
    }
    printf("입력값: %d%d%d%d%d, %d%d%d%d%d ", x[0], x[1], x[2], x[3], x[4], y[0], y[1], y[2], y[3], y[4]);
    printf("출력값: %s\n", result == 0 ? "False" : "True");
}

void merge(int *arr, int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = start; // 정렬된 배열을 담을 변수의 index
    // printf("mid :%d start: %d end: %d\n", mid, start, end);
    while(i <= mid && j <= end) { 
        if (arr[i] <= arr[j]) { // 앞의 값보다 뒤의값이 크거나 같은지
            mergeSortResult[k] = arr[i];
            i++;
        } else { // 뒤에비교하는 숫자가 더 작을경우
            mergeSortResult[k] = arr[j];
            j++;
        }
        k++;
    }

    if (i > mid) { // while 문에서 배열에 할당하지 못한 나머지 값을 여기서 할당한다.
        for(int t = j; t <= end; t++) {
            mergeSortResult[k] = arr[t];
            k++;
        }
    } else {
        for(int t = i; t <= mid; t++) {
            mergeSortResult[k] = arr[t];
            k++;
        }
    }
    for (int t = start; t <= end; t++) { // 정렬된 배열을 원래 배열에 넣는다.
        arr[t] = mergeSortResult[t];
    }
}

void mergeSort(int *arr, int start, int end) {
    // 재귀정렬
    if (start < end) {
        int mid = (start + end) / 2;
        // printf("mid: %d\n", mid);
        mergeSort(arr, start, mid); // 배열의 처음부터 중간까지
        mergeSort(arr, mid + 1, end); // 배열의 중간 다음배열부터 마지막 배열까지
        merge(arr, start, mid, end); // mergeSort 의 실행이 모두 끝나야 merge 함수실행
    }
}