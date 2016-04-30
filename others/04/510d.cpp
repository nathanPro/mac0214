#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 307;
const int inf = 1e9;
int n, l[N], c[N];
map<int, int> S[N];

inline int gcd(int a, int b) { return b? gcd(b,a%b) : a; }

int main(){
    scanf(" %d", &n);
    for(int i=1;i<=n;i++) scanf(" %d", l+i);
    for(int i=1;i<=n;i++) scanf(" %d", c+i);
    S[0][0] = 0;
    for(int i=1;i<=n;i++)
        for(auto it: S[i-1]){
            int d = it.first, w = it.second, nd = gcd(d,l[i]);
            if(!S[i].count(nd)) S[i][nd] = inf;
            S[i][nd] = min(S[i][nd], w + c[i]);
            if(!S[i].count(d)) S[i][d] = inf;
            S[i][d] = min(S[i][d], w);
        }

    if(S[n].count(1)) printf("%d\n", S[n][1]);
    else printf("-1\n");
}
