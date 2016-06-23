#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

ll ans;
int n, m, cnt[5];

int main(){
    cin >> n >> m;
    if(n > m) swap(n,m);

    for(int i=0;i<5;i++) cnt[i] = m/5;
    for(int i=1+m-m%5;i<=m;i++) cnt[i%5]++;

    for(int i=1;i<=n;i++) {
        if(i%5) ans += ll(cnt[5-i%5]);
        else    ans += ll(cnt[0]);
    }

    cout << ans << endl;
}
