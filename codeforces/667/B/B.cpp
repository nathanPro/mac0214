#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5;
int in[N], n;
ll tot, l[N];

int main(){
    scanf(" %d", &n);
    for(int i=0;i<n;i++){
        scanf(" %d", in+i);
        tot += (l[i] = in[i]);
    }
    ll ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, (l[i]<<1)-tot);
    cout << 1ll + ans << endl;
}
