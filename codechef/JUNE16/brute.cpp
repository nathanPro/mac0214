#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

const int N = 1e6;
bool comp[N], win[N];
int prime[N], ps;

int brute(int x){
    set<int> seen;
    seen.insert(x-1);
    for(int i=0;i<ps;i++){
        for(ll p=1;p <= x; p *= prime[i])
            seen.insert(x-p);
    }
    for(int i=0;i<=x;i++) if(!seen.count(i)) return i;
}

int main(){
    for(ll i=2;i<N;i++)
        if(!comp[i]){
            prime[ps++] = i;
            for(ll j=i*i;j<N;j+=i) comp[j] = 1;
        }
    int n;
    scanf(" %d", &n);
    for(ll i=0;i<n;i++)
        if(brute(i) > 0){
            for(int j=0;j<ps;j++)
                if(i%prime[j] == 0){
                    ll p = prime[j];
                    for(;p<i;p*=prime[j]);
                    assert(p == i);
                }
        }
}
