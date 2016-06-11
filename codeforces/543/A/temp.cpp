#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

const int N = 505;
int n, m, b, _M;
ll M;

struct mod{
    int x;
    mod() : x(0) {}
    mod(ll a) : x(a%M) {}
    mod operator+(mod b) { return (ll(x) + ll(b.x))%M;}
} S[2][N][N]; // b bugs, m lines
int A[N];


int main(){
    scanf(" %d%d%d%d", &n, &m, &b, &_M);
    M = _M;
    for(int i=0;i<n;i++) scanf(" %d", A+i);
    for(int b=0;b<=::b;b++) S[n&1][b][0] = 1;

    for(int i=n-1;i+1;i--)
        for(int b=0;b<=::b;b++)
            for(int m=0;m<=::m;m++){
                S[i&1][b][m] = S[(i+1)&1][b][m];
                if(b >= A[i]) S[i&1][b][m] = S[i&1][b][m] + S[i&1][b-A[i]][m-1];
            }
    printf("%d\n", (S[0][b][m].x+M)%M);
}
