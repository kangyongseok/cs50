#include <stdio.h>
#define MAX 10

int front = 0;
int rear = 0;
int queue[MAX] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};  //-1 in queue means empty. int queue[MAX] = {-1,} does not work.

void Add(int n);
void pop();
void display();

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
                    printf(">>>>>Please type the number which you want to input to Queue : ");
                    scanf("%d", &add);
                    Add(add);
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    return 0;
                default:
                    printf(">>>>>please input valide number.\n");
                    break;
            }
    }
}

void Add(int n){
    if(queue[rear] != -1){    //when queue is full. 
        printf(">>>>>Queue is full.\n");
    }
    else{
        queue[rear] = n;    
        rear+=1;
        if(rear == MAX) rear = rear % MAX;  //if rear is over the end of array index, go back to the front of array.
        printf(">>>>>%d is added in Queue.\n", n);
    }

}

void pop(){
    if(rear == front && queue[rear] == -1){ //when queue is empty. 
        printf(">>>>>Queue is empty.\n");
    }
    else {
        if(rear == MAX){    //when rear is bigger than MAX
            rear = rear % MAX;
        }
        printf("%d is poped!\n", queue[front]);
        queue[front] = -1;
        front += 1;
        if(front == MAX){   //when front is over the end of array index, go back to the front of array.
            front = front % MAX;
        }
    }
}

void display(){
        for(int i=front; i<MAX+front; i++){     //Just print all elements of queue with no cares that where is the front and rear.
            printf("%d ", queue[i%MAX]);
        }
        printf("\n");    
}

/*void quit(){

}*/