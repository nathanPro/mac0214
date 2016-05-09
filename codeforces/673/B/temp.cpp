#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T> void _max(T& a, T b) { a = max(a,b); }
template<typename T> void _min(T& a, T b) { a = min(a,b); }

const int N = 2e5+7;
const int M = 2e5+7;

int n, m;
int ad[N], sz[N], cl[N], in[N], out[N], is, os;
int to[M], nx[M], es;
int ok;

void dfs(int i, int c){
    cl[i] = c;
    sz[i] = 1;
    for(int e=ad[i];e;e=nx[e])
        if(sz[to[e]] == 0) dfs(to[e],c^1);
        else ok &= (cl[to[e]] != c);
}

int main(){
    scanf(" %d%d", &n, &m);
    es = 2;
    for(int i=0;i<m;i++){
        int j, k;
        scanf(" %d%d", &j, &k); --j; --k;
        to[es] = k; nx[es] = ad[j]; ad[j] = es++;
        to[es] = j; nx[es] = ad[k]; ad[k] = es++;
    }
    ok = 1;
    for(int i=0;i<n;i++) if(!sz[i]) dfs(i,0);
    for(int i=0;i<n;i++) if(ad[i] != 0) {
        if(cl[i]) in[is++] = i;
        else out[os++] = i;
    }
    if(is > 0 && os > 0){
        ok &= ((*max_element(in, in+is))<(*min_element(out, out+os)) ||
                (*max_element(out, out+os)<(*min_element(in, in+is)))
              );
    }
    if(!ok) printf("%d\n", 0);
    else {
        int lo, hi;
        if(is > 0 && os > 0) {
            lo = min(*max_element(in,in+is),*max_element(out,out+os));
            hi = max(*min_element(in,in+is),*min_element(out,out+os));
            int k = 1;
            for(int i=lo;i<hi+1;i++) if(ad[i] == 0) k++;
            printf("%d\n", k);
        } else if(is == 0 && os == 0) printf("%d\n", n-1);
        else printf("%d\n", 1);
    }
}
