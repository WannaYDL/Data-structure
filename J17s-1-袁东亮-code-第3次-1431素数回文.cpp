#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

bool is[9989899];
int prime[1000];

void init()
{
    int i,j;
    i=2;
    for(j=i*i;j<=9989899;j+=i)
        is[j]=true;
    for(i=3;i<=3163;i=i+2)
    {
        if(is[i])
            continue;
        for(j=i*i;j<=9989899;j+=i)
            is[j]=true;
    }
}

bool test(int a)
{
    int temp=a;
    int b=0;
    while(temp!=0)
    {
        b=b*10;
        b+=temp%10;
        temp/=10;
    }
    return a==b;
}

int main()
{
    int a,b;
    int i,k=0;
    init();
    for(i=5;i<=9989899;i+=2)
        if(!is[i]&&test(i))
            prime[k++]=i;
        while(~scanf("%d %d",&a,&b))
        {
            for(i=0;i<k;i++)
            {
                if(prime[i]<a)
                    continue;
                else if(prime[i]<=b)
                    printf("%d\n",prime[i]);
                else
                    break;
            }
            printf("\n");
        }
        return 0;
}
