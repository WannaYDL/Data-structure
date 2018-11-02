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
//挑选weight最小的两个结点的位置
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


//构造哈夫曼树HT
void CreatHuffmanTree(HuffmanTree &HT,int *w,int n)
{
    int m,s1,s2;        //s1,s2存放weight最小的两个字符的位置
    if(n<=1)return;
    m=2*n-1;            //m用来存储结点总数
    HT=new HTNode[m+1]; //建立m+1个结点，计数从1开始
    for(int i=1;i<m;i++){   //初始化HT
        HT[i].weight=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    for(int i=1;i<=n;i++){  //输入结点权值
       HT[i].weight=w[i];
    }
    /*建树*/
    cout<<"哈夫曼树为"<<endl;
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
/*从叶子节点到根节点逆向求每个字符的哈夫曼编码*/
void CreatHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n)
{
    int c,f,w=0;
    int a[100];
    int i,start;             //i计数,start用来指向编码的最后的位置
    char *cd;               //用来临时存储字符编码
    HC=new char *[n+1];     //分配存储n个字符编码的编码表的空间
    cd = new char[n];       //为cd分配空间
    cd[n-1]='\0';           //编码以\0结束
    memset(a,0,sizeof(a));
    for(i=1;i<=n;i++){
        start=n-1;
        c=i;f=HT[i].parent;
        while(f!=0){
            start--;
            if(HT[f].lchild==c)  //左边编码为0，右边编码为1
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
        HC[i]=new char[n-start];        //分配空间
        strcpy(HC[i],&cd[start]);      //将编码从临时存储空间转到HC中
    }
    delete cd;
    for(i=1; i<=n; i++)
        printf(" 权值为%d的哈夫曼编码为：%s\n",HT[i].weight,HC[i]);
    for(i=1; i<=n; i++)
        w+=HT[i].weight*a[i];
    printf(" 带权路径为：%d\n",w);
}


int main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    int *w,i,n,wei;
    cout<<endl;
    cout<<"&&&哈夫曼编码&&&"<<endl;
    cout<<"请输入叶子结点个数：";
    cin>>n;
    w=new int[n+1];
    cout<<"请输入这"<<n<<"个元素的权值："<<endl;
    for(i=1;i<=n;i++){
        cout<<i<<':';
        cin>>wei;
        w[i]=wei;
    }
    CreatHuffmanTree(HT,w,n);
    CreatHuffmanCode(HT,HC,n);
    return 0;
}





