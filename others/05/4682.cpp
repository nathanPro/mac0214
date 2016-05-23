#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

const int N = 1e5;
const int M = 1+(N<<5);
const int c = 8*sizeof(uint);
inline bool gbit(uint x, int i){ return (x>>i)&1u; }

int n;
int T[M][2], ts, tree;
uint ans;
int create(){ int t = ts++; T[t][0] = T[t][1] = 0; return t; }

int tc;
int main(){
    scanf(" %d", &tc);
    while(tc--){
        ans = 0;
        uint acc = 0, in;
        ts = 0; tree = create();

        scanf(" %d", &n);
        for(int i=0;i<n;i++){
            scanf(" %u", &in);
            acc ^= in;
            int t = tree; uint bst = 0;
            for(int d=c-1;d+1;--d){
                bool b = gbit(acc,d);
                bst <<= 1;
                if(T[t][1^b]) bst |= (1^b), t = T[t][1^b];
                else bst |= b, t = T[t][b];
                if(!t) break;
            }
            _max(ans, acc);
            if(t) _max(ans, bst^acc);

            t = tree;
            for(int d=c-1;d+1;--d){
                bool b = gbit(acc,d);
                if(!T[t][b]) T[t][b] = create();
                t = T[t][b];
            }
        }
        printf("%u\n", ans);
    }
}
