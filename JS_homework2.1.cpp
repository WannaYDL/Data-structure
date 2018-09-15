#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

struct Book {
	int a;
};
typedef struct LNode {
	Book data;
	struct LNode *next;
} LNode, *LinkList;
int length;
Status InitList_L(LinkList &L) { //算法2.6 单链表的初始化
	//构造一个空的单链表L
	L = new LNode; //生成新结点作为头结点，用头指针L指向头结点
	L->next = NULL; //头结点的指针域置空
	return OK;
}
Status GetElem_L(LinkList L, int i, Book &e) { //算法2.7 单链表的取值
	//在带头结点的单链表L中查找第i个元素
	//用e返回L中第i个数据元素的值
	int j;
	LinkList p;
	p = L->next;
	j = 1; //初始化，p指向第一个结点，j为计数器
	while (j < i && p) { //顺链域向后扫描，直到p指向第i个元素或p为空
		p = p->next; //p指向下一个结点
		++j; //计数器j相应加1
	}
	if (!p || j > i)
		return ERROR; //i值不合法i＞n或i<=0
	e = p->data; //取第i个结点的数据域
	return OK;
}
LNode *LocateElem_L(LinkList L, int e,int &id) { //算法2.8 按值查找
	//在带头结点的单链表L中查找值为e的元素
	LinkList p;
	int i=1;
	p = L->next;
	while (p && p->data.a!= e)//顺链域向后扫描，直到p为空或p所指结点的数据域等于e
    {
        i++;
		p = p->next; //p指向下一个结点
    }
    id =i;
	return p; //查找成功返回值为e的结点地址p，查找失败p为NULL
} //LocateElem_L
Status ListInsert_L(LinkList &L, int i, Book &e) { //算法2.9 单链表的插入
	//在带头结点的单链表L中第i个位置插入值为e的新结点
	int j;
	LinkList p, s;
	p = L;
	j = 0;
	while (p && j < i - 1) {
		p = p->next;
		++j;
	}//查找第i?1个结点，p指向该结点
	if (!p || j > i - 1)
		return ERROR; //i＞n+1或者i＜1
	s = new LNode; //生成新结点*s
	s->data = e; //将结点*s的数据域置为e
	s->next = p->next; //将结点*s的指针域指向结点ai
	p->next = s; //将结点*p的指针域指向结点*s
	++length;
	return OK;
} //ListInsert_L
Status ListDelete_L(LinkList &L, int i) { //算法2.9 单链表的删除
	//在带头结点的单链表L中，删除第i个位置
	LinkList p, q;
	int j;
	p = L;
	j = 0;
	while ((p->next) && (j < i - 1)) //查找第i?1个结点，p指向该结点
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || (j > i - 1))
		return ERROR; //当i>n或i<1时，删除位置不合理
	q = p->next; //临时保存被删结点的地址以备释放
	p->next = q->next; //改变删除结点前驱结点的指针域
	delete q; //释放删除结点的空间
	--length;
	return OK;
} //ListDelete_L

int CreateList_H(LinkList &L, int n) { //算法2.11 前插法创建单链表
	//逆位序输入n个元素的值，建立到头结点的单链表L
	LinkList p;
	L = new LNode;
	L->next = NULL; //先建立一个带头结点的空链表
	length = 0;
	cout<<"请输入数据：";
	while(n--){
		p = new LNode; //生成新结点*p
		int x;
		cin>>x;
		p->data.a=x;
		p->next = L->next;
		L->next = p; //将新结点*p插入到头结点之后
		length++;//同时对链表长度进行统计
	}
}
int CreateList_R(LinkList &L, int n) { //算法2.12 后插法创建单链表
	//正位序输入n个元素的值，建立带表头结点的单链表L
	LinkList p, r;
	L = new LNode;
	L->next = NULL; //先建立一个带头结点的空链表
	r = L; //尾指针r指向头结点
	length = 0;
	cout<<"请输入数据:";
	while(n--){
		p = new LNode;//生成新结点
		//file >> p->data.a;//输入元素值赋给新结点*p的数据域
		cin>>p->data.a;
		p->next = NULL;
		r->next = p;//将新结点*p插入尾结点*r之后
		r = p;//r指向新的尾结点*p
		length++; //同时对链表长度进行统计
	}
}
void ShowList(LinkList &L){//输出链表
    LinkList p=L->next;
    while(p){
        cout<<p->data.a<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    int lena,lenb,flag=1;
    cin>>lena>>lenb;
    LinkList a,b,p,q,next1,next2;
    CreateList_R(a,lena);
    //ShowList(a);
    CreateList_R(b,lenb);
    p=a->next; next1=p->next;
    q=b->next; next2=q->next;
    while(p->next){
        if((next1->data.a>q->data.a)){
            p->next=q;
            p=q;
            q->next=next1;
            q=next2;
            if(q==NULL){
                break;
            }
            next2=next2->next;
        }
        if(next1==NULL){
            next1=q;
            break;
        }
        if((next1->data.a<q->data.a)){
            p=next1;next1=p->next;
        }
    }
    ShowList(a);
    return 0;
}
