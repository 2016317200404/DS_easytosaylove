#include<iostream>
#include<list>
#include<cstdio>

using namespace std;

int main()
{
   while(1)
   {
       list<int>lis1;
    list<int>lis2;
    list<int>::iterator pos1;
    list<int>::iterator pos2;
   printf("输入一个链表 第一个数表示数据的个数 数据用“ ”隔开\n");
    int s,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&s);
        lis1.push_back(s);
    }
    printf("逆序前：\n");
     for(pos1 = lis1.begin();pos1 != lis1.end();pos1++)
            cout<<*pos1<<" ";
        printf("\n");
    for(pos1 = lis1.begin();pos1 != lis1.end();pos1++)
        lis2.push_front(*pos1);
        printf("逆序后：\n");
    for(pos1 = lis2.begin();pos1 != lis2.end();pos1++)
            cout<<*pos1<<" ";
        printf("\n");
   }
    return 0;
}
