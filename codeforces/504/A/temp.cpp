#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

const int N = (1<<17);
int n;
int x[N], d[N], q[N], qf, qb;
int ans[N][2], as;

int main(){
    scanf(" %d", &n);
    for(int i=0;i<n;i++) {
        scanf(" %d%d", d+i, x+i);
        if(d[i] == 1) q[qb++] = i;
    }

    while(qb > qf){
        int i = q[qf++], j = x[i];
        if(d[i] != 1) continue;
        ans[as][0] = i, ans[as][1] = j, as++;
        x[i] ^= j, x[j] ^= i; d[i]--; d[j]--;
        if(d[j] == 1) q[qb++] = j;
    }

    printf("%d\n", as);
    for(int i=0;i<as;i++) printf("%d %d\n", ans[i][0], ans[i][1]);
}
