#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

const int N = 2e5;
int a[N], ans, n;
set<int> seen;

int main(){
    scanf(" %d", &n);
    for(int i=1;i<1+n;i++) scanf(" %d", a+i);
    sort(a+1, a+1+n);
    for(int i=1;i<1+n;i++)
        seen.insert(a[i] = min(a[i], 1+a[i-1]));

    for(int i=1;i<=1+n;i++)
        if(seen.count(i) == 0) {
            printf("%d\n", i);
            return 0;
        }
}
