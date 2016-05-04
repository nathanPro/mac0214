#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
typedef long long ll;

const int S = 1e4;
char in[S];
int n;
ll a, b, d;

inline ll gcd(ll a, ll b) { return b? gcd(b,a%b) : a; }

int main(){
    scanf(" %s", in);
    n = strlen(in);
    for(int i=0;i<n;i++) {
        if(in[i] == '.') b = 100;
        else {
            a *= 10; a += ll(in[i] - '0');
            b *= 10;
        }
    }
    _max(b,100ll);
    cout << b/gcd(a,b) << endl;
}
