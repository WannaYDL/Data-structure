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
//    printf("请输入姓名：(ctrl+z结束输入)");
//    cin>>cnt;
    do{
        p=(Josephus*)malloc(sizeof(Josephus));
        if(p==NULL){
            printf("内存分配失败，退出！");
            return 0;
        }
        p->num=++n;  // 座位号
        p->count=0;   // 出列序号
        if(*head==NULL){//循环单链表的头指针
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
    return n-1;  //链表中的节点个数
}
// 遍历显示所有节点，循环链表没有表尾
void display_link(Josephus *head, int n){
    Josephus *p;
    int i=0;

    for(p=head; i<n; p=p->next,i++)
        printf("%d  %d\n",
               p->num,p->count);
}
void baoshu(Josephus *head,int n,int m) //报数函数
{
  	int counter=1;  //出列记数器
    int i=0,j=0;   //报数记数器
    Josephus *p,*pre;
    printf("约瑟夫排列(最初位置---约瑟夫环位置):\n");
    for(p=pre=head; counter<=n; ){   //模拟循环报数
        i++;
        if(i==m){   // 报到3出列，删除该结点
            i=0;
            p->count=counter; // 出列序号
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
    cout<<"请输入n及m的值：";
    cin>>n>>m;
    Josephus *head=NULL;
    creat_link(&head,n);
    baoshu(head,n,m);
    return 0;
}
