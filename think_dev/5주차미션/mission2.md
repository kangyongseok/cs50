## 1) 수업에서 언급되었던 Heap overflow와 stack overflow에 대해서 어떤 경우에 발생이 되는지 서술해주세요.
우선 heap overflow 와 stack overflow 를 이해하려면 heap 과 stack 에 대한 이해가 먼저 필요하다.  

### stack
스택은 임시변수를 저장하는 컴퓨터 메모리의 특별한 영역이다. c 를 작성할때 사용하는 main() 함수는 LIFO(last in, first out) 데이터구조로 CPU에 의해 관리되고 최적화된다.  

주로 함수의 호출과 관계되는 지역변수와 매개변수가 저장되는 영역이다. 스택영역은 함수의 호출과 함께 할당되고 함수의 호출이 완료되면 소멸하게된다.  

push 동작으로 데이터를 저장하고 pop 동작으로 데이터를 인출한다. 즉 가장 늦게 저장된 데이터가 가장 먼저 인출된다. 어떤 박스에 물건이 들어가있으면 가장 밑에 물건을 꺼내려면 위에서부터 차례대로 꺼내야 가장 밑에있는 물건을 꺼낼 수 있고 이 가장 밑에있는 물건은 물건이 들어갈때 가장 먼저 들어간 물건이다.

### heap
메모리의 힙 영역은 사용자가 직접 관리할 수 있고 또 관리해야만 하는 영역이다. 사용자에 의해서 동적으로 메모리가 할당되고 해제되며 여기에 사용되는 함수가 malloc() 과 free() 가 있다.

### overflow
스택은 계속 함수가 실행되면서 변수값이 쌓이는 상태가되는데 이 함수가 종료가되지않고 무한반복문 같은 루프에 빠지게되면 함수의 소멸이 발생하지않기때문에 스택의 모든 공간을 차지하고 나면 스택이 넘치는 스택오버플로우가 발생하게된다.  

힙은 사용자가 메모리를 할당해주게되는데 이때 힙 영역에 할당된 크기를 초과하게되면 초과된 데이터를 기록하더나 저장되어있던 데이터 및 함수의 주소를 변경하게된다. 이때 영역을 벗어난 데이터는 인접 메모리를 덮어쓰게되는데 다른데이터가 있을경우 데이터의 손실 or 치명적인 오류가 발생 할 수 있다.

## 2) Strcpy와 strncpy의 차이점을 서술해보세요. (어떤 것을 추천하는지와 그 이유에 대해서 서술해주세요.)
```c
strcpy(char *복사받을변수, char *복사할 변수);  
strncpy(char *복사받을변수, char *복사할 변수, 복사될 사이즈);  
```

strcpy 는 문자열의 마지막에 있는 null 값까지 복사를 수행한다. 복사를 진행하는 변수의 사이즈만큼만 변경을 실행하고 나머지 부분은 아무런 처리를 하지 않기때문에 포인터로 하나씩 찍어보면 복사한 문자열 이외에 뒤쪽에 기존에 나머지 문자열이 나오게 된다.  

strncpy 는 마지막 인자값으로 지정한 크기만큼만 복사를 진행하기때문에 오버플로우걱정을 덜 수 있다. 다만 null까지 복사해주지않기때문에 이 부분에 대한것까지 고려해서 사이즈를 지정해 주어야한다. 해당 사이즈만큼 문자를 복사하고나면 나머지 영역에 대해서는 자동으로 null 처리를 해주기때문에 복사한 문자열만 남게된다.   
둘다 복사받을 변수의 사이즈보다는 복사될 변수의 크기가 더 작아야한다. 둘다 불완전한 부분이 있지만 둘중에 사용해야한다면 명확한 복사사이즈를 지정해주고 크기가 더 작다면 나머지 문자열에 대해서 null 처리를 해주는 strncpy() 함수를 사용하기를 추천할것같다.


## 3) 메모리 초기화, 복사, 이동, 비교와 같은 함수가 라이브러리에 있습니다. 사용방법을 숙지하고, 간단하게 코드로 구현 후 정상적으로 동작이 되는지 확인해보세요.

### 함수 종류
```c
#include <string.h>

// 데이터 초기화 함수
/*
 s = 초기화될 메모리 영역
 c = 채울 데이터
 n = 채울 바이트 수
*/
void *memset(void *s, int c, size_t n);

// 메모리복사 or 이동 함수
/*
dest = 복사되는 공간의 첫번째 시작주소
src = 복사할 메모리의 첫번째 시작주소
count = 복사할 메모리크기

두 함수의 차이점
memcpy = 메모리의 내용을 직접 복사하고 (빠름)
memmove = 복사할 메모리의 내용을 임시공간에 저장한다음 복사 (안정성)

예전에는 두 함수의 차이가 있었는데 현재는 오류나 차이가 많이 좁혀졌다고함
*/
void *memcpy(void *dest, const void *src, size_t count);
void *memmove(void *dest, const void *src, size_t count);

// 메모리 비교
/*
str1 = 비교 대상 메모리 포인터
str2 = 비교할 메모리 포인터
n = 비교할 바이트 크기

결과
양의정수 = str1 이 더 크다
0 = 동일하다
음의정수 = str2 가 더 크다
*/
int memcmp ( const void * str1, const void * str2, size_t n );

```

### 실행코드
```c
#include <stdio.h>
#include <string.h>

char str1[13] = "Hello, world";
char str2[6] = "abcde";

void strncpyPlay(void);
void strcpyPlay(void);
void memsetPLay(void);
void memmovePlay(void);
void memcmpPlay(void);

int main(void) {

    strcpyPlay();
    strncpyPlay();
    memsetPLay();
    memmovePlay();
    memcmpPlay();
}

void strncpyPlay(void) {
    strncpy(str1, str2, sizeof(str1) - 1);
    printf("%s\n", str1);
    for (int i = 0; i < 13; i++) {
        printf("%c", str1[i]);
    }
    printf("\n");
}

void strcpyPlay(void) {
    strcpy(str1, str2);
    printf("%s\n", str1); // abcde
    int length = sizeof(str1) / sizeof(char);
    for (int i = 0; i < length; i++) {
        printf("%c", str1[i]); // abcde world
    }
    printf("\n");
}

void memsetPLay(void) {
     memset(str1, 'a', 13 * sizeof(char));
    for (int i = 0; i < 13; i++) {
        printf("%c", str1[i]);
    }
    printf("\n");
}

void memmovePlay(void) {
    int arr[5] = {1, 2, 3, 4, 5};
    memmove(arr, arr + 1, sizeof(int) * 3);
    for (int i = 0; i < 5; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void memcmpPlay(void) {
    int arr1[5] = {1, 2, 3, 4, 5};
    // int arr2[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {6, 7, 8, 9, 10};
    int result = memcmp(arr1, arr2, sizeof(int));
    printf("%d\n", result);    
    printf("\n");
}
```