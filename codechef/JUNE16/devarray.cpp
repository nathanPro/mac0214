#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

int lo, hi, n, q, in;
inline int inRange() { return lo <= in && in <= hi; }
int main(){
    lo = INT_MAX;
    scanf(" %d%d", &n, &q);
    while(n--) scanf(" %d", &in), _min(lo,in), _max(hi,in);
    while(q--) {
        scanf(" %d", &in);
        printf("%s\n", inRange() ? "Yes" : "No");
    }
}
