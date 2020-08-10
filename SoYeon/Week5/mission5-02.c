#include <stdio.h>
#include <memory.h>

void print(int n[], int v){
    if(v==1){
        printf("arr[4] : ");
        for(int i=0; i<4; i++) printf("%d\t", n[i]);
        printf("\n\n");
    }
    else{
        printf("src[7] : ");
        for(int i=0; i<7; i++) printf("%d\t", n[i]);
    printf("\n\n");
    }
}

void printX(int n[]){
    printf("arr[4] : ");
    for(int i=0; i<4; i++) printf("%#x\t", n[i]);
    printf("\n\n");
}

int main(void){
    int arr[4] = {0, 0, 0, 0};
    int src[7] = {1, 2, 3, 4, 5, 6, 7};
    int result;

    print(arr,1);
    print(src,2);

    ////////메모리 초기화(memset)////////////
    printf("AFTER memset(arr, 10, sizeof(int)*4)\n");
    memset(arr, 10, sizeof(int)*4);     //memset(void *dest, int c, size_t count)
    print(arr, 1);     //결과가 10으로 나오지 않는 이유 : memset은 1바이트 단위로 초기화하기 때문에 1바이트가 10으로 설정된 4개가 배열의 한 인덱스에 들어가는 것. 
                       //참고 : https://m.blog.naver.com/PostView.nhn?blogId=dd1587&logNo=221059593458&proxyReferer=https:%2F%2Fwww.google.com%2F
    printX(arr);

    /////////메모리 복사(memcpy)//////////////
    printf("AFTER memcpy(arr, src, sizeof(int)*4)\n");
    memcpy(arr, src, sizeof(int)*4);    ///memcpy(void *dest, void *src, size_t count)
    print(arr, 1);

    /////////메모리 이동(memmove)/////////////////
    printf("AFTER memmove(arr, arr+1, sizeof(int)*3\n");
    memmove(arr, arr+1, sizeof(int)*3); //memmove(void *dest, const void *src, size_t n)
    print(arr, 1);

    ///////////////메모리 비교(memcmp)/////////////
    printf("AFTER memcmp(arr, src, sizeof(arr)\n");
    result = memcmp(arr, src, sizeof(arr));
    print(arr, 1);
    print(src, 2);
    if(result == 0) 
        printf("Not same\n");
    else if(result == 1) 
        printf("arr is bigger than src\n");
    else 
        printf("arr is smaller than src.\n");
}