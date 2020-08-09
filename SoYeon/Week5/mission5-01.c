#include <stdio.h>
#include <stdlib.h>

int main(void){
    int arr[5][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20},
                     {21, 22, 23, 24, 25}};

    int **ptr=NULL; //이중포인터 선언

    ptr=(int**)malloc(sizeof(int*)*5);  //이중포인터에 int형 크기 5개짜리 포인터 배열 할당 
    for(int i=0; i<5; i++) ptr[i]=(int*)malloc(sizeof(int)*5);  //포인터 배열 각각의 인덱스에 int형 5개의 배열 할당

    for(int i=0; i<5; i++)
        ptr[i] = arr[i];    //포인터 배열 각 행에 2차원 배열의 각 행 첫 주소 복사
    
    for(int i=4; i>=0; i--){    //배열의 마지막 행부터 접근
        printf("arr[%d] : ", i);
        for(int j=0; j<5; j++){
            printf("%d\t", ptr[i][j]);
        }
        printf("\n");
    }

    //동적할당 해제
    for(int i=0; i<5; i++) free(ptr[i]);
    free(ptr);
}   //참고 : https://twinparadox.tistory.com/439