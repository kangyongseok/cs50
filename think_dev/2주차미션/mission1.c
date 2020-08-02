#include <stdio.h>

int main(void)
{
    int orderCount = 3;
    int currentCount = 5;
    int restCount = 0;
    int totalPrice = 0;
    int cost = 10000;
    float vat = 0.1;

    restCount = currentCount - orderCount;
    totalPrice = orderCount * cost;


    printf("주문건수 : %d 건\n", orderCount);
    printf("기존 재고량 : %d개\n", currentCount);
    printf("남은 재고량 : %d개\n", restCount);
    printf("매출액(부가세포함) : %.0f원\n", (totalPrice * vat) + totalPrice);

    return 0;
}