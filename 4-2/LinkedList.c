#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


void deleteNode(linkedList_h* L, listNode* p) {
    listNode* pre;                    
    if (L->head == NULL) return;     
    if (L->head->link == NULL) {     
        free(L->head);               
        L->head = NULL;              
        return;
    }
    else if (p == NULL) return;       
    else {                            
        pre = L->head;
        while (pre->link != p) {
            pre = pre->link;
        }
        pre->link = p->link;          
        free(p);                      
    }
}

listNode* searchNode(linkedList_h* L, char* x) {
    listNode* temp;
    temp = L->head;
    while (temp != NULL) {
        if (strcmp(temp->data, x) == 0) return temp;
        else temp = temp->link;
    }
    return temp;
}

void reverse(linkedList_h* L) {
    listNode* p;
    listNode* q;
    listNode* r;

    p = L->head;                     
    q = NULL;
    r = NULL;

    while (p != NULL) {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    L->head = q;
}
