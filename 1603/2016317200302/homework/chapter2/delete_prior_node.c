#include <stdio.h>
#include "../List/CircleLinkList.h"


void delete(Node*s){
    Node *p = s;
    while (p->next->next != s)p = p->next;
    Node *temp = p->next;
    p->next = temp->next;
    free(temp);
}
int main(){
    CLinkList linkList;
    InitCList(&linkList);
    int i;
    for(i = 0 ; i < 10 ; i ++){
        CreateFromTailCList(linkList , i + 1);
    }
    Node *s;
    PrintAllC(linkList);
    int n;
    printf("please enter the number you want to delete\n");
    do{
        scanf("%d",&n);
        if(n < 1 || n > 10)printf("please enter again\n");
    }while (n < 1 || n > 10);
    //let s point to the position of n
    s = linkList;
    while(n--)s = s->next;
    //remove the head of the circle link list
    Node *p = linkList;
    while (p->next != linkList)p = p->next;
    p->next = linkList->next;
    delete(s);
    //print all the elements by using s
    Node*t = s;
    while (t->next != s){
        printf("%d ",t->data);
        t = t->next;
    }
    printf("%d\n",t->data);
    printf("then I delete the prior element of n\n");
    return 0;
}