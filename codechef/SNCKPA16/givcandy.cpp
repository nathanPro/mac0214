#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

ll a, b, c, d, e;
inline ll gcd(ll a, ll b){ return b? gcd(b,a%b): a; }

int t;
int main(){
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> d;
        e = gcd(c,d);
        if(e == 1ll) puts("0");
        else {
            ll ans = abs(b-a);

            _min(ans, abs(b-a - (b-a)/e*e));
            _min(ans, abs(b-a - (b-a-ll(1)+e)/e*e));
            _min(ans, abs(a-b - (a-b)/e*e));
            _min(ans, abs(a-b - (a-b-ll(1)+e)/e*e));

            cout << ans << endl;
        }
    }
}
