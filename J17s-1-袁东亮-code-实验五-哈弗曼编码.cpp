#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
typedef struct HTNode{
    int weight;
    int parent,lchild,rchild;
}HTNode,*HuffmanTree;

typedef char **HuffmanCode;
//��ѡweight��С����������λ��
void Select(HuffmanTree HT ,int n ,int &s1 ,int &s2)
{
    int i,Min;
    for(i=1;i<=n;i++){
        if(HT[i].parent==0){
            Min=i;
            break;
        }
    }
    for(i=1;i<=n;i++){
        if(HT[i].parent==0){
            if(HT[i].weight<HT[Min].weight){
                Min=i;
            }
        }
    }
    s1=Min;
    for(i=1;i<=n;i++){
        if(HT[i].parent==0&&i!=s1){
            Min=i;
            break;
        }
    }
    for(i=1;i<=n;i++){
        if(HT[i].parent==0 && i!=s1){
            if(HT[i].weight<HT[Min].weight){
                Min=i;
            }
        }
    }
    s2=Min;
}


//�����������HT
void CreatHuffmanTree(HuffmanTree &HT,int *w,int n)
{
    int m,s1,s2;        //s1,s2���weight��С�������ַ���λ��
    if(n<=1)return;
    m=2*n-1;            //m�����洢�������
    HT=new HTNode[m+1]; //����m+1����㣬������1��ʼ
    for(int i=1;i<m;i++){   //��ʼ��HT
        HT[i].weight=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    for(int i=1;i<=n;i++){  //������Ȩֵ
       HT[i].weight=w[i];
    }
    /*����*/
    cout<<"��������Ϊ"<<endl;
    for(int i=n+1;i<=m;i++){
        Select(HT,i-1,s1,s2);
        HT[s1].parent=i;
        HT[s2].parent=i;
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
        cout<<HT[i].weight<<" ("<<HT[s1].weight<<" "<<HT[s2].weight<<")";
        //cout<<"hear{"<<HT[s1].parent<<" "<<HT[s2].parent<<"}";
    }
    cout<<endl;
}
/*��Ҷ�ӽڵ㵽���ڵ�������ÿ���ַ��Ĺ���������*/
void CreatHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n)
{
    int c,f,w=0;
    int a[100];
    int i,start;             //i����,start����ָ����������λ��
    char *cd;               //������ʱ�洢�ַ�����
    HC=new char *[n+1];     //����洢n���ַ�����ı����Ŀռ�
    cd = new char[n];       //Ϊcd����ռ�
    cd[n-1]='\0';           //������\0����
    memset(a,0,sizeof(a));
    for(i=1;i<=n;i++){
        start=n-1;
        c=i;f=HT[i].parent;
        while(f!=0){
            start--;
            if(HT[f].lchild==c)  //��߱���Ϊ0���ұ߱���Ϊ1
            {
                cd[start]='0';
                a[i]++;
            }
            else {
                cd[start]='1';
                a[i]++;
            }
            c=f;f=HT[f].parent;
        }
        HC[i]=new char[n-start];        //����ռ�
        strcpy(HC[i],&cd[start]);      //���������ʱ�洢�ռ�ת��HC��
    }
    delete cd;
    for(i=1; i<=n; i++)
        printf(" ȨֵΪ%d�Ĺ���������Ϊ��%s\n",HT[i].weight,HC[i]);
    for(i=1; i<=n; i++)
        w+=HT[i].weight*a[i];
    printf(" ��Ȩ·��Ϊ��%d\n",w);
}


int main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    int *w,i,n,wei;
    cout<<endl;
    cout<<"&&&����������&&&"<<endl;
    cout<<"������Ҷ�ӽ�������";
    cin>>n;
    w=new int[n+1];
    cout<<"��������"<<n<<"��Ԫ�ص�Ȩֵ��"<<endl;
    for(i=1;i<=n;i++){
        cout<<i<<':';
        cin>>wei;
        w[i]=wei;
    }
    CreatHuffmanTree(HT,w,n);
    CreatHuffmanCode(HT,HC,n);
    return 0;
}





