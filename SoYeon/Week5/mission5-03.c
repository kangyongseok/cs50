#include <stdio.h>
#define SIZE 7

void sort(int n, int arr[]);

int main(void){
    int arr[SIZE] = {0, 25, 10, 17, 6, 12, 9};

    sort(SIZE, arr);

    return 0;
}

void sort(int n, int arr[]){
    int *ptr = arr;
    int tmp;

    for(int i=0; i<n; i++){       //����� ������ŭ �ݺ� 
        for(int j=0; j<n-i; j++){   //�̹� ���ĵ� ��Ҵ� ���� �ʿ�����Ƿ� n-i
            if(ptr[j]>ptr[j+1]){    
                tmp = ptr[j+1];
                ptr[j+1] = ptr[j];
                ptr[j] = tmp;
            }
        }
    }

    for(int i=0; i<n; i++) printf("%d\t", ptr[i]);
}