#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int a[maxn];
int init()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    return n;
}
/*直接插入排序*/
void InsertSort(int a[],int n)
{
    int i,j;
    for(i=2;i<=n;i++){
        if(a[i]<a[i-1]){
            a[0]=a[i];
            a[i]=a[i-1];
            for(j=i-2;a[j]>a[0];j--){
                a[j+1]=a[j];
            }
            a[j+1]=a[0];
        }
    }
}
int main()
{
    int n;
    n=init();
    InsertSort(a,n);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}


/*简单选择排序*/
//int SelectSort(int a[],int n)
//{
//    int i,j,k;
//    for(i=1;i<n;i++){
//        k=i;
//        for(j=i+1;j<=n;j++){
//            if(a[j]<a[k])k=j;
//        }
//        if(k!=i)swap(a[k],a[i]);
//    }
//}
//int main()
//{
//    int n;
//    n=init();
//    SelectSort(a,n);
//    for(int i=1;i<=n;i++){
//        cout<<a[i]<<" ";
//    }
//    return 0;
//}

/*十进制转换二进制*/
//int change1(int n)
//{
//    if(n/2>0){
//        change1(n/2);
//    }
//    cout<<n%2;
//}
//int change2(int n)
//{
//    stack<int>st;
//    while(n){
//        int t=n%2;
//        st.push(t);
//        n/=2;
//    }
//    while(!st.empty()){
//        cout<<st.top();
//        st.pop();
//    }
//
//}
//int main()
//{
//    int n;
//    while(cin>>n){
//        //if(n==0){cout<<0<<endl;continue;}
//        change1(n);
//        cout<<endl;
//    }
//
//    return 0;
//}


/*QuickSort*/
//int Partition(int a[],int l,int h)
//{
//    a[0]=a[l];
//    int id=a[l];
//    while(l<h){
//        while(l<h&&a[h]>=id) h--;
//        a[l]=a[h];
//        while(l<h&&a[l]<=id) l++;
//        a[h]=a[l];
//    }
//    a[l]=a[0];
//    return l;
//}
//void qsort(int a[],int l,int h)
//{
//    if(l<h){
//        int k=Partition(a,l,h);
//        qsort(a,l,k-1);
//        qsort(a,k+1,h);
//    }
//}
//int main()
//{
//    int n;
//    n=init();
//    qsort(a,1,n);
//    for(int i=1;i<=n;i++){
//        cout<<a[i]<<" ";
//    }
//    return 0;
//}


/*斐波那契数列*/
//int fibo1(int n)
//{
//    if(n==1||n==2) return 1;
//    else return fibo1(n-1)+fibo1(n-2);
//}
//int a[maxn];
//int fibo2(int n)
//{
//    int i;
//    a[1]=1;a[2]=1;
//    for(i=3;i<=n;i++){
//        a[i]=a[i-1]+a[i-2];
//    }
//    return a[n];
//}
//int main()
//{
//    int n;
//    while(cin>>n)
//    cout<<fibo2(n)<<endl;
//    return 0;
//}

/*A+B*/
//int main()
//{
//    int a,b,c;
//    cin>>a>>b;
//    cout<<a+b<<endl;
//    return 0;
//}
