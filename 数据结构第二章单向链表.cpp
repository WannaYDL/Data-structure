#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

typedef struct Book{
    string id;
    string name;
    double price;
    friend bool operator!=(Book a,Book b){
        if(a.id==b.id || a.name==b.name||a.price==b.price) return 0;
        return 1;
    }
};
typedef struct LNode
{
    Book data;
    struct LNode *next;
}LNode,*LinkList;


//��ʼ�����½�ͷ���
int InitList(LinkList &L)
{
    L = new LNode;//�����½ڵ���Ϊͷ���
    L->next=NULL; //ͷ����ָ�����ÿ�
    return 1;
}
//�������ȡֵ
int GetElem(LinkList  L,int  i,Book &e)
{
    LinkList p=L->next;int j=1;
    while(p&&j<i){
        p=p->next;
        ++j;
    }
    if(!p||j>i)return 0;
    e=p->data;
    return 1;
}
//����
LNode *LocateElem(LinkList L,Book e)
{

    LinkList p=L->next;
    while(p && p->data!=e){
        p=p->next;
    }
    return p;
}
//���������
int ListInsert(LinkList &L,int i,Book e)
{
    LinkList p=L;int j =0;
    while(p && (j<i-1)){
        p=p->next;j++;
    }
    if(!p||j>i-1) return 0;
    LinkList s= new LNode ;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return 1;
}
//ɾ��
int ListDelete(LinkList &L,int i)
{
    LinkList p=L;int j=0;
    while((p->next)&&(j<i-1)){//p->nextΪҪɾ���Ľڵ�
        p=p->next;j++;
    }
    if(!p->next||j>i-1) return 0;
    LinkList q=p->next;//��ʱ����Ҫɾ���Ľڵ�
    p->next=q->next;
    delete q;
    return 1;
}
void CreatList_H(LinkList &L,int n)//��������n��Ҫ���������
{
    int i;
    L = new LNode;  //������ͷ��������
    L->next=NULL;
    for(i=0;i<n;i++){
        LinkList p = new LNode;
        Book e;
        cin>>e.id>>e.name>>e.price;
        p->data=e;
        p->next=L->next;
        L->next=p;
    }
}
void CreatList_R(LinkList &L,int n)
{

    int i;
}


