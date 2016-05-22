#include <bits/stdc++.h>
#define ld " PRId64"
#define lu " PRIu64"
using namespace std;
typedef long long ll;
typedef unsigned int uint;

const int N = 1e6;
const int M = 2+(N<<5);
const int c = 8*sizeof(uint);

int n, k, l;
uint tree, ts = 1;
uint sz[M], T[M][2];
ll ans;

inline bool gbit(uint x, int i) { return (x>>i)&1u; }
void insert(int t, uint x){
    bool b;
    for(int d=c-1;1+d;--d, t=T[t][b]){
        sz[t]++; b = gbit(x,d);
        if(!T[t][b]) T[t][b] = ts++;
    }
    sz[t]++;
}
void count(int t, uint x){
    uint pref = 0;
    for(int d=c-1;d+1;--d){
        bool b = gbit(x,d);
        if(pref + (1u<<d) >= k)
            ans += sz[T[t][1^b]], t = T[t][b];
        else pref += (1u<<d), t = T[t][1^b];
    }
    ans += (x >= k);
}

uint acc;
int in;
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> k;
    tree = ts++;
    for(int i=1;i<1+n;i++) {
        cin >> in;
        acc ^= in;
        count(tree, acc);
        insert(tree,acc);
    }
    cout << ans << endl;
}
