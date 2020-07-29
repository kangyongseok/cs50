#include <stdio.h>
#include <string.h> //using for strcmp
#include<stdlib.h>  //using for malloc, free
#define MAX 10

int front = 0;  //front of queue. 큐의 머리
int rear = 0;   //rear of queue. 큐의 꼬리
char *queue[MAX] = {"-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1"};  //-1 in queue means empty. declare pointer array for putting string into queue. 문자열을 넣기 위해 포인터 배열로 선언

int Add();
void pop();
void display();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////This is Cirular-Queue Program. You can input not only string but also integer.//////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(void){
    while(1){
            int input = 0;
            int add = 0;
            printf("This is Queue program. -1 means the queue is empty.\n");
            printf("1.add\t2.pop\t3.display\t4.quit\n");
            printf("\t*add : Add the number which you type into the Queue\n");
            printf("\t*pop : Pop the number at the front of Queue\n");
            printf("\t*display : Print all elements of Queue\n");
            printf("\t*quit : Exit this program\n");
            printf("Type the number which you want to execute : ");
            scanf("%d", &input);
            printf("=========================================================================================\n");
            switch(input){
                case 1:
                    Add();
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    display();
                    break;
                case 4:         //바로 프로그램 종료
                    return 0;
                default:
                    printf(">>>>>please input valide number.\n");
                    break;
            }
            printf("\n");
    }
}

int Add(){
    int size;
    char *add;

    printf(">>>>>type the size of string you will enter : ");
    scanf("%d", &size); 

    add = malloc(sizeof(char)*size);   
        
    printf(">>>>>Please type the number which you want to input to Queue : ");
    scanf("%s", add);


    if(strcmp(queue[rear], "-1") != 0){     //when queue is full. rear가 가리키는 곳이 -1이 아니면 내용물이 있는 것.
        printf(">>>>>Queue is full.\n");
        free(add);        
    } else{
        queue[rear] = add;    
        rear+=1;
        if(rear == MAX) rear = rear % MAX;  //if rear is over the end of array index, go back to the front of array.
                                            //원형큐를 만들기 위한 조건. rear가 배열크기가 됐을 때 배열 처음으로 돌려줌.
        printf(">>>>>%s is added in Queue.\n", add);
        free(add);
        }
}

void pop(){
    if(rear == front && (strcmp(queue[rear], "-1")==0) ){    //when queue is empty. rear와 front가 같고 rear가 가리키는 곳이 비어있을 때
        printf(">>>>>Queue is empty.\n");
    }
    else {
        if(rear == MAX){    //when rear is bigger than MAX. 
            rear = rear % MAX;  //원형큐 만들기 위한 조건.
        }
        printf("%s is poped!\n", queue[front]);
        queue[front] = "-1";
        front += 1;
        if(front == MAX){   //when front is over the end of array index, go back to the front of array.
                            //원형큐를 만들기 위한 조건. front가 배열크기와 같을 때 배열 처음으로 돌려줌.
            front = front % MAX;
        }
    }
}

void display(){
        for(int i=front; i<MAX+front; i++){     //Just print all elements of queue with no cares that where is the front and rear.
            printf("%s\t", queue[i%MAX]);
        }
        printf("\n");    
}

/*void quit(){

}*/
