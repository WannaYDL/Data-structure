#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
}Node,*LinkedList;
/*初始化*/
LinkedList InitCList(){
    LinkedList L=new Node;
    if(L==NULL){
        cout<<"分配内存失败！"<<endl;
        return 0;
    }
    L->next=L;
    return L;
}
void CreatList_H(LinkedList L,int n)
{
    Node *p;
    int x;
    L=new Node;
    L->next=L;
    for(int i=0;i<n;i++){
        p=new Node;
        cin>>x;
        p->data=x;
        p->next=L->next;
        L->next=p;
    }
}

void Invert(LinkedList L)
{
    Node *p,*t,*q;
    t=L;
    p=t->next;
    q=p->next;
    while(p!=L){
        p->next=t;
        p=q;
        q=q->next;
        t=t->next;
    }
    L->next=t;
}

void showList(LinkedList L)
{
    LinkedList p;
    p=L->next;
    while(p!=L){
        cout<<p->data<<" ";
        p=p->next;
    }

}


int main()
{
    LinkedList L,p;
    int n;
    cin>>n;
    CreatList_H(L,n);
    for(p=L->next;p!=L;p=p->next){
        cout<<int(p->data)<<" ";
    }
    Invert(L);
    for(p=L->next;p!=L;p=p->next){
        cout<<int(p->data)<<" ";
    }
    return 0;
}
