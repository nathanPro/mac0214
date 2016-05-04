#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
typedef long long ll;

const int S = 1e6;
int _c[26][26];

int n;
char in[S+1];
ll c[26][26], s[S], r[S];

ll solve(int l, int u){
    ll ans = 0;
    for(int i=l;i<u;i++) {
        ll loc = 2e6;
        for(int j=0;j<26;j++) _min(loc, c[s[i]][j] + c[r[i]][j]);
        ans += loc;
    }
    return ans;
}

int main(){
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            scanf(" %d", &_c[i][j]);
    for(int i=0;i<26;i++) _c[i][i] = 0;
    for(int i=0;i<26*26;i++) c[i/26][i%26] = _c[i/26][i%26];

    for(int k=0;k<26;k++)
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                _min(c[i][j], c[i][k] + c[k][j]);

    scanf(" %s", in);
    n = strlen(in);
    for(int i=0;i<n;i++) r[n-1-i] = s[i] = in[i]-'a';
    cout << min(solve(0,n/2), solve((1+n)/2,n)) << endl;
}
