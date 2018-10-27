#include<stdio.h>
#include<malloc.h>
#include<iostream>
#define MAX 20
using namespace std;
typedef struct BTNode{       /*节点结构声明*/
	char data ;               /*节点数据*/
	struct BTNode *lchild;
	struct BTNode *rchild ;  /*指针*/
}*BiTree;
/*cnt为节点总数 leaf 为叶子节点的总数*/
int cnt=0;
int leaf=0;
 /* 先序遍历创建二叉树*/
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
	createBiTree(&q->lchild); /*递归建立左子树*/
	createBiTree(&q->rchild); /*递归建立右子树*/
}

/* 先序遍历二叉树  并记录节点数*/
int PreOrder(BiTree p){
    if ( p!= NULL ) {
       	printf("%c", p->data);
       	if(p->data!='#')
            cnt++;
       	PreOrder( p->lchild ) ;
       	PreOrder( p->rchild) ;
    }
}

/* 中序遍历二叉树  并记录叶子节点的总数*/
void InOrder(BiTree p){
    if( p!= NULL ) {
 	 InOrder( p->lchild ) ;
   	 printf("%c", p->data);
   	 if(p->lchild==NULL&&p->rchild==NULL)
        leaf++;
   	 InOrder( p->rchild) ;
    }
}

/* 后序遍历二叉树*/
void PostOrder(BiTree p){
   if ( p!= NULL ) {
    	PostOrder( p->lchild ) ;
       	PostOrder( p->rchild) ;
       	printf("%c", p->data);
    }
}

/*先序遍历的非递归算法*/
void Preorder_n(BiTree p){
    BiTree stack[MAX],q;
    int top=0,i;
    for(i=0;i<MAX;i++) stack[i]=NULL;/*初始化栈*/
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

/*计算二叉树深度*/
int Depth(BiTree T)
{
    int n=0,m=0;
    if(T==NULL)return 0;
    else
    {/*m,n为根节点的子树的深度*/
        m=Depth(T->lchild);
        n=Depth(T->rchild);
        if(m>n)return (m+1);
        else return (n+1);
    }
}

void release(BiTree t){ /*释放二叉树空间*/
  	if(t!=NULL){
    	release(t->lchild);
    	release(t->rchild);
    	free(t);
  	}
}

int main(){
    /*dep记录树的深度*/
    int dep=0;
    BiTree t=NULL;
    createBiTree(&t);
    printf("\n\nPreOrder the tree is:");
    PreOrder(t);
    printf("\n\nInOrder the tree is:");
    InOrder(t);
    printf("\n\nPostOrder the tree is:");
    PostOrder(t);
    printf("\n\n先序遍历序列（非递归）:");
    Preorder_n(t);
    dep=Depth(t);
    release(t);
    cout<<"\nThe number of node is: ";
    cout<<cnt<<endl;
    cout<<"The number of leaf is : "<<leaf<<endl;
    cout <<"The depth of three is: "<<dep<<endl;
    return 0;
}
