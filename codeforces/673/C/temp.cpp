#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T> void _max(T& a, T b) { a = max(a,b); }
template<typename T> void _min(T& a, T b) { a = min(a,b); }

const int N = 5e3+7;
int n, a[N], ans[N];
int bst, dc;
int freq[N];

int main(){
    scanf(" %d", &n);
    for(int i=0;i<n;i++) scanf(" %d", a+i);
    for(int i=0;i<n;i++) {
        fill(freq,freq+n+1,0);

        freq[a[i]]++;
        bst = 1;
        dc = a[i];

        for(int j=i+1;j<n+1;j++){
            ans[dc]++;
            freq[a[j]]++;
            if(freq[a[j]] >  bst) dc = a[j];
            if(freq[a[j]] == bst) _min(dc, a[j]);
            _max(bst, freq[a[j]]);
        }
    }
    for(int i=1;i<n+1;i++) printf("%d%c", ans[i], " \n"[i==n]);
}
