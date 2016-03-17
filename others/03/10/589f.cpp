#include <bits/stdc++.h>
#define mt make_tuple
using namespace std;
typedef long long ll;

const int N = 100;

int i, t;
int n;
int a[N], b[N], p[N];
int lo, hi, k, cnt, cs;
tuple<int,int,int> curr[N];

int main(){
    scanf(" %d", &n);
    for(i=0;i<n;i++) scanf(" %d%d", a+i, b+i), p[i] = i;
    int _t = *min_element(a,a+n), t_ = *max_element(b,b+n);
    sort(p,p+n,[&](int i, int j){ return mt(a[i],b[i],i) < mt(a[j],b[j],j); });

    lo = 0; hi = t_;
    while(lo < hi){
        k = (lo+hi+1)/2;
        i = cnt = cs = 0;
        for(int t=_t;t<t_+1;t++){
            for(;i<n && a[p[i]] <= t;i++)
                curr[cs++] = mt(-b[p[i]],-a[p[i]],k), push_heap(curr, curr+cs);
            while(cs > 0 && -get<0>(curr[0]) <= t) pop_heap(curr,curr+(cs--));
            if(!cs) continue;
            int a, b, _k;
            pop_heap(curr,curr+cs);
            tie(b,a,_k) = curr[--cs];
            b *= -1; a *= -1;
            if(_k == 1) cnt++;
            else curr[cs++] = mt(-b,-a,_k-1),push_heap(curr, curr+cs);
        }
        if(cnt == n) lo = k;
        else hi = k-1;
    }
    printf("%d\n", lo*n);
}
