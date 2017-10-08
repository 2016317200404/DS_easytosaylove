#include <stdio.h>
#include "../List/LinkList.h"

int findMax(LinkList l){
    Node *p = l;
    Node *max = l->next;//@csk    if max = l , max->data will be a random number , you should check again before debug
    while (p->next != NULL){
        p = p->next;
        if(p->data > max->data )max = p;
    }
    int maxNumber = max->data;
    delete(l , max);
    return maxNumber;
}

int main(){
    LinkList l;
    InitList(&l);
    printf("please enter the numbers , enter end to end\n");
    int temp;
    while (scanf("%d",&temp) && temp){
        if(temp == 'e' || temp == 'E')break;
        CreateFromTail(l , temp);
    }
    PrintAll(l);
    int max = findMax(l);
    printf("%d\n", max);
    PrintAll(l);
    return  0;
}