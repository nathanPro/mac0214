#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

int p, a, b;

int main(){
    scanf(" %d%d%d", &p, &a, &b);
    if(b > p) puts("-1");
    else      printf("%d\n", max(p,a+b));
}
