
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <cstdlib>
#include <ctime>
using namespace std;
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
typedef long long ll;
const int MAXN = 1e5 + 10000;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
char s[MAXN], str[MAXN*2];
int p[MAXN*2];

int Manacher(void)  {
    str[0] = '$';  str[1] = '#';
    int len = strlen (s);
    for (int i=0; i<len; ++i)   {
        str[i*2+2] = s[i];  str[i*2+3] = '#';
    }
    len = len * 2 + 2;  str[len] = '\0';
    int mx = 0, id = 0;
    for (int i=1; i<len; ++i)   {
        if (mx > i) p[i] = min (p[2*id-i], mx - i);
        else    p[i] = 1;
        while (str[i-p[i]] == str[i+p[i]])  p[i]++;
        if (mx < p[i] + i)  {
            mx = p[i] + i;  id = i;
        }
    }
    int ret = 0;
    for (int i=0; i<len; ++i)   {
        ret = max (ret, p[i]);
    }
    return ret - 1;
}

int main(void)    {     //HDOJ 3068 最长回文
    while (scanf ("%s", s) == 1)  {
        printf ("%d\n", Manacher ());
    }

    return 0;
}
