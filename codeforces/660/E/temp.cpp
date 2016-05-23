#include <bits/stdc++.h>
#define mt make_tuple
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b) { a = max(a,b); }
template<typename T> inline void _min(T& a, T b) { a = min(a,b); }

const int N = 1+1e6;
const int P = 1e9+7;
struct mod{
    int x;
    mod() : x(0) {}
    mod(int a) : x(a) {} 
    mod operator+(mod b) { return (ll(x)+ll(b.x) + P)%P; }
    mod operator*(mod b) { return (ll(x)*ll(b.x))%P; }
};
mod fat[N], inv[N], ans;

mod fexp(mod a, int e){
    mod t = 1;
    for(;e;e>>=1,a=a*a)
        if(e&1) t = t*a;
    return t;
}
inline mod comb(int n, int k) { return fat[n]*inv[k]*inv[n-k]; }

int m, n;
int main(){
    ios::sync_with_stdio(false);

    fat[0] = 1;
    for(int i=1;i<N;i++) fat[i] = mod(i)*fat[i-1];
    inv[N-1] = fexp(fat[N-1],P-2);
    for(int i=N-2;i+1;i--) inv[i] = mod(i+1)*inv[i+1];

    cin >> n >> m;
    ans = fexp(m,n);
    for(int i=1;i<n+1;i++) ans = ans + comb(n,i-1)*fexp(m,i)*fexp(m-1,n-i);
    cout << ans.x << endl;
}
