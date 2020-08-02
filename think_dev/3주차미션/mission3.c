#include <stdio.h>
#include <string.h>
#include <ctype.h> 

#define MAX 10
#define TRUE 1
#define FALSE 0

int front = 0;
int rear = 0;
int queueArr[MAX];
int loopEnd = FALSE;

void enqueue(void);
void dequeue(void);
void quit(void);
void display(void);
int get_int(char *text);

int main(void) {
    while(!loopEnd) {
        int option = get_int("옵션번호를 입력하세요(1. enqueue, 2. dequeue, 3. display, 4. quit) : ");
        // getchar 는 stdin에있는 문자를 읽어들이는데 그러면 scanf 입력버퍼에 남아있던 \n 을 가져옴 != \n 처리를 한 이유는 그냥 getchar() 함수를 사용하면 띄어쓰기 이후에 남아있던 다른 문자까지 모두 가져와 입력버퍼에서 제거해버리기 때문에 필요한 비교구문
        while (getchar() != '\n');
        switch(option) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                quit();
                break;
            default:
                break;
        }
    }
    return 0;
}

void enqueue(void) {
    if ((rear + 1) % MAX == front) {
        printf("Queue가 꽉 찼습니다.\n");
    } else {
        int input_value = get_int("값을 입력해주세요 : ");
        rear = (rear + 1) % MAX;
        queueArr[rear] = input_value;
    }
}

void dequeue(void) {
    if (front == rear) {
        printf("Queue 가 비었습니다.\n");
    } else {
        front = (front + 1) % MAX;
        printf("%i\n", queueArr[front]);
    }
}

void display(void) {
    printf("==============================================================\n");
    printf("Queue에 남은값 : ");
    for(int i = front + 1; i < rear + 1; i++) {
        printf("%i ", queueArr[i]);
    }
    printf("\n");
    printf("==============================================================\n");
}

void quit(void) {
    printf("************************************************************\n");
    printf("Queue 프로그램 종료\n");
    printf("************************************************************\n");
    loopEnd = TRUE;
}



int get_int(char *text) {
    int getInt;
    printf("%s", text);
    scanf("%i", &getInt);
    return getInt;
}