//
// Created by asus on 2017/9/10.
//

#ifndef DATASTRUCTURE_LINKLIST_H
#define DATASTRUCTURE_LINKLIST_H


//define the struct

#include <stdlib.h>
#include <stdio.h>
#define T int

typedef struct  Node
{
    T data;
    struct Node * next;
}Node , *LinkList;

//initialize the list
//set next NULL

void InitList(LinkList * l)
{
    *l = (Node*)malloc(sizeof(Node*));
    (*l)->next = NULL;
}

//create from head


void CreateFromHead(LinkList l , T value)
{
    Node* p = (Node*)malloc(sizeof(Node*));
    p->data = value;
    if( l->next == NULL)
    {
        l->next = p;
        p->next = NULL;
    }
    else
    {
        p->next = l->next;
        l->next = p;
    }
}

//create from tail

void CreateFromTail(LinkList l , T value)
{
    Node* p = (Node*)malloc(sizeof(Node*));
    p->data = value;
    Node* tail;
    tail = l;
    while(tail->next != NULL)tail = tail->next;
    tail->next = p;
    p->next = NULL;
}

//insert a elem to the list

int InseList(LinkList l , int index , T value)
{
    Node* s = (Node*)malloc(sizeof(Node*));
    s->data = value;
    Node* p = l;
    int  k;
    if( index < 1)printf("the index is too small !\n");
    else
    {
        for( k = 0 ; k < index - 1 ;)
        {
            if( p->next == NULL)
            {
                printf("the index is too large !\n");
                return 0;
            }
            else
            {
                p = p->next;
                k++;
            }
        }

    }
    s->next = p->next;
    p->next = s;
}

//print all the elems

void PrintAll(LinkList l)
{
    Node* p;
    p = l;
    while( p->next != NULL)
    {
        p = p->next;
        printf("%d ",p->data);
    }
    printf("\n");
}

//find the elem by value

int FindList(LinkList l , T value)
{
    Node* p;
    p = l;
    int index = 0;
    while( p->next != NULL)
    {
        p = p->next;
        index ++;
        if( p->data == value)return index;
    }
    return -1;
}
#endif //DATASTRUCTURE_LINKLIST_H
