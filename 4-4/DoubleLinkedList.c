#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoubleLinkedList.h"


linkedList_h* createLinkedList_h(void) {
    linkedList_h* DL;

    DL = (linkedList_h*)malloc(sizeof(linkedList_h));
    DL->head = NULL;

    return DL;
}

void printList(linkedList_h* DL) {
    listNode* p;

    printf("DL = (");

    p = DL->head;

    while (p != NULL) {
        printf("%s", p->data);

        p = p->rlink;

        if (p != NULL)
            printf(", ");
    }

    printf(")\n");
}

void insertNode(linkedList_h* DL, listNode* pre, char* x) {
    listNode* newNode;

    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);

    if (DL->head == NULL || pre == NULL) {
        newNode->llink = NULL;
        newNode->rlink = DL->head;

        if (DL->head != NULL)
            DL->head->llink = newNode;

        DL->head = newNode;
    }
    else {
        newNode->rlink = pre->rlink;
        newNode->llink = pre;

        if (pre->rlink != NULL)
            pre->rlink->llink = newNode;

        pre->rlink = newNode;
    }
}

void deleteNode(linkedList_h* DL, listNode* old) {
    if (DL->head == NULL || old == NULL)
        return;

    if (old == DL->head) {
        DL->head = old->rlink;
    }

    if (old->llink != NULL)
        old->llink->rlink = old->rlink;

    if (old->rlink != NULL)
        old->rlink->llink = old->llink;

    free(old);
}

listNode* searchNode(linkedList_h* DL, char* x) {
    listNode* temp;

    temp = DL->head;

    while (temp != NULL) {
        if (strcmp(temp->data, x) == 0)
            return temp;
        else
            temp = temp->rlink;
    }

    return temp;
}
