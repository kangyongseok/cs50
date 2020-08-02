#include <stdio.h>
#include <stdlib.h>
// #include <math.h>
#define TRUE 1
#define FALSE 0

// 요구사항 자체가 거리를 예시로들면서 정해진 순서대로 숫자가 입력된다고 보았습니다.
// 요구사항에는 없는 정렬코드가 들어가게되면 불필요한 로직이 생기고 불필요한 실행시간이 소요되기때문에 순수하게 거리의 센터위치를 구현하는데 중점을 두었습니다.
// 정렬 관련된 문제가 아닌것같아서 저는 모든 값은 이미 정렬된 순서대로 들어온다고 가정하고 코드를 작성하였습니다.
// 입력된 배열 내에서 센터에 가장 근접한 값을 찾아 리턴하는 문제라고 이해하고 접근하였습니다.
int inputData_1[4] = {0, 4, 6, 9};
int inputData_2[4] = {2, 2, 2, 4};
int inputData_3[6] = {1, 2, 3, 5, 7, 9};
int inputData_4[6] = {1, 2, 10, 23, 31, 35};

// void getIntArrSize(int *arr);
void findCenterHouse(int arr[], int count);
int averageDistance(int arr[], int count);

int main(void) {
    findCenterHouse(inputData_1, sizeof(inputData_1) / sizeof(int));
    findCenterHouse(inputData_2, sizeof(inputData_2) / sizeof(int));
    findCenterHouse(inputData_3, sizeof(inputData_3) / sizeof(int));
    findCenterHouse(inputData_4, sizeof(inputData_4) / sizeof(int));

    return 0;
}

void findCenterHouse(int arr[], int count) {
    int average = averageDistance(arr, count);
    int isCenterHouse = FALSE;
    for (int i = 0; i < count; i++) { // 평균 지점과 일치하는 값이 배열에 있을때
        if(arr[i] == average) {
            isCenterHouse = average;
            break;
        }
    }
    if (isCenterHouse == FALSE) { // 평균 지점과 일치하는 센터값이 배열에 없을때
        int maxOfSmallValue; // 평균값보다 작은값중에 가장 큰값
        int minOfBigValue; // 평균값보다 큰값중에 가장 작은값

        for(int i = 0; i < count; i++) { // 센터값과 가장 근사치에있는 양쪽의 값을 구함
            if (average > arr[i]) {
                // printf("평균값보다 작은 배열의 값: %d\n", arr[i]);
                maxOfSmallValue = arr[i];
            } else {
                // printf("평균값보다 큰 배열의 값: %d\n", arr[i]);
                minOfBigValue = arr[i];
                break;
            }
        }

        // printf("a: %d\n", a);
        // printf("b: %d\n", b);
        // 선택값과 근사치로 있는 양쪽의 값을 구했으면 
        // 근사치에서 가장 작은값을 빼고 가장 큰 값에서 큰사치를 뺴서 양쪽 거리의 격차값이 더 작은쪽이 센터
        if (abs((maxOfSmallValue - arr[0]) - (arr[count - 1] - maxOfSmallValue)) < abs((minOfBigValue - arr[0]) - (arr[count - 1] - minOfBigValue))) {
            isCenterHouse = maxOfSmallValue;
        } else {
            isCenterHouse = minOfBigValue;
        }
    }
    printf("Center House: %d\n", isCenterHouse);
}

int averageDistance(int arr[], int count) { // 평균 거리를 갖는 지역의 정수를 반환
    int sum = 0;
    int average = 0;
    for (int i = 0; i < count; i++) {
        sum += arr[i];
    }
    average = sum / count;
    // printf("Averrage Distance: %d\n", average);
    return average;
}
