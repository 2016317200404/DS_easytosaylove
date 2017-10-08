//链表终极版
#include<bits/stdc++.h>
using namespace std;
struct List
{
    List *Next;
    int data;
    List(int _data)
    {
        data=_data;
        Next=NULL;
    }
}*head,tail;//head:头指针
void insert_head(int x)//头插法
{
    List *temp=head;
    List *p=new List(x);
    head=p;
    p->Next=temp;
    return ;
}
void insert_tail(int x)//尾插法
{
    List *p=new List(x);
    tail->Next=p;
    tail=p;
    return ;
}
void find_num(int num)//根据值查找
{
    List *p=head;
    while(p)
}
void find_pos(int pos)//根据位置查找
{

}
void List_delete_num(int pos)//根据值删除

}
void List_delete_pos(int pos)//根据位置删除
{

}
void update(int pos,int x)//修该pos位置的数为x
{

}
void List_clear()//清空list，释放空间，避免内存泄露
{

}
int main()
{

}
