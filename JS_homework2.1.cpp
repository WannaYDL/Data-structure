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
Status InitList_L(LinkList &L) { //�㷨2.6 ������ĳ�ʼ��
	//����һ���յĵ�����L
	L = new LNode; //�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���
	L->next = NULL; //ͷ����ָ�����ÿ�
	return OK;
}
Status GetElem_L(LinkList L, int i, Book &e) { //�㷨2.7 �������ȡֵ
	//�ڴ�ͷ���ĵ�����L�в��ҵ�i��Ԫ��
	//��e����L�е�i������Ԫ�ص�ֵ
	int j;
	LinkList p;
	p = L->next;
	j = 1; //��ʼ����pָ���һ����㣬jΪ������
	while (j < i && p) { //˳�������ɨ�裬ֱ��pָ���i��Ԫ�ػ�pΪ��
		p = p->next; //pָ����һ�����
		++j; //������j��Ӧ��1
	}
	if (!p || j > i)
		return ERROR; //iֵ���Ϸ�i��n��i<=0
	e = p->data; //ȡ��i������������
	return OK;
}
LNode *LocateElem_L(LinkList L, int e,int &id) { //�㷨2.8 ��ֵ����
	//�ڴ�ͷ���ĵ�����L�в���ֵΪe��Ԫ��
	LinkList p;
	int i=1;
	p = L->next;
	while (p && p->data.a!= e)//˳�������ɨ�裬ֱ��pΪ�ջ�p��ָ�������������e
    {
        i++;
		p = p->next; //pָ����һ�����
    }
    id =i;
	return p; //���ҳɹ�����ֵΪe�Ľ���ַp������ʧ��pΪNULL
} //LocateElem_L
Status ListInsert_L(LinkList &L, int i, Book &e) { //�㷨2.9 ������Ĳ���
	//�ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe���½��
	int j;
	LinkList p, s;
	p = L;
	j = 0;
	while (p && j < i - 1) {
		p = p->next;
		++j;
	}//���ҵ�i?1����㣬pָ��ý��
	if (!p || j > i - 1)
		return ERROR; //i��n+1����i��1
	s = new LNode; //�����½��*s
	s->data = e; //�����*s����������Ϊe
	s->next = p->next; //�����*s��ָ����ָ����ai
	p->next = s; //�����*p��ָ����ָ����*s
	++length;
	return OK;
} //ListInsert_L
Status ListDelete_L(LinkList &L, int i) { //�㷨2.9 �������ɾ��
	//�ڴ�ͷ���ĵ�����L�У�ɾ����i��λ��
	LinkList p, q;
	int j;
	p = L;
	j = 0;
	while ((p->next) && (j < i - 1)) //���ҵ�i?1����㣬pָ��ý��
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || (j > i - 1))
		return ERROR; //��i>n��i<1ʱ��ɾ��λ�ò�����
	q = p->next; //��ʱ���汻ɾ���ĵ�ַ�Ա��ͷ�
	p->next = q->next; //�ı�ɾ�����ǰ������ָ����
	delete q; //�ͷ�ɾ�����Ŀռ�
	--length;
	return OK;
} //ListDelete_L

int CreateList_H(LinkList &L, int n) { //�㷨2.11 ǰ�巨����������
	//��λ������n��Ԫ�ص�ֵ��������ͷ���ĵ�����L
	LinkList p;
	L = new LNode;
	L->next = NULL; //�Ƚ���һ����ͷ���Ŀ�����
	length = 0;
	cout<<"���������ݣ�";
	while(n--){
		p = new LNode; //�����½��*p
		int x;
		cin>>x;
		p->data.a=x;
		p->next = L->next;
		L->next = p; //���½��*p���뵽ͷ���֮��
		length++;//ͬʱ�������Ƚ���ͳ��
	}
}
int CreateList_R(LinkList &L, int n) { //�㷨2.12 ��巨����������
	//��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ�����L
	LinkList p, r;
	L = new LNode;
	L->next = NULL; //�Ƚ���һ����ͷ���Ŀ�����
	r = L; //βָ��rָ��ͷ���
	length = 0;
	cout<<"����������:";
	while(n--){
		p = new LNode;//�����½��
		//file >> p->data.a;//����Ԫ��ֵ�����½��*p��������
		cin>>p->data.a;
		p->next = NULL;
		r->next = p;//���½��*p����β���*r֮��
		r = p;//rָ���µ�β���*p
		length++; //ͬʱ�������Ƚ���ͳ��
	}
}
void ShowList(LinkList &L){//�������
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
