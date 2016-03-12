#include <bits/stdc++.h>
#define mt make_tuple
using namespace std;
typedef long long ll;

const int N = 2e5;

int n, m;
ll a[N], b[N];
set<tuple<int,int,int>> line, aux;

void update(ll *v, int p, ll x)
{ for(;p>0;p-=(p&-p)) v[p] += x; }
inline void update(ll * v, int l, int r, ll x)
{ update(v, r, x); update(v, l-1, -x); }
void sum(int l, int r, ll x){
    update(b, l,   r, -ll(l-1)*x);
    update(b, r+1, n, ll(r-l+1)*x);
    update(a, l, r, x);
}

ll get(ll *v, int p){
    ll ans = 0;
    for(;p && p<=n;p+=(p&-p)) ans += v[p];
    return ans;
}
ll get(int p)
{ return get(b, p) + ll(p)*get(a,p); }
ll query(int l, int r)
{ return get(r) - get(l-1); }


int i, j, cmd;
int main(){
    scanf(" %d%d", &n, &m);
    for(i=1;i<=n;i++) line.insert(mt(i,i,i));
    while(m--){
        scanf(" %d", &cmd);
        if(cmd == 1){
            int nl, nr, nc;
            scanf(" %d%d%d", &nl, &nr, &nc);
            auto ns = mt(nl,nr,nc);
            auto it = line.upper_bound(ns);
            if(it != line.begin()) --it;
            while(it != line.end() && get<0>(*it) <= nr){
                int _l, _r, _c, il, ir;
                tie(_l,_r,_c) = *it;

                il = max(_l, nl);
                ir = min(_r, nr);
                if(ir-il >= 0){
                    sum(il, ir, max(nc-_c,_c-nc));
                }
                if(il != _l) aux.insert(mt(_l, il-1, _c));
                if(ir != _r) aux.insert(mt(ir+1, _r, _c));

                line.erase(it++);
            }
            for(auto it: aux) line.insert(it);
            line.insert(mt(nl,nr,nc));
            aux.clear();
        } else {
            int l, r;
            scanf(" %d%d", &l, &r);
            printf("%I64d\n", query(l,r));
        }
    }
}
