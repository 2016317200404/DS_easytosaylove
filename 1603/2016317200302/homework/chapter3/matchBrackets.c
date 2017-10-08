
#include <stdio.h>
#include <stdlib.h>
#define N 100
#define T char
#define A '('
#define B '{'
#define C '['
#define X ')'
#define Y '}'
#define Z ']'
typedef struct Node {
    T data;
    struct Node* next;
}Node , *LinkStack;    //@csk    * before Stack

void InitStack(LinkStack *top){
    *top = (Node*)malloc(sizeof(Node*));
    (*top)->next = NULL;
}

void push(LinkStack top , T value){
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

T  pop(LinkStack top){
    if(top->next != NULL){
        T value;
        Node* p = top->next;
        top->next = p->next;
        value = p->data;
        free(p);
        return value;
    }
    return NULL;
}

int isEmpty(LinkStack top){
    return top->next == NULL;
}


void matchBracket(char string[]){
    LinkStack stack;
    InitStack(&stack);
    int i = 0;
    char test;
    while (string[i] != '\0'){
        switch (string[i]){
            case A:
            case B:
            case C:
                push(stack , string[i]);
                break;
            case X:
                if(isEmpty(stack)){
                    printf("there are too many right brackets\n");
                    return;
                }
                else if((test =  pop(stack) ) != A){
                    printf("not the same type of bracket\n");
                    return;
                }

                break;
            case Y:
                if(isEmpty(stack)){
                    printf("there are too many right brackets\n");
                    return;
                }
                else if((test =  pop(stack) )!= B){
                    printf("not the same type of bracket\n");
                    return;
                }
                break;
            case Z:
                if(isEmpty(stack)){
                    printf("there are too many right brackets\n");
                    return;
                }
                else if((test =  pop(stack) ) != C){
                    printf("not the same type of bracket\n");
                    return;
                }
                break;
            default:
                break;
        }
       i ++;
    }
    if(! isEmpty(stack))printf("there are too many left brackets\n");
    else printf("perfect\n");
}

int main(){
    char string[N];
    printf("please enter the brackets string\n");
//    getchar();     @csk why will you get the first character ? I think you just get '\n'
    gets(string);
    matchBracket(string);
    return  0;
}