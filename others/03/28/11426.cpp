#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4000001;

ll fct[N], g[N], tot[N];
ll d[N], aux[35];
int ds, as;

int main(){
    for(ll i=2;i<N;i++)
        if(!fct[i]){
            fct[i] = i;
            for(ll j=i*i;j<N;j+=i) fct[j] = i;
        }
    tot[1] = 1;
    for(ll i=2;i<N;i++){
        ll p=1;
        for(;i%(p*fct[i])==0;p*=fct[i]);
        tot[i] = (p-p/fct[i])*tot[i/p];
    }
    g[2] = d[0] = 1;
    for(ll i=3;i<N;i++){
        g[i] = g[i-1];
        ds = 1; ll n = i;
        while(n > 1){
            as = 0;
            ll p=1;
            for(;n%(p*fct[n])==0;p*=fct[n]) aux[as++] = p;
            aux[as++] = p;
            for(int j=0;j<as*ds;j++) d[j] = d[j%ds]*aux[j/ds];
            ds *= as;
            n /= p;
        }
        for(int j=0;j<ds;j++) if(d[j] != i) g[i] += d[j]*tot[i/d[j]];
    }
    int in;
    while(scanf(" %d", &in) != EOF && in > 0) printf("%lld\n", g[in]);
}
