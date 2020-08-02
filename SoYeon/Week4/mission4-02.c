#include <stdio.h>
//#include <math.h> //pow(����) ����ϱ� ���� ��.
//#include <string.h> //memset �Լ� ���
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

    while(i<=mid && j<=right){  //starting from the 1st elements of left and right array. ���ʹ迭, �����ʹ迭 ���� ó������ ������
        if(data[i]<=data[j])    //If element of left array is smaller than elements of right array. ���ʹ迭�� ���Ұ� �����ʹ迭�� ���Һ��� �۴ٸ�
            sorted[k++] = data[i++];    //store the smaller elements in the temporary array. �ӽù迭�� ���� ���� ����
        else                    //if element of right array is smaller than elements of left array. ������ �迭�� ���Ұ� ���ʹ迭�� ���Һ��� �۴ٸ� 
            sorted[k++] = data[j++]; //store the smaller elements in the temporary array. �ӽù迭�� ���� ���� ����
    }

    if(i>mid){      //copy all left elements of right array to temporary array. �����ִ� ���� �ϰ�����. ������ �迭�� �����ִ� ���� �ϰ�����
        for(l=j; l<=right; l++){
            sorted[k++] = data[l];
        }
    }
    else{           //copy all left elements of left array to temporary array. �����ִ� ���� �ϰ�����. ���ʹ迭�� �����ִ� ���� �ϰ�����
        for(l=i; l<=mid; l++){
            sorted[k++] = data[l];
        }
    }

    for(l=left; l<=right; l++){     //copy all elements of temporary array to original array(n1, n2). �ӽ� �迭�� ���� �迭�� ����
        data[l] = sorted[l];
    }
}

void merge_sort(int data[], int left, int right, int size){   //merge sort by recursion
    int mid;
    if(left<right){
        mid = (left+right)/2;   //calculate the middle of array. �߰� ��ġ ���
        merge_sort(data, left, mid, size);    //merge sort of left array by middle. �߰� ���� ���ʹ迭 ����
        merge_sort(data, mid+1, right, size); //merge sort of right array by middle. �߰� ���� �����ʹ迭 ����
        merge(data, left, mid, right, size);  //merge the sorted left and right array. �����ص� ��,�� �迭 ��ġ��
    }
}   //��ó : https://gmlwjd9405.github.io/2018/05/08/algorithm-merge-sort.html

/*int chooseMid(int data[], int s){     //�� �Ÿ����� ������ �ּڰ��� ���غ����� �ߴµ� �ʹ� ���������� ����...
    int sum[s]; //�Ÿ� ���� ���� ����
    int idx[s]; //�Ÿ� ���� �տ� �����ϴ� �ε��� ����
    int result[s];
    int min=0;

    memset(sum, 0, s*sizeof(int));  //int sum[s] = {0, }���� �ʱ�ȭ�� �ȵ�.

    for(int i=0; i<s; i++){
        for(int j=0; j<s; j++){
            sum[i] += pow((data[i]-data[j]), 2);    //�� �Ÿ��� ���� ������ ����.
        }
    }
    for(int i=0; i<s; i++){
        idx[i]=sum[i];
    }

    merge_sort(sum, 0, s-1);    //�����ϰ� ���� ���� ���� ���� �� �տ� ����
    
    for(int i=0; i<s; i++){
        if(sum[i]==sum[i+1]){   //�ּڰ��� 2�� �̻��� ���
            for(int j=0; j<s; j++){ //�� �ּڰ��� �ش��ϴ� �ε��� ã��
                if(sum[i]==idx[j]){
                    result[i]=data[j+1];  //������ �迭�� ���� �ε����� �ش��ϴ� �� �ֱ�
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