#include <bits/stdc++.h>
using namespace std;
const int T = 1e5+2;

int x[T], y[T];
int lc[T], rc[T], sz[T], s[T], ts;
int tl, tr;

int node(int k){
    lc[ts] = rc[ts] = 0;
    sz[ts] = 1; x[ts] = k; s[ts] = 0;
    return ts++;
}
int lst(int t){
    while(rc[t] != 0) t = rc[t];
    return x[t];
}
int fst(int t){
    while(lc[t] != 0) t = lc[t];
    return x[t];
}
int calculate(int t){
    s[t] = s[lc[t]] + s[rc[t]];
    if(lc[t]) s[t] += (lst(lc[t]) != x[t]);
    if(rc[t]) s[t] += (x[t] != fst(rc[t]));
}
void split(int t, int k){
    if(!t) return (void)(tl = tr = 0);
    if(k <= sz[lc[t]]) split(lc[t], k), lc[t] = tr, tr = t;
    else split(rc[t],k-1-sz[lc[t]]), rc[t] = tl, tl = t;
    sz[t] = 1 + sz[lc[t]] + sz[rc[t]];
    calculate(t);
}
int merge(int tl, int tr){
    if(!min(tl,tr)) return max(tl,tr);
    int r = tr;
    if(y[tl] < y[tr]) lc[tr] = merge(tl, lc[tr]);
    else            rc[r=tl] = merge(rc[tl], tr);
    sz[r] = 1 + sz[lc[r]] + sz[rc[r]];
    calculate(r);
    return r;
}

int tc, tree, n;
int main(){
    srand(time(NULL));
    for(int i=0;i<T;i++) y[i] = i;
    random_shuffle(y,y+T);

    scanf(" %d", &tc);
    while(tc--){
        ts = 1;
        tree = 0;
        scanf(" %d", &n);
        while(n--) {
            int aux;
            scanf(" %d", &aux);
            tree = merge(tree, node(aux));
        }
        scanf(" %d", &n);
        while(n--) {
            int op, l, r;
            scanf(" %d%d%d", &op, &l, &r); --l;
            int lhs, mid, rhs;
            split(tree, r);
            mid = tl; rhs = tr;
            split(mid, l);
            lhs = tl; mid = tr;
            if(op == 1) {
                printf("%d\n", 1+s[mid]);
                tree = merge(merge(lhs, mid), rhs);
            } else tree = merge(merge(mid, lhs), rhs);
        }
    }
}
