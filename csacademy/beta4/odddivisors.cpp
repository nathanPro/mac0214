#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum(int x){
    ll ans = 0;
    while(x > 0){
        ll q = (x+1)>>1;
        ans += q*q;
        x >>= 1;
    }
    return ans;
}

int main(){
    int k, a, b;
    scanf(" %d", &k);
    while(k--){
        scanf(" %d%d", &a, &b);
        printf("%lld\n", sum(b)-sum(a-1));
    }
}

