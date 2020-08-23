#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}ListNode;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = (ListNode *)malloc(sizeof(ListNode));
    ListNode* pt = head;

    l1 = l1->next;
    l2 = l2->next;

    while (l1!=NULL && l2!=NULL) {
        if (l1->data <= l2->data) {
            pt->next = l1;
            l1 = l1->next;
        } else {
            pt->next = l2;
            l2 = l2->next;
        }
        pt = pt->next;
    }
    if (l1 != NULL)
        pt->next = l1;
    if (l2 != NULL)
        pt->next = l2;
    return head;
}

void append(ListNode* l, int data) {
    ListNode* item = (ListNode*)malloc(sizeof(ListNode));
    item->data = data;
    item->next = NULL;

    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));    
    temp = l;
    while(temp->next != NULL) {
        temp=temp->next;
    }
    temp->next = item;
}

void printList(ListNode* l) {
    while(l->next != NULL) {
        printf("%d ", l->next->data);
        l = l->next;
    }
    printf("\n");
}

int main() {
    ListNode* listA = (ListNode*)malloc(sizeof(ListNode));
    ListNode* listB = (ListNode*)malloc(sizeof(ListNode));

    append(listA, 2);
    append(listA, 6);
    append(listA, 9);
    append(listA, 10);
    printList(listA);

    append(listB, 1);
    append(listB, 5);
    append(listB, 7);
    append(listB, 8);
    append(listB, 11);
    printList(listB);

    ListNode* result = mergeTwoLists(listA, listB);
    printList(result);
}