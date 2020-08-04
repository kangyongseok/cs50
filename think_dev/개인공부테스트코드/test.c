#include <stdio.h>
const int len = 7;
const int arr[len + 1] = {0, 1, 2, 3, 4, 7, 9, 10}; // 처음에 0을 넣은 이유: 1번째 사람을 인덱스0이 아니라 인덱스1로 접근하기 위해서.

void one(int index);
void two(int big, int bigger);
void river(int length);

int sum = 0;
int cycle = (len % 4) + (len / 4) + len; // 추가 전체 인원수에 따라 총 싸이클 계산
int increaseCycle = 0; // 추가 총 싸이클과 비교하기 위해 편도로 오고 갈때마다 싸이클 수 증가
int odd = (len % 2) != 0; // 추가 인원수가 홀수인지 확인

int main(void) {
	river(len);
	printf("sum: %d\n", sum);
}

void river(int length) { // 7, 0
	if (length == 1)		
		one(1);
	else if (length == 2)	
		two(1, 2);
	else				
	{
		// 1. 여기가 가장 먼저 실행됨
		river(2); // 재귀 실행 후 two 함수로 전달되어 배열인덱스의 첫번째와 두번째가 출력되게함 
		river(1); // 재귀 실행 후 one 함수로 전달되어 배열의 인덱스의 첫번째 값이 출력되게함 
		if (cycle - increaseCycle == 1 && odd) {  // 총 인원이 홀수이고 마지막 싸이클일떄
			two(length - 2, length);
		} else {
			two(length - 1, length); // 넘겨받은 길이가 2 이상일경우 length 값과 length-1 값 출력되게함
		}
	}

	if (length >= 4)
	{
		// 2. 1번의 실행이 끝난다음 여기 실행
		// printf("test\n");
		one(2); // 무조건 두번째 배열의 값을 출력 / 5
		river(length - 2);
	}
}


void one(int index) {
	sum += arr[index];
	increaseCycle += 1;
	printf("%d\n", arr[index]);
	// printf("SUM: %d\n", sum);
}

void two(int big, int bigger) {
	sum += arr[bigger];
	increaseCycle += 1;
	printf("%d %d\n", arr[big], arr[bigger]);
	// printf("SUM: %d\n", sum);
}