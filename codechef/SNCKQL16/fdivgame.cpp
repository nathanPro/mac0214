#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

int brute(ll x){
    if(x == 0) return 0;
    int seen[7];
    for(int i=0;i<7;i++) seen[i] = 0;
    for(ll i=2;i<7;i++){
        int tmp = brute(x/i);
        if(tmp < 7) seen[tmp] = 1;
    }
    for(int i=0;i<7;i++) if(!seen[i]) return i;
}

int main(){
    for(ll i=0;i<100;i++) printf("%3lld %d\n", i, brute(i));
}
