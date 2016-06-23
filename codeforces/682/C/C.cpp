#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

const int N = 1e5 + 7;
const int M = N<<1;

int n;
int a[N], f[N], sz[N], ad[N];
int to[M], nx[M], w[M], es = 2;

int dfs(int i, int d){
    sz[i] = 1;
    _max(d, 0);
    for(int e=ad[i];e;e=nx[e])
        if(sz[to[e]] == 0) {
            f[to[e]] |= (d + w[e] > a[to[e]]);
            sz[i] += dfs(to[e], d + w[e]);
        }
    return sz[i];
}

int cnt(int i){
    if(f[i]) return sz[i];
    int ans = 0;
    for(int e=ad[i];e;e=nx[e]) ans += cnt(to[e]);
    return ans;
}

int main(){
    scanf(" %d", &n);
    for(int i=0;i<n;i++) scanf(" %d", a+i);
    for(int i=1;i<n;i++){
        int j, c;
        scanf(" %d%d", &j, &c); --j;
        to[es] = i; nx[es] = ad[j]; w[es] = c; ad[j] = es++;
    }

    dfs(0, 0);
    printf("%d\n", cnt(0));
}
