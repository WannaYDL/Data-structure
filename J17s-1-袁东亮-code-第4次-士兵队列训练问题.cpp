#include <iostream>
#include <queue>
using namespace std;
queue<int> q1, q2 ;
/*
���������໥����
��Ϊ2ʱ
1�����е�������Ԫ�ر�����2����
��Ϊ3ʱ
2�����еڷ�3��Ԫ�ر�����1����
*/
int main()
{
    int N, key;
    int n, stop=0, len, a ;
    cin >> N ;
    while(N--)
    {
        stop = 0, key = 2 ;
        while(!q1.empty())//��ն���
            q1.pop();
        while(!q2.empty())
            q2.pop();
        cin >> n ;
        if(n == 2 || n == 3 )
            stop = 1;
        for(int i = 1 ; i <= n ; i++)
            q1.push(i) ;
        while(stop!=1)
        {
            if(key == 2)//��2����
            {
                len = q1.size();
                for(int i = 1 ; i <= len ; i++)
                {
                    if(i%2!=0)
                    {
                        a = q1.front() ;
                        q1.pop() ;
                        q2.push(a) ;
                    }
                    else
                        q1.pop() ;
                }
                key = 3 ;
                if(q2.size() <= 3)
                    stop = 1 ;
            }
            else//��3����
            {
                len = q2.size();
                for(int i = 1 ; i <= len ; i++)
                {
                    if(i%3!=0)
                    {
                        a = q2.front() ;
                        q2.pop() ;
                        q1.push(a) ;
                    }
                    else
                        q2.pop() ;
                }
                key = 2 ;
                if(q1.size() <= 3)
                    stop = 1 ;
            }
        }
        //������

        if(key == 3)
        {
            cout << q2.front() ;
            q2.pop() ;
            while(!q2.empty())
            {
                cout << " " << q2.front() ;
                q2.pop() ;
            }
        }
        else
        {
            cout << q1.front() ;
            q1.pop() ;
            while(!q1.empty())
            {
                cout << " " << q1.front() ;
                q1.pop() ;
            }
        }
        cout << endl ;
    }
    return 0;
}
