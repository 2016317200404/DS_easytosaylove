#include<iostream>
#include<cstdio>
#include<list>

using namespace std;

int main()
{
    int a;
    list<int>listint ;
    list<int>::iterator  pos;  //好像定义了一个指针
    while(~scanf("%d",&a))
    {
        if(a == 0)
        {
            for(pos = listint.begin(); pos != listint.end(); pos++)  //指向首地址，首地址对应的是0
            {
                cout<<*pos;   //输出相应地址对应的数据
                    printf(" ");
            }
            printf("\n");
        }
        else if(a == 1)
        {
            int dos,num;
            scanf("%d %d",&dos,&num);
            pos = listint.begin();
//在dos位置插入一个数值为num的数
//pos对应的下标应该是dos-1
            for(int i = 1; i < dos; i++)
                pos++;
            listint.insert(pos,num);
        }
        else
            {
                int dos;
                scanf("%d",&dos);
            //删除操作  删除位置为dos的数据
            //pos对应的下标应该为dos-1
                pos = listint.begin();
                for(int i = 1; i < dos; i++)
                    pos++;
                listint.erase(pos);
            }
            }
    return 0;
}
