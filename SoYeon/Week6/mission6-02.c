#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode {
    int data;
    struct stackNode* next;
} StackNode;

StackNode* createStackNode(int data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = data;
    node->next = NULL;
    return node;
}

int isEmpty(StackNode* root) {
    return !root;
}

void push(StackNode** root, int data) {
    // 이 부분을 구현해 주세요!
    StackNode* item = createStackNode(data);    //인자로 들어온 값을 가지는 노드 1개 생성

    if(*root == NULL){  //root가 첫 노드를 연결할 때
        *root = item;   //인자로 들어온 노드를 그대로 연결
        printf("%d pushed to stack\n", item->data);
        return;
    }
    //root가 두번째 이상의 노드를 연결할 때
    item->next = *root;  //새로운 노드가 루트가 가리키던 노드를 가리키도록 설정
    *root = item;        // 루트는 추가된 새로운 노드를 가리키며 LIFO 구조 형성
    printf("%d pushed to stack\n", item->data);
}

int pop(StackNode** root) {
    if (isEmpty(*root))     //스택이 비어있으면 -9999 반환
        return -9999;
    int popped;
    // 이 부분을 구현해 주세요!
    popped = (*root)->data; //pop할 값이 들어가는 변수에 root가 가리키는 data 저장
    (*root) = (*root)->next;    //root가 가리키던 노드의 다음 노드를 다시 root에 저장(pop한 노드 버리기)
    return popped;
}

int peek(StackNode** root) {
    if (isEmpty(*root))
        return -9999;
    return (*root)->data;   //top 반환을 root의 data로 하므로 root랑 연결된 노드는 스택에서 최상위에 위치
}

int main() {
    StackNode* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    push(&root, 40);

    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));

    push(&root, 50);
    printf("%d peeked from stack\n", peek(&root));
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));
    return 0;
}