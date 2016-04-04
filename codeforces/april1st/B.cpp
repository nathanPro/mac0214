#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 20;
const int S = 1e6;
ll gcd(ll a, ll b){ return b? gcd(b,a%b) : a; }
ll mmc(ll a, ll b){ return a/gcd(a,b)*b; }

int n, me, M;
int r[N], m[N], seen[S];

int main(){
    scanf(" %d", &n);
    for(int i=0;i<n;i++) scanf(" %d", m+i);
    for(int i=0;i<n;i++) scanf(" %d", r+i);
    M = 1;
    for(int i=0;i<n;i++) M = mmc(m[i], M);
    for(int i=0;i<n;i++)
        for(int j=r[i];j<M;j+=m[i]) seen[j]|= 1; 
    for(int i=0;i<M;i++) me += seen[i];
    printf("%.20lf\n", 1.*me/M);
}
