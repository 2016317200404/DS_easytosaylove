#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SIZE 3
#define T Car

//define the car to store the data of a car

typedef struct Car{
    long id;
    time_t arrive;
    time_t leave;
}Car;

//define a Car for queue

typedef struct Node{
    T car;
    struct Node* next;
}Node;

//define queue head
typedef struct{
    Node* front;
    Node* rear;
}Queue;

//define sqstack

typedef struct {
    T a[MAX_SIZE];
    int top;
}SqStack;

//functions for queue

//initialize the empty queue

void InitQueue(Queue *l){
    l->front = (Node*)malloc(sizeof(Node));
    l->rear = l->front;
    l->front->next = NULL;
}

//enter the queue

void enter(Queue *l , T c){
    Node *p = (Node*)malloc(sizeof(Node));
    p->car = c;
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
  //  printf("debug get: car is :%ld" , (l.front->next->car).id);
    return l.front->next->car;
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
        return s->a[0];
    }
}

//is full
int isFull(SqStack l){
    return l.top >= MAX_SIZE - 1;
}

//size of the sqstack

int sizeofStack(SqStack l){
    return l.top + 1;
}

//initialize the car

void InitCar(Car *c){
    c->arrive = c->leave = c->id = -1;
}

Car leave(SqStack *s , Car c , SqStack *temp){
    Car c1;
    InitCar(&c1);
    while (s->top != -1 ){
      //  printf("debug leave: top = %d\n" , s->top);
        if((s->a[s->top]).id == c.id){
            c1 = pop(s);
            c1.leave = c.leave;
            return c1;
        }
        push(temp , pop(s));
    }
    return c1;
}

void fee(Car c){
    int hour = (int)(difftime(c.leave ,c.arrive)/3600);
   printf("park %d seconds , cost %d $\n" , (int)difftime(c.leave , c.arrive) , hour);
}

void comeBack(SqStack *s , SqStack *temp){
    while (temp->top != -1){
      // printf("debug comeBack:top = %d\n" , s->top);
        push(s , pop(temp));
    }
}
int main(){
    Car c;
    Queue q;
    SqStack s , temp;
    InitCar(&c);
    InitQueue(&q);
    InitStack(&s);
    InitStack(&temp);
    //get the car information , 1 stands for arrive , 0 stands for leave
    //use time function to get the time
    int flag;
    Car leaveCar , arriveCar;
    while (scanf("%ld%d" , &c.id , &flag) && c.id > 0){
        if(flag){
            if(isFull(s)){
                enter(&q , c);
                printf("on the shortcut : %d" ,  sizeofQueue(q));
               //printf("%ld\n" , c.arrive);
            } else{
                time(&c.arrive);
                push(&s , c);
                printf("on the parking lot : %d" ,sizeofStack(s));
               // printf("%ld\n" , c.arrive);
            }
        } else{
            time(&c.leave);
            //the car leave the parking lot
            leaveCar = leave(&s , c , &temp);
            if(leaveCar.id == -1)printf("this car is not on the parking lot\n");
            else{
                //calculate the fee of parking
                //1 dollar per hour
                fee(leaveCar);
            }
                //all the cars thtr give way to the leaving car come back to the parking lot
                comeBack(&s , &temp);
            if(!isEmpty(q) && !isFull(s)){
                arriveCar = get(q);
                delete(&q);
                time(&arriveCar.arrive);
                push(&s ,arriveCar);
            }
        }
    }
    return 0;
}