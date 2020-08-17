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
    // �� �κ��� ������ �ּ���!
    StackNode* item = createStackNode(data);    //���ڷ� ���� ���� ������ ��� 1�� ����

    if(*root == NULL){  //root�� ù ��带 ������ ��
        *root = item;   //���ڷ� ���� ��带 �״�� ����
        printf("%d pushed to stack\n", item->data);
        return;
    }
    //root�� �ι�° �̻��� ��带 ������ ��
    item->next = *root;  //���ο� ��尡 ��Ʈ�� ����Ű�� ��带 ����Ű���� ����
    *root = item;        // ��Ʈ�� �߰��� ���ο� ��带 ����Ű�� LIFO ���� ����
    printf("%d pushed to stack\n", item->data);
}

int pop(StackNode** root) {
    if (isEmpty(*root))     //������ ��������� -9999 ��ȯ
        return -9999;
    int popped;
    // �� �κ��� ������ �ּ���!
    popped = (*root)->data; //pop�� ���� ���� ������ root�� ����Ű�� data ����
    (*root) = (*root)->next;    //root�� ����Ű�� ����� ���� ��带 �ٽ� root�� ����(pop�� ��� ������)
    return popped;
}

int peek(StackNode** root) {
    if (isEmpty(*root))
        return -9999;
    return (*root)->data;   //top ��ȯ�� root�� data�� �ϹǷ� root�� ����� ���� ���ÿ��� �ֻ����� ��ġ
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