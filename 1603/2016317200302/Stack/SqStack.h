//
// Created by asus on 2017/9/12.
//

#ifndef DATASTRUCTURE_SQSTACK_H
#define DATASTRUCTURE_SQSTACK_H

#include <stdio.h>

#define MAX_SIZE 100
#define T int

typedef struct {
    T a[MAX_SIZE];
    int top;
}SqStack;

//initialize the stack
void InitStack(SqStack* s){
    s->top = -1;
}

//push
void push(SqStack* s , T value){
    if(s->top + 1 < MAX_SIZE){
        s->a[++ s->top] = value ;
    } else{
        printf("the stack is full ! \n");
    }
}

//pop
T pop(SqStack*s){
    if(s->top != -1)
    return s->a[s->top --];
    else{
        printf("the stack is empty !\n");
        return  NULL;
    }
}

#endif //DATASTRUCTURE_SQSTACK_H
