#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
typedef char ElemType;
using namespace std;
typedef struct StackNode
{
  ElemType data;
  struct StackNode *next;

}StackNode,*LinkStack;
//不需要头结点
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
{//返回栈顶元素，不修改指针
    if(S!=NULL)
        return S->data;
}
int StackEmpty(LinkStack &S)
{
    if(S==NULL)
        return 1;
    else
        return 0;

}
