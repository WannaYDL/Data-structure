#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
}Node,*LinkedList;

LinkedList LinkedListInit() {
    Node *L;
    L = (Node *)malloc(sizeof(Node));
    if(L == NULL) {
        printf("�����ڴ�ռ�ʧ��\n");
    }
    L->next = NULL;
 	return L;
}

LinkedList LinkedListCreatH() {
    Node *L;
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;

    ElemType x;
    while(scanf("%d",&x) != EOF) {
        Node *p;
        p = (Node *)malloc(sizeof(Node));
        p->data = x;
        p->next = L->next;
        L->next = p;
    }
    return L;
}

LinkedList LinkedListCreatR() {
    Node *L;
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
    LinkedList r;
    r=L;
    ElemType x;
    while(scanf("%d",&x) != EOF) {
        Node *p;
        p = (Node *)malloc(sizeof(Node));
        p->data = x;
        p->next = NULL;
        r->next = p;
        r=p;
    }
    return L;
}

LinkedList LinkedListInsert(LinkedList L,int i,ElemType x) {
    Node *pre;
    pre = L;
    int tempi = 0;
    for (tempi = 1; tempi < i; tempi++) {
    	pre = pre->next;
	}
	if(pre==NULL){
        cout<<"��λ�ò����ڣ�"<<endl;
        return 0;
	}
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = pre->next;
    pre->next = p;
    return L;
}

LinkedList LinkedListDelete(LinkedList L,ElemType x)
{
    Node *p,*pre;
    p = L->next;
    if(x==p->data){
        L->next=p->next;
        return L;
    }
    while(p->data != x) {
        pre = p;
        p = p->next;
    }
    pre->next = p->next;
    free(p);
    return L;
}

ElemType LocateLink(LinkedList L,int x)
{
   Node *p;
   int j=0;
   p=L->next;
    while(j!=x){
        j++;
        //cout<<p->data<<" ";
        p=p->next;
        if(p==NULL){
            cout<<"δ�ҵ���Ԫ�أ�"<<endl;
            break;
        }
    }
   if(j==x){
    cout<<p->data<<endl;
    return p->data;
   }
}

int main() {
    LinkedList list,start;
 	printf("�����뵥���������(�����Բ�����EOF��β)��");
    list = LinkedListCreatR();
    for(start = list->next; start != NULL; start = start->next) {
    	printf("%d ",start->data);
	}
    printf("\n");
    int i;
    ElemType x;
    printf("������������ݵ�λ�ã�");
    scanf("%d",&i);
    printf("������������ݵ�ֵ��");
    scanf("%d",&x);
    LinkedListInsert(list,i,x);
    for(start = list->next; start != NULL; start = start->next) {
    	printf("%d ",start->data);
	}
    printf("\n");
    printf("������Ҫɾ����Ԫ�ص�ֵ��");
    scanf("%d",&x);
    LinkedListDelete(list,x);
    for(start = list->next; start != NULL; start = start->next) {
    	printf("%d ",start->data);
	}
	cout<<endl;
	cout<<"������Ҫ���ҵ�����λ��(��Ŵ�0��ʼ)��";
	cin>>i;
	cout<<LocateLink(list,i)<<endl;
    printf("\n");
    return 0;
}
