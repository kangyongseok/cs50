#include <stdio.h>
#include <stdlib.h>

int main(void){
    int arr[5][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20},
                     {21, 22, 23, 24, 25}};

    int **ptr=NULL; //���������� ����

    ptr=(int**)malloc(sizeof(int*)*5);  //���������Ϳ� int�� ũ�� 5��¥�� ������ �迭 �Ҵ� 
    for(int i=0; i<5; i++) ptr[i]=(int*)malloc(sizeof(int)*5);  //������ �迭 ������ �ε����� int�� 5���� �迭 �Ҵ�

    for(int i=0; i<5; i++)
        ptr[i] = arr[i];    //������ �迭 �� �࿡ 2���� �迭�� �� �� ù �ּ� ����
    
    for(int i=4; i>=0; i--){    //�迭�� ������ ����� ����
        printf("arr[%d] : ", i);
        for(int j=0; j<5; j++){
            printf("%d\t", ptr[i][j]);
        }
        printf("\n");
    }

    //�����Ҵ� ����
    for(int i=0; i<5; i++) free(ptr[i]);
    free(ptr);
}   //���� : https://twinparadox.tistory.com/439