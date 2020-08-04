#include <stdio.h>
#define HORIZONTAL 9
#define VERTICAL 8 // 세로길이는 별로 의미가 없네요?

/*
문제에서 원하는 출력값은 낙차값중에 가장 큰값입니다.
따라서 개별 박스의 낙차를 구하기보다는 해당 열에있는 박스중 가장 낙차값이 크게 나오는 숫자를
resultArr 배열에 저장하고
그리고 이 배열에서 가장 큰 값을 출력하는 방식으로 생각하고 코드를 작성했습니다.
90도 회전 어쩌구하는건 일단 무시했습니다.
*/

int dropTheBox[HORIZONTAL] = {7, 4, 2, 0, 0, 6, 0, 7, 0};
int resultArr[HORIZONTAL];

void vertical_drop(int dropTheBox[], int horizontal);

int main(void) {
    vertical_drop(dropTheBox, HORIZONTAL);
    int max = 0;
    printf("result array: ");
    for (int i = 0; i < HORIZONTAL; i++) { // 낙차값 배열중 가장 큰 값을 추출하는 코드 입니다.
        printf("%d ", resultArr[i]);
        if (max < resultArr[i]) {
            max = resultArr[i];
        }
    }
    printf("\n");
    printf("result: %d", max);
    return 0;
}

void vertical_drop(int dropTheBox[], int horizontal) {
    for (int i = 0; i < horizontal; i++) {
        int countMax = 0; // countMax 는 비교하려는 값(dropTheBox[i]) 보다 같거나 큰값이 몇개나 있는지 얻어오는 변수입니다.
        for (int j = i; j < horizontal; j++) { // 비교하려는 값보다 큰값들을 찾습니다.
            if (dropTheBox[i] <= dropTheBox[j] && dropTheBox[i] != 0) {
                countMax += 1;
            }
        }
        if (dropTheBox[i] == 0) { // arr[i] 가 0일경우 resultArr에 그대로 0을 넣어줍니다.
            resultArr[i] = 0;
        } else {
            // horizontal 은 90도 회전했을경우 떨어질 높이값이 됩니다.
            // 그래서 낙차값을 총 높이 - 아래박스가 현재 박스보다 크거나 같은 박스의 갯수 - 그리고 떨어질때마다 +1씩 낙차값이 올라가는데 자기 자신이 위치한 칸은 제외해야 하므로 i 를 빼줍니다.
            resultArr[i] = horizontal - countMax - i;
        }
    }
}