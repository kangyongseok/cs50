#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

void append(Node* head, int data) {
    // �� �κ��� �ۼ��� �ּ���!
    Node* item = (Node*)malloc(sizeof(Node));   //���ڷ� ���� data�� ������ ��� ����
    item->data = data;
    item->next = NULL;

    if(head->next == NULL){     //head�� ������ ù��° �����
        head->next = item;      //head�� next�� �ٷ� ����
        return;
    }
    Node *temp = (Node*)malloc(sizeof(Node));   //�ӽ� ��� ����
    temp = head;                
    while(temp->next != NULL){  //������ ������ �ݺ�
        temp = temp->next;          //���� ���� �̵�
    }
    temp->next = item;          //������ ����� next�� �� ��� ����
}

int getLastNode (Node* head, int k) {
    // �� �κ��� �ۼ��� �ּ���!
    int size=0;     //���Ḯ��Ʈ�� �� ��� ����
    int count=0;    //ù������ k��° �������� ���� ī��Ʈ

    Node* tmp;      //��� �̵��� �ӽ� ������
    for(tmp = head->next; tmp!=NULL; tmp=tmp->next){    //����� �� ���� ���ϱ�. ���� �����Ͱ� ����ִ� head ������ ������ ����.
        size++;
    }
    tmp=head;       //�ӽ� �����Ͱ� �ٽ� head�� ���� ���� ������
    while(count != size-k+1){       //�ڿ��� k��° = ù������ (size-k+1)��°�� �Ǹ� �ݺ��� Ż��
        tmp = tmp->next;            //���� ���� �̵�
        count++;                    //���� ���� �̵��� ������ count ����
    }
    return tmp->data;
}

void printList(Node* head) {
    // �� �κ��� �ۼ��� �ּ���!
    for(Node *tmp=head->next; tmp!=NULL; tmp=tmp->next){
        printf("%d\t", tmp->data);
    }
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;  //�� ������ ���� �ʰ� �ذ��� �� �ִ��� �ǹ�
    
    append(head, 9);
    append(head, 8);
    append(head, 4);
    append(head, 14);
    append(head, 5);

    printList(head);

    printf("\n%dth last node is %d\n", 2, getLastNode(head, 2));
}