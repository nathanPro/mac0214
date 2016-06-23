#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

const int N = 7 + 3e5;
const int M = N;

int n, q;
int ad[N], sz[N], ans[N], lnk[N];
int to[M], nx[M], es=1;
set<pair<int,int>> rng[N];

int find(int i){ return lnk[i] == i? i : lnk[i] = find(lnk[i]); }

int dfs(int i){
    sz[i] = 1;
    lnk[i] = i;
    int bs = 0;
    for(int e=ad[i];e;e=nx[e])
        if(!sz[to[e]]){
            int aux = dfs(to[e]);
            sz[i] += aux;
            if(aux > bs) bs = aux, lnk[i] = to[e];
        }
    if(sz[i] == 1) ans[i] = i;
    else {
        int j = find(i);
        if(sz[i] > rng[j].rbegin()->first) ans[i] = i;
        else ans[i] = rng[j].lower_bound(mp(sz[i],-1))->second;

    }
    rng[find(i)].insert(mp(sz[i]<<1, i));
    return sz[i];
}

int main(){
    scanf(" %d%d", &n, &q);
    for(int j=1;j<n;j++){
        int i; scanf(" %d", &i); i--;
        to[es] = j; nx[es] = ad[i]; ad[i] = es++;
    }
    dfs(0);
    while(q--){
        int v;
        scanf(" %d", &v);
        printf("%d\n", 1+ans[--v]);
    }
}
