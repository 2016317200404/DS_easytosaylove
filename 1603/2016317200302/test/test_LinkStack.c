#include "../Stack/LinkStack.h"
#include <stdio.h>

int main()
{
    LinkStack l;
    InitStack(&l);
    int i;
    for( i = 0 ; i < 10 ; i ++){
        pushStack(l , i + 1);
    }
    for( i = 0 ; i < 10 ; i ++){
        printf("%d " , popStack(l));
    }
    return  0;
}
