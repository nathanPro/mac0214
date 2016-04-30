#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
const int N = 3e4+5;
const int M = 2*5*N+2;
const int inf = 1e9;

int n, m;
int ad[N], rk[N];
int to[M], nx[M], w[M], es, sol;

vector<int> kr[11];
int d[N], gd[N], seen[N], dji;
set<pair<int, int>> reach;

void relax(int i){
    for(int e=ad[i];e;e=nx[e])
        if(d[to[e]] > d[i] + w[e])
            reach.insert(mp(d[to[e]] = d[i] + w[e], to[e]));
}

void mrk(int s){
    ++dji; reach.clear();
    fill(d, d+n, inf);
    reach.insert(mp(0, s)); d[s] = 0;
    while(!reach.empty()){
        int i = reach.begin()->second; reach.erase(reach.begin());
        if(seen[i] == dji) continue; seen[i] = dji;
        if(d[i] < gd[i]) sol++, relax(i);
    }
}
void update(int k){
    ++dji; reach.clear();
    fill(d, d+n, inf);
    for(int i: kr[k]) reach.insert(mp(0,i)), d[i] = 0;
    while(!reach.empty()){
        int i = reach.begin()->second; reach.erase(reach.begin());
        if(seen[i] == dji) continue; seen[i] = dji;
        gd[i] = min(gd[i], d[i]); relax(i);
    }
}

int main(){
    int tc; scanf(" %d", &tc);
    for(int tcn=0;tcn<tc;tcn++){
        if(tcn) putchar('\n');
        scanf(" %d%d", &n, &m);

        fill(ad, ad+n, 0); es = 2;
        fill(gd, gd+n, inf);
        sol = 0;
        for(int i=0;i<11;i++) kr[i].clear();

        for(int i=0;i<n;i++) scanf(" %d", rk+i), kr[rk[i]].push_back(i);
        while(m--){
            int i, j, c;
            scanf(" %d%d%d", &i, &j, &c); --i; --j;
            to[es] = j; nx[es] = ad[i]; w[es] = c; ad[i] = es++;
            to[es] = i; nx[es] = ad[j]; w[es] = c; ad[j] = es++;
        }
        for(int k=10;k+1;--k)
            if(kr[k].size()){
                for(int i : kr[k]) mrk(i);
                update(k);
            }
        printf("%d\n", sol);
    }
}
