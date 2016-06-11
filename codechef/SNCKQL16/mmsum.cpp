#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

const int N = 1e5;
const int oo = 1e9+7;
int t, n;
ll a[N], ans, S[2][N];

int main(){
    scanf(" %d", &t);
    while(t--){
        scanf(" %d", &n);
        for(int i=0;i<n;i++) scanf(" %lld", a+i);
        S[0][0] = a[0]; S[1][0] = -oo;
        S[0][1] = max(a[0] + a[1],a[1]);
        S[1][1] = max(a[0], a[1]);
        for(int i=2;i<n;i++){
            S[0][i] = max(a[i], S[0][i-1] + a[i]);
            S[1][i] = max(S[0][i-1], S[1][i-1] + a[i]);
        }
        ans = -oo;
        for(int i=0;i<2;i++)
            for(int j=0;j<n;j++)
                ans = max(ans, S[i][j]);
        printf("%lld\n", ans);
    }
}
