//
// Created by asus on 2017/9/13.
//

#ifndef DATASTRUCTURE_DLINKLIST_H
#define DATASTRUCTURE_DLINKLIST_H

#include <stdlib.h>

#define  T int

typedef struct Node {
    T data;
    struct Node* prior;
    struct Node* next;
}Node , *DLinkList;

//initialize the list

void InitList(DLinkList *l ){
    *l = (Node*) malloc(sizeof(Node));
    (*l)->next = *l;
    (*l)->prior = *l;
}

//create from head

void CreateFromHead(DLinkList l , T value){
    Node *p = (Node*) malloc(sizeof(Node));
    p->data = value;
    if( l->next == l && l->prior == l){
        l->next = p;
        l->prior = p;
        p->next = l;
        p->prior = l;
    } else{
        p->next = l->next;
        p->prior = l;
        l->next = p;
    }
}

//create from tail

void CreateFromTail(DLinkList l , T value){
    Node *p = (Node*) malloc(sizeof(Node));
    Node *temp = l->prior;
    p->data = value;
    p->prior = temp;
    p->next = l;
    temp->next = p;
}



#endif //DATASTRUCTURE_DLINKLIST_H
