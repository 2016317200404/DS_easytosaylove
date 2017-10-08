#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#define T char

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

void PrintAll(LinkList l){
    Node *p = l;
    while (p->next != l && p->next != NULL){
        p = p->next;
        printf("%c ",p->data);
    }

    printf("\n");
}

void classifyList(LinkList numberList , LinkList charList , LinkList otherList , LinkList l){
    Node *n , *c , *o;
    n = numberList;
    c = charList;
    o = otherList;
    Node *p = l;
    while (l->next != NULL){
        p = l->next;
        l->next = p->next;
        if(isdigit(p->data)){
            n->next = p;
            p->next = numberList;
            n = p;
        }else if(isalpha(p->data)){
            c->next = p;
            p->next = charList;
            c = p;
        } else{
            o->next = p;
            p->next = otherList;
            o = p;
        }
    }
}
int main(){
    LinkList l;
    InitList(&l);
    printf("please enter some characters\n");
    char temp;
    getchar();
    while ((temp = getchar()) != '\n'){
        CreateFromTail(l , temp);
    }
    PrintAll(l);
    LinkList numberList , charList , otherList;
    InitList(&numberList);
    InitList(&charList);
    InitList(&otherList);
    classifyList(numberList , charList , otherList , l);
    PrintAll(numberList);
    PrintAll(charList);
    PrintAll(otherList);
    return 0;
}