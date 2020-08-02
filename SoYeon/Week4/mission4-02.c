#include <stdio.h>
//#include <math.h> //pow(제곱) 사용하기 위한 것.
//#include <string.h> //memset 함수 사용
#define SIZE1 10
#define SIZE2 5
#define SIZE3 4
#define SIZE4 6
void print(int num[], int s);
void merge_sort(int data[], int left, int right, int size);
void merge(int data[], int left, int mid, int right, int size);
int chooseMid(int data[], int s);

int main(void){
    int dst1[SIZE1] = {4, 3, 1, 6, 8, 3, 5, 9, 5, 2};
    int dst2[SIZE2] = {1, 2, 3, 4, 5};
    int dst3[SIZE3] = {2, 2, 2, 4};
    int dst4[SIZE4] = {5, 2, 3, 6, 4, 1};
    int mid;

    printf("INPUT dst1\n");
    print(dst1, SIZE1);
    merge_sort(dst1, 0, SIZE1-1, sizeof(dst1)/sizeof(int));
    printf("Merged dst1\n");
    print(dst1, SIZE1);
    printf("OUTPUT : %d\n", dst1[SIZE1/2]);
    printf("========================================================\n");

    printf("INPUT dst2\n");
    print(dst2, SIZE2);
    merge_sort(dst2, 0, SIZE2-1, sizeof(dst2)/sizeof(int));
    printf("Merged dst2\n");
    print(dst2, SIZE2);
    printf("OUTPUT : %d\n", dst2[SIZE2/2]);
    printf("========================================================\n");

    printf("INPUT dst3\n");
    print(dst3, SIZE3);
    merge_sort(dst3, 0, SIZE3-1, sizeof(dst3)/sizeof(int));
    printf("Merged dst3\n");
    print(dst3, SIZE3);
    printf("OUTPUT : %d\n", dst3[SIZE3/2]);
    printf("========================================================\n");


    printf("INPUT dst4\n");
    print(dst4, SIZE4);
    merge_sort(dst4, 0, SIZE4-1, sizeof(dst4)/sizeof(int));
    printf("Merged dst4\n");
    print(dst4, SIZE4);
    printf("OUTPUT : %d\n", dst4[SIZE4/2]);
    printf("========================================================\n");


}

void print(int num[], int s){      //print all elements of array.
    printf(">>>>>\t");
    for(int i=0; i<s; i++){
        printf("%d\t", num[i]);
    }
    printf("\n");
}

void merge(int data[], int left, int mid, int right, int size){
    int i = left, j = mid+1, k = left, l;
    int sorted[size];

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

void merge_sort(int data[], int left, int right, int size){   //merge sort by recursion
    int mid;
    if(left<right){
        mid = (left+right)/2;   //calculate the middle of array. 중간 위치 계산
        merge_sort(data, left, mid, size);    //merge sort of left array by middle. 중간 기준 왼쪽배열 정렬
        merge_sort(data, mid+1, right, size); //merge sort of right array by middle. 중간 기준 오른쪽배열 정렬
        merge(data, left, mid, right, size);  //merge the sorted left and right array. 정렬해둔 왼,오 배열 합치기
    }
}   //출처 : https://gmlwjd9405.github.io/2018/05/08/algorithm-merge-sort.html

/*int chooseMid(int data[], int s){     //각 거리차의 합으로 최솟값을 구해보려고 했는데 너무 복잡해져서 포기...
    int sum[s]; //거리 차의 합을 저장
    int idx[s]; //거리 차의 합에 대응하는 인덱스 저장
    int result[s];
    int min=0;

    memset(sum, 0, s*sizeof(int));  //int sum[s] = {0, }으로 초기화가 안됨.

    for(int i=0; i<s; i++){
        for(int j=0; j<s; j++){
            sum[i] += pow((data[i]-data[j]), 2);    //각 거리의 차의 제곱을 구함.
        }
    }
    for(int i=0; i<s; i++){
        idx[i]=sum[i];
    }

    merge_sort(sum, 0, s-1);    //정렬하고 나면 가장 작은 수가 맨 앞에 정렬
    
    for(int i=0; i<s; i++){
        if(sum[i]==sum[i+1]){   //최솟값이 2개 이상일 경우
            for(int j=0; j<s; j++){ //그 최솟값에 해당하는 인덱스 찾기
                if(sum[i]==idx[j]){
                    result[i]=data[j+1];  //결과담는 배열에 원래 인덱스에 해당하는 값 넣기
                }
            }
        }
        else{
            for(int j=0; j<s; j++){
                if(sum[i]==idx[j])
                    result[i]=data[j+1];
            }
        } 
        
    }

}*/