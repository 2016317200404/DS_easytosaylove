//
// Created by asus on 2017/9/11.
//

#ifndef DATASTRUCTURE_LINKSTACK_H
#define DATASTRUCTURE_LINKSTACK_H

#include <malloc.h>
#include <stdio.h>
#define T int

typedef struct Node {
    T data;
    struct Node* next;
}Node , *LinkStack;    //@csk    * before Stack

void InitStack(LinkStack *top){
    *top = (Node*)malloc(sizeof(Node*));
    (*top)->next = NULL;
}

void pushStack(LinkStack top , T value){
    Node*p = (Node*) malloc(sizeof(Node*));
    p->data = value;
    if(top->next == NULL){
        top->next = p;
        p->next = NULL;
    }
    else{
        p->next = top->next;
        top->next = p;
    }
}

int  popStack(LinkStack top){
    if(top->next != NULL){
        T value;
        Node* p = top->next;
        top->next = p->next;
        value = p->data;
        free(p);
        return value;
    }
}



#endif //DATASTRUCTURE_LINKSTACK_H
