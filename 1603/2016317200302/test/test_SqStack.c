#include <stdio.h>
#include "../Stack/SqStack.h"

int main(){
    int i ;
    SqStack s;
    InitStack(&s);
    for( i = 0 ; i < 10 ; i ++){
        push(&s , i + 1);
    }
    for( i = 0 ; i < 10; i ++){
        printf("%d ", pop(&s));
    }
    return 0;
}