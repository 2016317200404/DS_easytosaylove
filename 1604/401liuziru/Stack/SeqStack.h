#include<stdio.h>
#include<stdlib.h>
#define Stack_Size 50
#define false 0
#define true 1
/*顺序栈*/
typedef struct{
    char e[Stack_Size];
    int top;
}SeqStack;

void InitStack(SeqStack *S){
    S->top=-1;
}

int Push(SeqStack *S,char x){
    if(S->top==Stack_Size-1) return false;
    S->top++;
    S->e[S->top]=x;
    return true;
}

int Pop(SeqStack *S,char *x){
    if(S->top==-1) return false;
    *x=S->e[S->top];
    S->top--;
    return true;
}

int GetTop(SeqStack *S,char *x){
    if(S->top==-1) return false;
    *x=S->e[S->top];
    return true;
}

/*END*/
