#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#include <cstdlib>
using namespace std;
int main()
{
    stack<int> s1,s2;
    char ch[10];
    char a[]="PUSH",b[]="POP";
    int n,t,x;
    cin>>n;
    while(n--){
        cin>>ch;
        if(ch[1]=='U'){
            cin>>t;
            s1.push(t);
        }
        if(ch[1]=='O'){
            if(s2.empty())
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            else{
                x=s2.top();
                s2.pop();
                cout<<x<<endl;
            }
        }
    }
}
