#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

const int N = 1e5;
int n, ans, s[N], out[N], in[N], os, is;
map<int, int> freq;

int main(){
    scanf(" %d", &n);
    for(int i=0;i<n;i++) scanf(" %d", s+i);
    sort(s,s+n);
    for(int i=0;i<n;i++){
        if(lower_bound(s,s+n,s[i]<<1) < s+n) in[is++] = s[i];
        else out[os++] = s[i];
    }
    ans = os;
    for(int i=is-1;i+1;i--){
        if(os && lower_bound(out,out+os,in[i]<<1) < out+os) os--;
        else if(freq.lower_bound(in[i]<<1) != freq.end()) {
            int tgt = freq.rbegin()->first;
            if(--freq[tgt] == 0) freq.erase(tgt);
        }
        else freq[in[i]]++, ans++;
    }
    printf("%d\n", ans);
}
