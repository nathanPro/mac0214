#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

const int N = 5e5;
int n, p[N], q[N], a[N], b[N], d[N];

int c[N];
void insert(int p){ for(p++;p<=n;p+=(p&-p)) c[p] += 1; }
int count(int p){
    int ans = 0;
    for(p++;p;p-=(p&-p)) ans += c[p];
    return ans;
}

void find(int * p, int * a){
    for(int i=1;i<n+1;i++) c[i] = 0*(i&(-i));
    for(int i=0;i<n;i++){
        a[i] = p[i] - count(p[i]);
        insert(p[i]);
    }
    reverse(a,a+n);
}

int main(){
    scanf(" %d", &n);
    for(int i=0;i<n;i++) scanf(" %d", p+i);
    for(int i=0;i<n;i++) scanf(" %d", q+i);

    find(p,a);
    find(q,b);
    int carry = 0;
    for(int i=0;i<n+1;i++) {
        int partial = a[i] + b[i] + carry;
        if(partial > i) carry = 1, partial -= (i+1);
        else carry = 0;
        d[i] = partial;
    }
    reverse(d,d+n); fill(c,c+1+n, 0);
    for(int i=0;i<n;i++){
        int lo = 0, hi = n;
        while(lo < hi){
            int mid = (lo+hi)/2,
                  k = mid - count(mid);
            if(k >= d[i]) hi = mid;
            else          lo = mid+1;
        }
        printf("%d%c", lo, " \n"[i+1==n]);
        insert(lo);
    }
}
