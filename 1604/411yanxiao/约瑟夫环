#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    int num;
    struct Node *next;
}Node, *Linklist;

void A(Linklist *L)
{
    *L=(Linklist)malloc(sizeof(Node));
    (*L)->next = *L;
}

void creat(Linklist L,int n)
{
    Node *s,*real;
    real = L;
    int num=0;
    int i;
    for( i = 0;i<n;i++)
    {
        s =(Node*)malloc(sizeof(Node));
        s->num = ++num;
        real->next = s;
        real = s;
    }
    real->next = L;
}

void getnum(Linklist L,int m)
{
  Node *s,*del;
  s = L;
  while(L->next!=L){
        int i;
    for( i = 0;i<m-1;i++)
    {
        s = s->next;
        if(s == L)
            s = s->next;
    }
    del = s->next;
    s->next = del->next;

    if(del == L){
        L = del->next;
        printf("%d",s->num);
    }
   else
    printf("%d ",del->num);
  free(del);
  }
  printf("\n");
}


int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    Linklist L;
    A(&L);
    creat( L,n);
    getnum( L,m);
    return 0;
}
