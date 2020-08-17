#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

void append(Node* head, int data) {
    // 이 부분을 작성해 주세요!
    Node* item = (Node*)malloc(sizeof(Node));   //인자로 들어온 data를 가지는 노드 생성
    item->data = data;
    item->next = NULL;

    if(head->next == NULL){     //head와 연결할 첫번째 노드라면
        head->next = item;      //head의 next에 바로 연결
        return;
    }
    Node *temp = (Node*)malloc(sizeof(Node));   //임시 노드 생성
    temp = head;                
    while(temp->next != NULL){  //마지막 노드까지 반복
        temp = temp->next;          //다음 노드로 이동
    }
    temp->next = item;          //마지막 노드의 next에 새 노드 연결
}

int getLastNode (Node* head, int k) {
    // 이 부분을 작성해 주세요!
    int size=0;     //연결리스트의 총 노드 개수
    int count=0;    //첫노드부터 k번째 노드까지를 세는 카운트

    Node* tmp;      //노드 이동할 임시 포인터
    for(tmp = head->next; tmp!=NULL; tmp=tmp->next){    //노드의 총 개수 구하기. 실제 데이터가 들어있는 head 다음의 노드부터 시작.
        size++;
    }
    tmp=head;       //임시 포인터가 다시 head와 같은 값을 갖도록
    while(count != size-k+1){       //뒤에서 k번째 = 첫노드부터 (size-k+1)번째가 되면 반복문 탈출
        tmp = tmp->next;            //다음 노드로 이동
        count++;                    //다음 노드로 이동할 때마다 count 증가
    }
    return tmp->data;
}

void printList(Node* head) {
    // 이 부분을 작성해 주세요!
    for(Node *tmp=head->next; tmp!=NULL; tmp=tmp->next){
        printf("%d\t", tmp->data);
    }
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;  //이 라인을 넣지 않고 해결할 수 있는지 의문
    
    append(head, 9);
    append(head, 8);
    append(head, 4);
    append(head, 14);
    append(head, 5);

    printList(head);

    printf("\n%dth last node is %d\n", 2, getLastNode(head, 2));
}