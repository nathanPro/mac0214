#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T> void _max(T& a, T b) { a = max(a,b); }
template<typename T> void _min(T& a, T b) { a = min(a,b); }

const int N = 101;
int n, m, k;
int in[N], aux[N], is, as, ans;

int main(){
    scanf(" %d%d%d", &n, &m, &k);
    for(int i=0;i<k;i++) scanf(" %d", in+i);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int p; scanf(" %d", &p);
            as = 0;
            for(int a=0;a<k;a++)
                if(in[a] == p) ans += 1+a;
                else aux[as++] = in[a];
            in[0] = p;
            for(int a=0;a<as;a++) in[1+a] = aux[a];
        }
    }
    printf("%d\n", ans);
}
