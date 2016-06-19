#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

const int N = 1e6;
bool comp[N];
ll primes[N], p, aux;
int ps, ok;

int t, n;
int main(){
    for(ll i=2;i<N;i++)
        if(!comp[i]){
            primes[ps++] = i;
            for(ll j=i*i;j<N;j+=i) comp[j] = 1;
        }
    scanf(" %d", &t);
    while(t--){
        scanf(" %d", &n);
        aux = n;
        ok = 0;
        for(int i=0;i<ps;i++)
            if(n%primes[i] == 0){
                for(p=primes[i];p<n;p*=primes[i]);
                n /= p;
                break;
            }
        if(n == aux || n == 1) puts("Chef");
        else                   puts("Misha");
    }
}
