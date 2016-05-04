#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5+7;
int n, sz[N], ps;
char * in[N], _in[N];

int main(){
    scanf(" %d", &n);
    for(int i=0;i<n;i++){
        in[i] = _in+ps;
        scanf(" %s", _in+ps);
        sz[i] = strlen(in[i]);
        ps += sz[i] + 1;
        sort(in[i],in[i]+sz[i]);
    }
    map<string, int> freq;
    for(int i=0;i<n;i++) freq[string(in[i])]++;
    int ans = 0;
    for(auto it : freq) ans = max(ans, it.second);
    printf("%d\n", ans);
}
