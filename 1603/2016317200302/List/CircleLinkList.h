//
// Created by asus on 2017/9/12.
//

#ifndef DATASTRUCTURE_CIRCLELINKLIST_H
#define DATASTRUCTURE_CIRCLELINKLIST_H


#include<stdlib.h>
#include<stdio.h>
#define T int

typedef struct Node
{
    T data;
    struct Node* next;
}Node  , *CLinkList;

//initialize the list

void InitCList(CLinkList  *l)
{
    *l = (Node*)malloc(sizeof(Node*));//do not miss * , because l is a pointer of Node*
    (*l)->next = *l;
}

//create from head

void  CreateFromHeadCList(CLinkList l , T value)
{
    Node* p = (Node*)malloc(sizeof(Node*));
    p->data = value;
    p->next = l;
    if(l->next == l)
        l->next = p;
    else
    {
        p->next = l->next;
        l->next = p;
    }
}

//create from tail

void CreateFromTailCList(CLinkList l , T value)
{
    Node* p = (Node*)malloc(sizeof(Node*));
    p->data = value;
    p->next = l;
    Node* temp = l;
    while(temp->next != l)temp = temp->next;
    temp->next = p;
}

//print all the elems in the list

void PrintAllC(CLinkList l)
{
    Node *p = l;
    while(p->next != l)
    {
        p = p->next;
        printf("%d ",p->data);
    }
    printf("\n");
}



#endif //DATASTRUCTURE_CIRCLELINKLIST_H
