#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

const int N = 1+1e5;
int A[N], S[N];

int t, n;
int main(){
    scanf(" %d", &t);
    while(t--){
        scanf(" %d", &n);
        for(int i=1;i<n+1;i++) scanf(" %d", A+i);
        for(int i=1;i<n+1;i++) S[i] = 1 + S[i-1]*(A[i] == A[i-1]);
        if(*max_element(S,S+n+1) >= 3) puts("Yes");
        else puts("No");
    }
}
