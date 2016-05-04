#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
typedef long long ll;

const int N = 2e6;
int v[N], bst[N], n;

int main(){
    scanf(" %d", &n);
    for(int i=0;i<n;i++) scanf(" %d", v+i);
    bst[n-1] = v[n-1];
    for(int i=n-2;i+1;--i){
        bst[i] = bst[i+1];
        _max(bst[i], v[i] + bst[i+3]);
    }
    printf("%d\n", bst[0]);
}
