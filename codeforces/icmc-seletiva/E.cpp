#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
typedef long long ll;

const int N = 1e6;
int s[N], n, m;

int main(){
    scanf(" %d%d", &n, &m);
    for(int i=0;i<n;i++) scanf(" %d", s+i);
    sort(s,s+n);
    printf("%d\n", s[m-1]);
}
