#include <stdio.h>
const int len = 4;
const int arr[len + 1] = {0, 1, 2, 5, 10}; // 처음에 0을 넣은 이유: 1번째 사람을 인덱스0이 아니라 인덱스1로 접근하기 위해서.
void one(int a, int *sum)
{
	*sum += arr[a];
	printf("%d\n", arr[a]);
}

void two(int a, int b, int *sum)
{
	*sum += arr[b];
	printf("%d %d\n", arr[a], arr[b]);
}

void river(int n, int *sum)
{
	if (n == 1)			// 한명
		one(1, sum);
	else if (n == 2)	// 두명
		two(1, 2, sum);
	else				// 세명
	{
		river(2, sum);
		river(1, sum);
		two(n - 1, n, sum);
	}					// 네명부터
	if (n >= 4)
	{
		one(2, sum);
		river(n - 2, sum);
	}
}
int main(void)
{
	int sum = 0;
	river(len, &sum);
	printf("sum: %d\n", sum);
}