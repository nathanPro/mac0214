#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

const int N = 201;
const int Z = 256;

int n, m;
int cost[Z];
char s[N], g[N];

int main(){
    for(int i=0;i<Z;i++) cost[i] = 200;
    scanf(" %d%d", &n, &m);
    scanf(" %s", g);
    for(int i=0;i<m;i++){
        int l, c;
        scanf(" %d%d", &l, &c);
        for(int j=0;j<l;j++){
            char curr;
            scanf(" %c", &curr);
            _min(cost[curr], c);
        }
    }
    int tot = 0;
    for(int i=0;i<n;i++)
        if(cost[g[i]] == 200){
            puts("-1");
            return 0;
        } else tot += cost[g[i]];
    printf("%d\n", tot);
}
