#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5      //SIZE of input array

void print(int num[]);
int compare(int n1[], int n2[]);
void convert(int n[], int N);
void merge_sort(int data[], int left, int right);
void merge(int data[], int left, int mid, int right);

int sorted[SIZE];   //temporary array to merge sort

///////////////////////////////////////////////////////////////////////////
//////////This program checks whether inputs have the same elements.///////
//////////Also, Users can input the data which they want.//////////////////
///////////////////////Plus, it uses merge sort.///////////////////////////
///////////////////////////////////////////////////////////////////////////
int main(void){
    int n1[SIZE];
    int n2[SIZE];
    int result;
    char all[100];
    char *strN1;
    char *strN2;
    int N1;
    int N2;

    printf("Input the 1 pair of 5 numbers. Example : 12345(space)43251\n");
    gets(all);  //input data. 데이터 입력
    strN1 = strtok(all, " "); //seperate the string before space. 스페이스 이전의 숫자 덩어리 가져오기
    strN2 = strtok(NULL, "");   //seperate the string after space. 스페이스 이후의 숫자 덩어리 가져오기

    N1 = atoi(strN1);   //convert string to integer. 문자열을 숫자로 변환
    N2 = atoi(strN2);

    convert(n1, N1);    //seperate the numbers by digits.숫자를 자릿수별로 배열에 입력
    convert(n2, N2);

    printf("=======================================================\n");
    printf("INPUT\n");
    print(n1);          //print input 1
    print(n2);          //print input 2

    printf("=======================================================\n");
    merge_sort(n1, 0, SIZE-1);    //merge sort of n1(input 1). n1의 합병 정렬 수행
    merge_sort(n2, 0, SIZE-1);    //merge sort of n2(input 2). n2의 합병 정렬 수행
    result = compare(n1, n2);   //compare two sorted inputs. 정렬한 두 배열 비교
    if(result == 0) printf("OUTPUT : True\n");
    else printf("OUTPUT : False\n");

}

void print(int num[]){      //print all elements of array.
    printf(">>>>>\t");
    for(int i=0; i<SIZE; i++){
        printf("%d\t", num[i]);
    }
    printf("\n");
}

void convert(int n[], int N){   //seperate the numbers by digits. 각 자릿수를 배열에 저장하는 함수

    n[0] = N/10000;
    N %= 10000;
    n[1] = N/1000;
    N %= 1000;
    n[2] = N/100;
    N %= 100;
    n[3] = N/10;
    n[4] = N%10;
}

void merge(int data[], int left, int mid, int right){
    int i = left, j = mid+1, k = left, l;

    while(i<=mid && j<=right){  //starting from the 1st elements of left and right array. 왼쪽배열, 오른쪽배열 각각 처음부터 끝까지
        if(data[i]<=data[j])    //If element of left array is smaller than elements of right array. 왼쪽배열의 원소가 오른쪽배열의 원소보다 작다면
            sorted[k++] = data[i++];    //store the smaller elements in the temporary array. 임시배열에 작은 원소 저장
        else                    //if element of right array is smaller than elements of left array. 오른쪽 배열의 원소가 왼쪽배열의 원소보다 작다면 
            sorted[k++] = data[j++]; //store the smaller elements in the temporary array. 임시배열에 작은 원소 저장
    }

    if(i>mid){      //copy all left elements of right array to temporary array. 남아있는 값들 일괄복사. 오른쪽 배열에 남아있는 값들 일괄복사
        for(l=j; l<=right; l++){
            sorted[k++] = data[l];
        }
    }
    else{           //copy all left elements of left array to temporary array. 남아있는 값들 일괄복사. 왼쪽배열에 남아있는 값들 일괄복사
        for(l=i; l<=mid; l++){
            sorted[k++] = data[l];
        }
    }

    for(l=left; l<=right; l++){     //copy all elements of temporary array to original array(n1, n2). 임시 배열을 원래 배열에 복사
        data[l] = sorted[l];
    }
}

void merge_sort(int data[], int left, int right){   //merge sort by recursion
    int mid;

    if(left<right){
        mid = (left+right)/2;   //calculate the middle of array. 중간 위치 계산
        merge_sort(data, left, mid);    //merge sort of left array by middle. 중간 기준 왼쪽배열 정렬
        merge_sort(data, mid+1, right); //merge sort of right array by middle. 중간 기준 오른쪽배열 정렬
        merge(data, left, mid, right);  //merge the sorted left and right array. 정렬해둔 왼,오 배열 합치기
    }
}   //출처 : https://gmlwjd9405.github.io/2018/05/08/algorithm-merge-sort.html

int compare(int n1[], int n2[]){    //compare the elements of two array.
    for(int i=0; i<SIZE; i++){
        if(n1[i]!=n2[i])
            return 1;
    }
}

