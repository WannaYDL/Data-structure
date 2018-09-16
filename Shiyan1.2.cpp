#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣
typedef int ElemType; //ElemType Ϊ�ɶ�����������ͣ�����Ϊint����

struct Book {
	int a;
};
typedef struct LNode {
	Book data; //����������
	struct LNode *next; //����ָ����
} LNode, *LinkList; //LinkListΪָ��ṹ��LNode��ָ������

string head_1, head_2, head_3;
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
} //GetElem_L

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
	while(n--){
		p = new LNode; //�����½��*p
		//file >> p->data.a; //����Ԫ��ֵ�����½��*p��������
		int x;
		cin>>x;
		p->data.a=x;
		p->next = L->next;
		L->next = p; //���½��*p���뵽ͷ���֮��
		length++;//ͬʱ�������Ƚ���ͳ��
	}
	//file.close();
} //CreateList_F

int CreateList_R(LinkList &L, int n) { //�㷨2.12 ��巨����������
	//��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ�����L
	LinkList p, r;
	L = new LNode;
	L->next = NULL; //�Ƚ���һ����ͷ���Ŀ�����
	r = L; //βָ��rָ��ͷ���
	length = 0;
	//fstream file; //���ļ����ж�д����
//file.open("book.txt");
//	if (!file) {
//		cout << "δ�ҵ�����ļ����޷��򿪣�" << endl;
//		return (ERROR);
//	}
//	file >> head_1;
	//while (!file.eof()) { //���ļ��е���Ϣ���ú�巨���뵽������
	cout<<"��������Ҫ���������:";
	while(n--){
		p = new LNode;//�����½��
		//file >> p->data.a;//����Ԫ��ֵ�����½��*p��������
		cin>>p->data.a;
		p->next = NULL;
		r->next = p;//���½��*p����β���*r֮��
		r = p;//rָ���µ�β���*p
		length++; //ͬʱ�������Ƚ���ͳ��
	}
	//file.close();
} //CreateList_L

int main() {
	int d, n, choose;
	double price;
	Book e;
	LinkList L, p;
	cout << "1. ����\n";
	cout << "2. ����\n";//�����ʱ������������ʵ�ʳ��ȣ��������ں�̨����
	cout << "3. ȡֵ\n";
	cout << "4. ����\n";
	cout << "5. ����\n";
	cout << "6. ��λ��ɾ��\n";
	cout << "7. ���\n";
	cout << "8. ��ֵɾ��\n";
	cout << "9. ������ϲ�\n";
	cout << "0. �˳�\n\n";

	choose = -1;
	while (choose != 0) {
		cout << "��ѡ��:";
		cin >> choose;
		switch (choose) {
		case 1: //����һ��������
			if (InitList_L(L))
				cout << "�ɹ���������!\n\n";
			break;
		case 2: //ʹ�ú�巨����������
		    cout<<"������Ҫ�����Ԫ�ظ���:";
		    cin>>length;
			CreateList_R(L, length);
			//cout << "���� book.txt ��Ϣ���\n\n";
			cout<<"����ɹ���"<<endl<<endl;
			break;
		case 3: //������İ����ȡֵ
			cout << "������һ��λ������ȡֵ:";
			cin >> d;
			if (GetElem_L(L, d, e)) {
				cout << "���ҳɹ�\n";
				cout << "��" << d << "��Ԫ���ǣ�\n";
				cout<<e.a<<endl;
			} else
				cout << "����ʧ��\n\n";
			break;
		case 4: //������İ�ֵ����
			cout << "��������Ҫ����ֵ:";
			int m;
			cin >> m;
			int id;
			if (LocateElem_L(L, m,id) != NULL) {
				cout << "���ҳɹ�\n";
				cout << "��Ԫ��Ϊ��" << LocateElem_L(L, m,id)->data.a
						<< endl << endl;
			} else
				cout << "����ʧ��! ֵ" << price << " û���ҵ�\n\n";
			break;
		case 5: //������Ĳ���
			cout << "����������λ�ú�����";
			cin >> d;
			cin >> e.a;
			if (ListInsert_L(L, d, e))
				cout << "����ɹ�.\n\n";
			else
				cout << "����ʧ��!\n\n";
			break;
		case 6: //�������ɾ��
			cout << "��������Ҫɾ����ֵ��λ��:";
			cin >> d;
			if (ListDelete_L(L, d))
				cout << "ɾ���ɹ�!\n\n";
			else
				cout << "ɾ��ʧ��!\n\n";
			break;
		case 7: //����������
			cout << "��ǰ�������:\n";
			p = L->next;
			while (p) {
                cout<<p->data.a;
				p = p->next;
			}
			cout << endl;
			break;
        case 8:
            cout<<"��������Ҫɾ����ֵ��";
            int y,nid;
            cin>>y;
            if(LocateElem_L(L, y,nid)){
                if(ListDelete_L(L, nid)){
                    cout<<"ɾ���ɹ�"<<endl;
                }
                else
                    cout<<"ɾ��ʧ��"<<endl;
            }
            else
                cout<<"ɾ��ʧ��"<<endl;
            break;
        case 9:
            cout<<"�����������������ϲ�";
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
