#include<cstdio>
#include<cstring>
#include<stdlib.h>

typedef struct Node
{
    char data;
    struct Node *next;
}Node,*Linklist;

void init(Linklist *L)
{
    *L = (Linklist)malloc(sizeof(Node));
    (*L)->next = NULL;
}

void Creat(Linklist L)
{
    Node *s;
    char c;
    int flag = 1;
    printf("输入一串数字 “#”表示输入结束");
    while(flag){
        c = getchar();
        if(c != '#'){
            s = (Node*)malloc(sizeof(Node));
            s->data = c;
            s->next = L->next;
            L->next = s;
        }
        else flag = 0;
    }
}

char getmax(Linklist L)
{
    Node *s;
    s = (Node*)malloc(sizeof(Node));
    s = L->next;
    char temp = s->data;
    while(s->next != NULL){
        s = s->next;
        if(temp < s->data)
            temp = s->data;
    }
    printf("最大值为%c\n",temp);
    return temp;
}

void  dellist(Linklist L,char num)
{
        Node *pre,*r;
        pre = L;
        while(pre->next != NULL)
        {

            if(pre->next->data == num)
            {
                r = pre->next;
                pre->next = r->next;
                printf("%c已删除\n",r->data);
                free(r);
            }
            else{
                pre = pre->next;
            }
        }
}

int main()
{
    Linklist L;
    init(&L);
    Creat(L);
    char num;
    num = getmax(L);
    dellist(L,num);
    return 0;
}
