
#include <stdlib.h>
#include <stdio.h>
#define T int

typedef struct  Node
{
    T data;
    struct Node * next;
    
    struct Node *back;
}Node , *LinkList;

//initialize the list
//set next NULL

void InitList(LinkList * l)
{
    *l = (Node*)malloc(sizeof(Node*));
    (*l)->next = *l;
    (*l)->back = NULL;
    
}

//create from tail

void CreateFromTail(LinkList l , T value)
{
    Node* p = (Node*)malloc(sizeof(Node*));
    p->data = value;
    p->back = NULL;
    Node* tail;
    tail = l;
    while(tail->next != l)tail = tail->next;
    tail->next = p;
    p->next = l;
}

//print all the elems

void PrintAll(LinkList l)
{
    Node* p;
    p = l;
    while( p->next != l)
    {
        p = p->next;
        printf("%d ",p->data);
    }
    printf("\n");
}


void toDLink(LinkList l){
	while(l->next->back == NULL){
		l->next->back = l;
		l = l->next;
	}
}

void testDList(LinkList l){
	int flag = 1;
	Node *p = l;
	while(p->next != l){
	    if(p->back == NULL)flag = 0;
	    p = p->next;
	}
	if(flag)printf("it is a DLinkList");
	else printf("it is not a DLinkList");
}
int main(){
	
	int i;
	LinkList l;
	InitList(&l);
	for( i = 0 ; i < 10 ; i ++)
	    CreateFromTail(l , i + 1);
	PrintAll(l);
    toDLink(l);
    testDList(l);
    }
    
	