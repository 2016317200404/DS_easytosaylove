#include<iostream>
#include<list>
#include<cstdio>

using namespace std;

int main()
{
    list<int>lis1;
    list<int>lis2;
    int n1,n2;
    while(1)
    {
        scanf("%d",&n1);
        int s;
        for(int i = 0;i < n1; i++)
        {
            scanf("%d",&s);
            lis1.push_back(s);
        }
        scanf("%d",&n2);
        for(int i = 0; i < n2; i++)
        {
            scanf("%d",&s);
            lis2.push_back(s);
        }
        list<int>::iterator pos1;
         list<int>::iterator pos2;
        for(pos1 = lis1.begin();pos1 != lis1.end();pos1++)
            cout<<*pos1<<" ";
        printf("\n");
        for(pos2 = lis2.begin();pos2 != lis2.end();pos2++)
            cout<<*pos2<<" ";
            printf("\n");
        for(pos2 = lis2.begin();pos2 != lis2.end();pos2++)
        {
            int flag = 0;
            for(pos1 = lis1.begin();pos1 != lis1.end();pos1++)
            {
                if(*pos2 == *pos1)
                    flag = 1;
            }
            if(flag == 0)
                lis1.push_back(*pos2);
            for(pos1 = lis1.begin();pos1 != lis1.end();pos1++)
            cout<<*pos1<<" ";
            printf("\n");
        }
    }
    return 0;
}
