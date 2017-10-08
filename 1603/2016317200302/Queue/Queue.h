//
// Created by asus on 2017/10/7.
//

#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H

#include <stdlib.h>
#define T int
typedef struct Node{
    T data;
    struct Node* next;
}Node;

//define queue head
typedef struct{
    Node* front;
    Node* rear;
}Queue;

//initialize the empty queue

void InitQueue(Queue *l){
    l->front = (Node*)malloc(sizeof(Node));
    l->rear = l->front;
    l->front->next = NULL;
}

//enter the queue

void enter(Queue *l , T c){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = c;
    l->rear->next = p;
    l->rear = p;
    p->next = NULL;
}

//delete from the queue

void delete(Queue *l){
    Node *p;
    if(l->front->next != NULL){
        if(l->rear == l->front->next)l->rear = l->front;
        p = l->front->next;
        l->front->next =p->next;
        free(p);
    }
}

//get a element data from the queue

T get(Queue l){
    return l.front->next->data;
}

//is empty

int isEmpty(Queue l){
    return l.front->next == NULL;
}

//get the size of the queue

int sizeofQueue(Queue l){
    int counter = 0;
    Node *p = l.front;
    while (p->next != NULL){
        p = p->next;
        counter ++;
    }
    return counter;
}
//functions for the Stack

#endif //DATASTRUCTURE_QUEUE_H
