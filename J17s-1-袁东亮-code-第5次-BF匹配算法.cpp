#include <iostream>
#include <cstring>
using namespace std;
const int maxn=100;
char s[maxn],t[maxn];
int lens,lent;
int BF(int pos){
    int i=pos,j=1;
    while(i<=lens&&j<=lent){
        if(s[i-1]==t[j-1]){
            i++;j++;
        }
        else{
            i=i-j+2;
            j=1;
        }
    }
    if(j>lent){
        return i-lent;
    }
    else return 0;
}

int main()
{
    int ans;
    while(cin>>s>>t){
        lens=strlen(s);
        lent=strlen(t);
        ans=BF(1);
        if(ans)
            cout<<ans<<endl;
        else
            cout<<"²»´æÔÚÆ¥Åä´®£¡"<<endl;
    }
    return 0;
}
