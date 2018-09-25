#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct ElemType
{
  int p;
};

typedef struct StackNode
{
  ElemType data;
  struct StackNode *next;

}StackNode,*LinkStack;

//����Ҫͷ���
int InitStack(LinkStack &S)
{
    S=NULL;
    return 1;
}

int Push(LinkStack &S,ElemType e)
{
    LinkStack p=new StackNode;
    p->data=e;
    p->next=S;
    S=p;
    return 1;
}

int Pop(LinkStack &S,ElemType &e)
{
    if(S==NULL) return 0;
    e=S->data;
    LinkStack p=S;
    S=S->next;
    delete p;
    return 1;
}

ElemType GetTop(LinkStack S)
{//����ջ��Ԫ�أ����޸�ָ��
    if(S!=NULL)
        return S->data;
    else
        cout<<"ջ�յ���"<<endl;
}

int main()
{
    LinkStack S;
    int x;
    ElemType a;
    while(cin>>x){
        a.p=x;
        Push(S,a);
    }
}
