#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status 是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType; //ElemType 为可定义的数据类型，此设为int类型

struct Book {
	int a;
};
typedef struct LNode {
	Book data; //结点的数据域
	struct LNode *next; //结点的指针域
} LNode, *LinkList; //LinkList为指向结构体LNode的指针类型

string head_1, head_2, head_3;
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
} //GetElem_L

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
	while(n--){
		p = new LNode; //生成新结点*p
		//file >> p->data.a; //输入元素值赋给新结点*p的数据域
		int x;
		cin>>x;
		p->data.a=x;
		p->next = L->next;
		L->next = p; //将新结点*p插入到头结点之后
		length++;//同时对链表长度进行统计
	}
	//file.close();
} //CreateList_F

int CreateList_R(LinkList &L, int n) { //算法2.12 后插法创建单链表
	//正位序输入n个元素的值，建立带表头结点的单链表L
	LinkList p, r;
	L = new LNode;
	L->next = NULL; //先建立一个带头结点的空链表
	r = L; //尾指针r指向头结点
	length = 0;
	//fstream file; //打开文件进行读写操作
//file.open("book.txt");
//	if (!file) {
//		cout << "未找到相关文件，无法打开！" << endl;
//		return (ERROR);
//	}
//	file >> head_1;
	//while (!file.eof()) { //将文件中的信息运用后插法插入到链表中
	cout<<"请输入所要插入的数据:";
	while(n--){
		p = new LNode;//生成新结点
		//file >> p->data.a;//输入元素值赋给新结点*p的数据域
		cin>>p->data.a;
		p->next = NULL;
		r->next = p;//将新结点*p插入尾结点*r之后
		r = p;//r指向新的尾结点*p
		length++; //同时对链表长度进行统计
	}
	//file.close();
} //CreateList_L

int main() {
	int d, n, choose;
	double price;
	Book e;
	LinkList L, p;
	cout << "1. 建立\n";
	cout << "2. 输入\n";//输入的时候计算了链表的实际长度，输入是在后台输入
	cout << "3. 取值\n";
	cout << "4. 查找\n";
	cout << "5. 插入\n";
	cout << "6. 按位置删除\n";
	cout << "7. 输出\n";
	cout << "8. 按值删除\n";
	cout << "9. 建立与合并\n";
	cout << "0. 退出\n\n";

	choose = -1;
	while (choose != 0) {
		cout << "请选择:";
		cin >> choose;
		switch (choose) {
		case 1: //建立一个单链表
			if (InitList_L(L))
				cout << "成功建立链表!\n\n";
			break;
		case 2: //使用后插法创建单链表
		    cout<<"请输入要插入的元素个数:";
		    cin>>length;
			CreateList_R(L, length);
			//cout << "输入 book.txt 信息完毕\n\n";
			cout<<"输入成功！"<<endl<<endl;
			break;
		case 3: //单链表的按序号取值
			cout << "请输入一个位置用来取值:";
			cin >> d;
			if (GetElem_L(L, d, e)) {
				cout << "查找成功\n";
				cout << "第" << d << "个元素是：\n";
				cout<<e.a<<endl;
			} else
				cout << "查找失败\n\n";
			break;
		case 4: //单链表的按值查找
			cout << "请输入所要查找值:";
			int m;
			cin >> m;
			int id;
			if (LocateElem_L(L, m,id) != NULL) {
				cout << "查找成功\n";
				cout << "该元素为：" << LocateElem_L(L, m,id)->data.a
						<< endl << endl;
			} else
				cout << "查找失败! 值" << price << " 没有找到\n\n";
			break;
		case 5: //单链表的插入
			cout << "请输入插入的位置和数据";
			cin >> d;
			cin >> e.a;
			if (ListInsert_L(L, d, e))
				cout << "插入成功.\n\n";
			else
				cout << "插入失败!\n\n";
			break;
		case 6: //单链表的删除
			cout << "请输入所要删除的值的位置:";
			cin >> d;
			if (ListDelete_L(L, d))
				cout << "删除成功!\n\n";
			else
				cout << "删除失败!\n\n";
			break;
		case 7: //单链表的输出
			cout << "当前链表读出:\n";
			p = L->next;
			while (p) {
                cout<<p->data.a;
				p = p->next;
			}
			cout << endl;
			break;
        case 8:
            cout<<"请输入所要删除的值：";
            int y,nid;
            cin>>y;
            if(LocateElem_L(L, y,nid)){
                if(ListDelete_L(L, nid)){
                    cout<<"删除成功"<<endl;
                }
                else
                    cout<<"删除失败"<<endl;
            }
            else
                cout<<"删除失败"<<endl;
            break;
        case 9:
            cout<<"建立两个有序链表并合并";
            LinkList a,b;
            int lena,lenb;
            CreateList_R(a,lena);
            CreateList_H(b,lenb);
            p=a->next;
            while (p) {
                cout<<p->data.a;
				p = p->next;
			}

		}
	}
	return 0;
}
