#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5;
int in[N], n;
int bit[N];

void erase(int p){
    for(p+=1;p<=n;p+=(p&-p)) bit[p] -= 1;
}
int get(int p){
    int ans = 0;
    if(p <= 0) return ans;
    for(p+=1;p>0;p-=(p&-p)) ans += bit[p];
    return ans;
}

map<int, int> pos;
int main(){
    scanf(" %d", &n);
    for(int i=1;i<=n;i++) bit[i] = (i&-i);
    for(int i=0;i<n;i++) scanf(" %d", in+i), pos[in[i]] = max(pos[in[i]], i);

    int td = 0;
    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        erase(i); erase(pos[in[i]]);
        ans += ll(get(pos[in[i]]) - get(i));
    }
    printf("%lld\n", ans);
}

