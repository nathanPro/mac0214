#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5+1;
const int T = 3500000;
int q, n;
int seen[N], ss;
int l[N], r[N], x[N];
int tp;
char aux, in[500];
ll ans[3];

int tree[N];
int lc[T], rc[T], sum[T], ts;
int ql, qr, qa;
int build(int t, int l, int r){
    lc[t] = rc[t] = -1; sum[t] = 0;
    if(l+1 == r) return t;
    int mid = (l+r)>>1;
    lc[t] = build(ts++,l,mid); rc[t] = build(ts++,mid,r);
    return t;
}
int update(int t, int l, int r, int p){
    int nt = ts++;
    lc[nt] = lc[t]; rc[nt] = rc[t]; sum[nt] = sum[t] + (l+1 == r);
    if(l+1 == r) return nt;
    int mid = (l+r)>>1;
    if(p < mid) lc[nt] = update(lc[t], l, mid, p);
    else        rc[nt] = update(rc[t], mid, r, p);
    sum[nt] = sum[lc[nt]] + sum[rc[nt]];
    return nt;
}
void query(int t, int l, int r){
    if(ql <= l && r <= qr) return (void)(qa += sum[t]);
    if(r <= ql || qr <= l) return;
    int mid = (l+r)>>1;
    query(lc[t], l, mid); query(rc[t], mid, r);
}
int iquery(int tl, int tr, int l, int r, int k){
    if(l+1 == r) return l;
    int sl  =  lc[tr] == -1? 0 : sum[lc[tr]];
        sl -= (lc[tl] == -1? 0 : sum[lc[tl]]);
    int mid = (l+r)>>1;
    if(k <= sl) return iquery(lc[tl], lc[tr], l, mid, k);
    else return iquery(rc[tl], rc[tr], mid, r, k-sl);

}

int i, j, k, tc;
int main(){
    while(scanf(" %d", &q) != EOF){
        ts = ss = n = 0;
        memset(ans, 0, sizeof ans);

        for(i=0;i<q;i++){
            scanf(" %c", &aux);
            if(aux == 'I') scanf("%*s %d", x+i), l[i] = r[i] = -1;
            else {
                scanf("%s", in); for(j=0;in[j]!='_';j++); j++;
                tp = in[j]-'0';
                if(tp == 1) scanf(" %d%d%d", l+i, r+i, x+i), l[i]--;
                else scanf(" %d", x+i), l[i] = tp, r[i] = -1;
            }
            seen[ss++] = x[i];
        }
        sort(seen, seen+ss); ss = unique(seen,seen+ss)-seen;
        tree[0] = build(ts, 0, ss);
        for(i=0;i<q;i++){
            if(l[i] == -1){
                tree[n+1] = update(tree[n], 0, ss, lower_bound(seen,seen+ss,x[i])-seen);
                n++;
            }
            else if(r[i] == -1 && l[i] == 2){
                qa = ql = 0; qr = lower_bound(seen,seen+ss,x[i])-seen;
                query(tree[n], 0, ss);
                ans[1] += ll(1+qa);
            }
            else if(r[i] == -1 && l[i] == 3) ans[2] += ll(seen[iquery(tree[0], tree[n], 0, ss, x[i])]);
            else           ans[0] += ll(seen[iquery(tree[l[i]], tree[r[i]], 0, ss, x[i])]);
        }
        printf("Case %d:\n", ++tc);
        for(i=0;i<3;i++) printf("%lld\n", ans[i]);
    }
}
