#include <iostream>
#include <cstring>
using namespace std;

const int maxn=100;
char s[maxn],t[maxn];
int nxt[maxn];
int lens,lent;

void get_next(){
    nxt[0]=0;
    int i=1,j=0;
    while(i<lent){
        if(t[j]==t[i]){
            nxt[i++]=++j;
        }
        else if(j==0) i++;
        else j=nxt[j-1];
    }
}
int kmp(){
    //j表示子串的指针，i表示主串上的指针
    int j=0,i=0;
    int ans=0;
    while(i<lens){
        if(s[i]==t[j]){
            i++;j++;
        }
        else if(j==0) i++;
        else j=nxt[j-1];
        if(j==lent)ans++;
    }
    return ans;
//    if(j==lent){
//        return i-lent+1;
//    }
//    else return -1;
}

int main()
{
    int loca;
    while(cin>>s>>t){
        lens=strlen(s);
        lent=strlen(t);
        get_next();
        loca=kmp();
        if(loca==0){
            cout<<"不存在公共子串"<<endl;
        }
        else cout<<loca<<endl;

    }

    return 0;
}

