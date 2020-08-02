#include <stdio.h>

int main(void)
{
    int goalMoney;

    printf("목표금액을 입력하세요: ");
    scanf("%d", &goalMoney);

    printf("%.0f", (goalMoney * 0.012) + goalMoney);

    return 0;
}