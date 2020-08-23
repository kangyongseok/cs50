#include <stdio.h>
#include <stdlib.h>

// isEmpty 랑 peek 는 어디다 쓰라는건지?
// 지문에 나온 결과중에 마지막 -9999 는 대체 어디서 나온값인지?
// 채우라는 코드만 작성하라는건지 사용되지않은 사용자 함수까지 사용해보라는건지 뭐 명확하지가않음

typedef struct stack{
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity*sizeof(int));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity-1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

int pop(Stack* stack) {
    // 이곳을 채워주세요!
    return stack->array[stack->top--];
}

int peek(Stack* stack) {
    // 이곳을 채워주세요!
    printf("peek");
}

int main() {
    Stack* stack = createStack(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));

    push(stack, 50);
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    return 0;
}