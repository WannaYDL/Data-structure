#include <iostream>
#include <cstring>
using namespace std;
const int maxn=1000000;
char s[maxn],t[maxn];
int nxt[maxn],nxtval[maxn];
int lens,lent;
void get_next()
{
    int i=1,j=0;
    nxt[1]=0;
    while(i<lent){
        if(j==0||t[i]==t[j]){
            ++i;++j;nxt[i]=j;
        }
        else j=nxt[j];
    }
}
void get_nextval()
{
    int i=1,j=0;
    nxtval[1]=0;
    while(i<lent){
        if(j==0||t[i]==t[j]){
            ++i;++j;
            if(t[i]!=t[j])nxtval[i]=j;
            else nxtval[i]=nxtval[j];
        }
        else j=nxtval[j];
    }
}
//kmp
int Index_kmp(int pos)
{
    int i=pos,j=1;
    int ans=0;
    while(i<=lens){
        if(j==0||s[i]==t[j]){
            ++i;++j;
        }
        else j=nxt[j];
        if(j==lent) ans++;
    }
    return ans;

}

int main()
{
    int n;
    int loca;
    cin>>n;
    while(n--){
        cin>>t>>s;
        lens=strlen(s);
        lent=strlen(t);
        get_next();
        get_nextval();
        loca=Index_kmp(1);
        if(loca==0)cout<<0<<endl;
        else
        cout<<loca<<endl;
    }
    return 0;
}
