#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct Josephus
{
    int num;
    int count;
    struct Josephus *next;
};

int creat_link(Josephus**head,int cnt){
    cnt--;
    Josephus *p,*pre;
    p=pre=NULL;
    int i,n=0;
//    char name[20];
//    printf("������������(ctrl+z��������)");
//    cin>>cnt;
    do{
        p=(Josephus*)malloc(sizeof(Josephus));
        if(p==NULL){
            printf("�ڴ����ʧ�ܣ��˳���");
            return 0;
        }
        p->num=++n;  // ��λ��
        p->count=0;   // �������
        if(*head==NULL){//ѭ���������ͷָ��
            *head=p;
            p->next=p;
        }
        else{
            p->next=pre->next;
            pre->next=p;
        }
        //cout<<p->num<<"  "<<p->count<<endl;
        pre=p;
    }while(cnt--);
    return n-1;  //�����еĽڵ����
}
// ������ʾ���нڵ㣬ѭ������û�б�β
void display_link(Josephus *head, int n){
    Josephus *p;
    int i=0;

    for(p=head; i<n; p=p->next,i++)
        printf("%d  %d\n",
               p->num,p->count);
}
void baoshu(Josephus *head,int n,int m) //��������
{
  	int counter=1;  //���м�����
    int i=0,j=0;   //����������
    Josephus *p,*pre;
    printf("Լɪ������(���λ��---Լɪ��λ��):\n");
    for(p=pre=head; counter<=n; ){   //ģ��ѭ������
        i++;
        if(i==m){   // ����3���У�ɾ���ý��
            i=0;
            p->count=counter; // �������
            //printf("%d----%d\n",p->num,p->count);
            if(counter==n){
                cout<<p->num<<endl;
            }
            pre->next=p->next;
            free(p);
            counter++;
        }
        else{
            pre=p;
        }
        p=p->next;
    }
}
int main()
{
    int n,m;
    cout<<"������n��m��ֵ��";
    cin>>n>>m;
    Josephus *head=NULL;
    creat_link(&head,n);
    baoshu(head,n,m);
    return 0;
}
