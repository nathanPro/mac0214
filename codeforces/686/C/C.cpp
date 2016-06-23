#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

int p[] = {0, 1, 2, 3, 4, 5 ,6};
int n, k, d[2], t;
set<int> seen;

int mask(){
    int ans = 0;
    for(int i=0;i<t;i++)
        ans *= 7, ans += p[i];
    return ans;
}

int digits(int x){
    int ans = 0, aux = 1;
    for(;aux <= x; aux *= 7) ans++;
    return max(ans, 1);
}

int main(){
    scanf(" %d%d", &n, &k);
    t = (d[0] = digits(n-1)) + (d[1] = digits(k-1));
    if(t > 7){
        printf("%d\n", 0);
        return 0;
    }
    do {
        int h = 0, m = 0;
        for(int i=0;i<d[0];i++) h *= 7, h += p[i];
        for(int i=d[0];i<t;i++) m *= 7, m += p[i];
        if(h < n && m < k) seen.insert(mask());
    } while( next_permutation(p,p+7) );
    printf("%u\n", seen.size());
}
