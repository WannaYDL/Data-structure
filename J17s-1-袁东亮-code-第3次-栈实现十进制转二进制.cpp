#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#include <cstdlib>
using namespace std;
void change(int n){
    int a[100];
    int cnt=0;
    while(n){
        a[cnt++]=n%2;
        n/=2;
    }

    for(int j=cnt-1;j>=0;j--){
        cout<<a[j];
    }
    cout<<endl;
}


void change2(int n)
{
    stack<int>sta;
    while(n){
       sta.push(n%2);
        n/=2;
    }
    while(!sta.empty()){
        int t=sta.top();
        sta.pop();
        cout<<t;
    }
    cout<<endl;
}
int main()
{
    int choose=-1;
    int n;
    while(1){
        cout<<"��ѡ��1��ջʵ��  2��˳��ʵ��  0���˳�"<<endl;
        cin>>choose;
        if(choose==0)break;
        if(choose>2){
            cout<<"�����������������"<<endl;
            continue;
        }
        cout<<"������Ҫת�������� n"<<endl;
        cin>>n;
        switch(choose){
        case 1:
            change2(n);
            break;
        case 2:
            change(n);
            break;
        }

    }


}


//typedef int ElemType;
//typedef struct StackNode
//{
//  ElemType data;
//  struct StackNode *next;
//  int lenth=0;
//
//}StackNode,*LinkStack;
////����Ҫͷ���
//int InitStack(LinkStack &S)
//{
//    S=NULL;
//    return 1;
//}
////��ջ
//int Push(LinkStack &S,ElemType e)
//{
//    LinkStack p=new StackNode;
//    p->data=e;
//    p->next=S;
//    S=p;
//    S->lenth++;
//    return 1;
//}
////��ջ
//int Pop(LinkStack &S,ElemType &e)
//{
//    if(S==NULL) return 0;
//    e=S->data;
//    LinkStack p=S;
//    S=S->next;
//    delete p;
//    S->lenth--;
//    return 1;
//}
////ջ�գ�
//int StackEmpty(LinkStack S){
//    if(S==NULL)
//        return 1;
//    else return 0;
//}
////ջ��Ԫ��
//int GetTop(LinkStack S)
//{//����ջ��Ԫ�أ����޸�ָ��
//    if(S!=NULL)
//        return S->data;
//    else
//        cout<<"ջ�յ���"<<endl;
//}

