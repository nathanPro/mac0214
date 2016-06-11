#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }
const ll u = 1ll;

inline ll countOn(ll x, int k) { 
    printf("%lld %d : %lld + %lld\n", x, k, ((x>>k)&u)*(u + x%(u<<k)), (((x>>k)<<(k-1)) - u));
    return ((x>>k)&u)*(u + x%(u<<k)) + ((x>>k)<<(k-1)); 
}

int l, r;
int main(){
    for(int i=0;i<16;i++) printf("%d %lld\n", i, countOn(i, 2));
}
