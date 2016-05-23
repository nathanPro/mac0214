#include <bits/stdc++.h>
#define mt make_tuple
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b) { a = max(a,b); }
template<typename T> inline void _min(T& a, T b) { a = min(a,b); }

const int N = 1000;
int a[N], b[N<<1], bs, n;

int main(){
    scanf(" %d", &n);
    for(int i=0;i<n;i++) scanf(" %d", a+i);
    b[bs++] = a[0];
    for(int i=1;i<n;i++){
        if(__gcd(a[i],b[bs-1]) != 1) b[bs++] = 1;
        b[bs++] = a[i];
    }
    printf("%d\n", bs-n);
    for(int i=0;i<bs;i++) printf("%d%c", b[i]," \n"[i+1==bs]);
}
