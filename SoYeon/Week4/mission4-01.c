#include <stdio.h>
#define SIZE 5

/////////////////////////////////////////////////////////////////////////////
////////////This program checks whether inputs have the same elements.///////
/////////////////////////////////////////////////////////////////////////////
void print(int num[]);
int compare(int n1[], int n2[]);

int main(void){
    int n1[SIZE] = {1, 4, 2, 5, 9};     //fixed input 1
    int n2[SIZE] = {9, 2, 4, 5, 2};     //fixed input 2
    int result;
    
    printf("INPUT\n");
    print(n1);      //print input
    print(n2);      //print input

    printf("=======================================================\n");
    result = compare(n1, n2);   //compare inputs whether they have the same elements
    if(result == 0) printf("OUTPUT : True\n");
    else printf("OUTPUT : False\n");

}

void print(int num[]){          //print array element
    printf(">>>>>\t");
    for(int i=0; i<SIZE; i++){
        printf("%d\t", num[i]);
    }
    printf("\n");
}

int compare(int n1[], int n2[]){    //compare two array
    int flag = 0;

    for(int i=0; i<SIZE; i++){      //the standard is the element of input 1
        for(int j=0; j<SIZE; ){
            if(n1[i] != n2[j])      
                j++;
            else{
                flag += 1;          //flag gets +1 when there are the same elements with input 1 in input2
                break;
            }
        }
    }
    if(flag == SIZE) return 0;      //If the flag is same with size of input 1, input 1 and input 2 have the same element.
    else return 1;
}   //But, this function can't check when there are duplicated elements in input 1 and 2.