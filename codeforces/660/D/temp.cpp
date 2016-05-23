#include <bits/stdc++.h>
#define mt make_tuple
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b) { a = max(a,b); }
template<typename T> inline void _min(T& a, T b) { a = min(a,b); }

const int N = 2e3;
int n;
int xin, yin;
pair<int,int> p[N];
map<pair<int,int>, int> freq;
ll ans;

inline ll pick(ll x){ return (x*(x-1ll))>>1; }
int main(){
    scanf(" %d", &n);
    for(int i=0;i<n;i++){
        scanf(" %d%d", &xin, &yin);
        p[i] = make_pair(xin, yin);
    }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            int x = p[i].first - p[j].first,
                y = p[i].second - p[j].second;
            freq[make_pair(x,y)]++;
            freq[make_pair(-x,-y)]++;
        }
    for(auto it: freq) ans += pick(it.second);
    printf("%I64d\n", ans>>2);
}
