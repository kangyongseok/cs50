#include <stdio.h>

int main(void) {
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';
    // i 는 int , c 는 char, (int) 는 문자를 ASCII 코드의 숫자형태로 변형
    printf("%i %i %i\n", (int)c1, (int)c2, (int)c3);
    // 실제 메모리에 저장된 형태
    //     c1               c2            c3
    // 01001000 (72), 01001001 (73), 00100001 (33)
}