#include<stdio.h>
#include<malloc.h>
#include<iostream>
#define MAX 20
using namespace std;
typedef struct BTNode{       /*�ڵ�ṹ����*/
	char data ;               /*�ڵ�����*/
	struct BTNode *lchild;
	struct BTNode *rchild ;  /*ָ��*/
}*BiTree;
/*cntΪ�ڵ����� leaf ΪҶ�ӽڵ������*/
int cnt=0;
int leaf=0;
 /* �����������������*/
void createBiTree(BiTree *t){
	char s;
	BiTree q;
	printf("\nplease input data:(exit for #)");
	s=getchar();
	if(s=='#'){*t=NULL; return;}
	q=(BiTree)malloc(sizeof(struct BTNode));
	if(q==NULL){printf("Memory malloc failure!"); exit(0);}
	q->data=s;
	*t=q;
	createBiTree(&q->lchild); /*�ݹ齨��������*/
	createBiTree(&q->rchild); /*�ݹ齨��������*/
}

/* �������������  ����¼�ڵ���*/
int PreOrder(BiTree p){
    if ( p!= NULL ) {
       	printf("%c", p->data);
       	if(p->data!='#')
            cnt++;
       	PreOrder( p->lchild ) ;
       	PreOrder( p->rchild) ;
    }
}

/* �������������  ����¼Ҷ�ӽڵ������*/
void InOrder(BiTree p){
    if( p!= NULL ) {
 	 InOrder( p->lchild ) ;
   	 printf("%c", p->data);
   	 if(p->lchild==NULL&&p->rchild==NULL)
        leaf++;
   	 InOrder( p->rchild) ;
    }
}

/* �������������*/
void PostOrder(BiTree p){
   if ( p!= NULL ) {
    	PostOrder( p->lchild ) ;
       	PostOrder( p->rchild) ;
       	printf("%c", p->data);
    }
}

/*��������ķǵݹ��㷨*/
void Preorder_n(BiTree p){
    BiTree stack[MAX],q;
    int top=0,i;
    for(i=0;i<MAX;i++) stack[i]=NULL;/*��ʼ��ջ*/
    q=p;
    while(q!=NULL){
        printf("%c",q->data);
        if(q->rchild!=NULL) stack[top++]=q->rchild;
        if(q->lchild!=NULL) q=q->lchild;
        else
            if(top>0) q=stack[--top];
            else q=NULL;
    }
}

/*������������*/
int Depth(BiTree T)
{
    int n=0,m=0;
    if(T==NULL)return 0;
    else
    {/*m,nΪ���ڵ�����������*/
        m=Depth(T->lchild);
        n=Depth(T->rchild);
        if(m>n)return (m+1);
        else return (n+1);
    }
}

void release(BiTree t){ /*�ͷŶ������ռ�*/
  	if(t!=NULL){
    	release(t->lchild);
    	release(t->rchild);
    	free(t);
  	}
}

int main(){
    /*dep��¼�������*/
    int dep=0;
    BiTree t=NULL;
    createBiTree(&t);
    printf("\n\nPreOrder the tree is:");
    PreOrder(t);
    printf("\n\nInOrder the tree is:");
    InOrder(t);
    printf("\n\nPostOrder the tree is:");
    PostOrder(t);
    printf("\n\n����������У��ǵݹ飩:");
    Preorder_n(t);
    dep=Depth(t);
    release(t);
    cout<<"\nThe number of node is: ";
    cout<<cnt<<endl;
    cout<<"The number of leaf is : "<<leaf<<endl;
    cout <<"The depth of three is: "<<dep<<endl;
    return 0;
}
