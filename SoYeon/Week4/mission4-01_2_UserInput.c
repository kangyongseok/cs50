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
    gets(all);  //input data. ������ �Է�
    strN1 = strtok(all, " "); //seperate the string before space. �����̽� ������ ���� ��� ��������
    strN2 = strtok(NULL, "");   //seperate the string after space. �����̽� ������ ���� ��� ��������

    N1 = atoi(strN1);   //convert string to integer. ���ڿ��� ���ڷ� ��ȯ
    N2 = atoi(strN2);

    convert(n1, N1);    //seperate the numbers by digits.���ڸ� �ڸ������� �迭�� �Է�
    convert(n2, N2);

    printf("=======================================================\n");
    printf("INPUT\n");
    print(n1);          //print input 1
    print(n2);          //print input 2

    printf("=======================================================\n");
    merge_sort(n1, 0, SIZE-1);    //merge sort of n1(input 1). n1�� �պ� ���� ����
    merge_sort(n2, 0, SIZE-1);    //merge sort of n2(input 2). n2�� �պ� ���� ����
    result = compare(n1, n2);   //compare two sorted inputs. ������ �� �迭 ��
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

void convert(int n[], int N){   //seperate the numbers by digits. �� �ڸ����� �迭�� �����ϴ� �Լ�

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

void merge_sort(int data[], int left, int right){   //merge sort by recursion
    int mid;

    if(left<right){
        mid = (left+right)/2;   //calculate the middle of array. �߰� ��ġ ���
        merge_sort(data, left, mid);    //merge sort of left array by middle. �߰� ���� ���ʹ迭 ����
        merge_sort(data, mid+1, right); //merge sort of right array by middle. �߰� ���� �����ʹ迭 ����
        merge(data, left, mid, right);  //merge the sorted left and right array. �����ص� ��,�� �迭 ��ġ��
    }
}   //��ó : https://gmlwjd9405.github.io/2018/05/08/algorithm-merge-sort.html

int compare(int n1[], int n2[]){    //compare the elements of two array.
    for(int i=0; i<SIZE; i++){
        if(n1[i]!=n2[i])
            return 1;
    }
}

