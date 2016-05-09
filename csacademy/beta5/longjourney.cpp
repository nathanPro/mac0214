#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5   + 7;
const int M = 2*3e5 + 7;

int n, m, s, a, b, lca;
int ad[N], d[N], seen[N], q[N], qf, qb;
int to[M], nx[M], es=2;

int main(){
    scanf(" %d%d %d%d%d", &n, &m, &s, &a, &b);
    --a; --b; --s;
    while(m--){
        int i, j;
        scanf(" %d%d", &i, &j); --i; --j;
        to[es] = j; nx[es] = ad[i]; ad[i] = es++;
        to[es] = i; nx[es] = ad[j]; ad[j] = es++;
    }

    fill(d,d+n,n<<1);
    d[s] = 0;
    q[qb++] = s;
    while(qb-qf > 0){
        int i = q[qf++];
        for(int e=ad[i];e;e=nx[e])
            if(d[to[e]] > d[i] + 1){
                d[to[e]] = d[i] + 1;
                q[qb++] = to[e];
            }
    }

    qb = qf = 0;
    q[qb++] = a;
    while(qb-qf > 0){
        int i = q[qf++];
        seen[i] = 1;
        for(int e=ad[i];e;e=nx[e])
            if(d[to[e]] + 1 == d[i])
                q[qb++] = to[e];
    }

    qb = qf = 0;
    q[qb++] = b;
    while(qb-qf > 0){
        int i = q[qf++];
        if(seen[i]){
            lca = i;
            break;
        }
        for(int e=ad[i];e;e=nx[e])
            if(d[to[e]] + 1 == d[i])
                q[qb++] = to[e];
    }

    printf("%d\n", d[lca]);
}
