#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAXSIZE=100;
typedef struct SElem{
    int p;
};

typedef struct SqStack{
    SElem *base;
    SElem *top;
    int stacksize;
};

int InitStack(SqStack &S)
{
    S.base = new SElem[MAXSIZE];
    if(!S.base) return 0;
    S.top = S.base;
    S.stacksize=MAXSIZE;
    return 1;
}

int Push(SqStack &S,SElem e)
{
    if(S.top-S.base == S.stacksize)return 0;
    *S.top=e;
    S.top++;
    return 1;
}

int Pop(SqStack &S ,SElem &e)
{
    if(S.top==S.base) return 0;
    S.top--;
    e= *S.top;
    return 1;
}

SElem GetTop(SqStack &S)
{
    if(S.top!=S.base)
        return *(S.top-1);
    else{
        cout<<"Õ»¿ÕÀ²£¡"<<endl;
    }
}

int main()
{
    int x;
    SqStack S;
    SElem a,b;
    InitStack(S);
    a.p=5;
    while(cin>>x){
        a.p=x;
        Push(S,a);
    }
    a.p=0;
    Pop(S,a);
    cout<<a.p<<endl;
    b=GetTop(S);
    cout<<b.p<<endl;

}
