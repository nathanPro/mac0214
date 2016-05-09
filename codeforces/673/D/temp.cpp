#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T> void _max(T& a, T b) { a = max(a,b); }
template<typename T> void _min(T& a, T b) { a = min(a,b); }

const int N = 1e3;
int n, k, ava[N], as, fix[4], aux[4];

int main(){
    scanf(" %d%d", &n, &k);
    if(n == 4 || k < n+1) {
        printf("-1\n");
        return 0;
    }
    for(int i=0;i<4;i++) {
        scanf(" %d", fix+i);
        aux[i] = fix[i];
    }
    sort(aux, aux+4);
    for(int i=1;i<n+1;i++) if(!binary_search(aux,aux+4,i)) ava[as++] = i;

    printf("%d %d %d %d", fix[0], fix[2], ava[0], fix[3]);
    for(int i=1;i<as;i++) printf(" %d", ava[i]);
    printf(" %d\n", fix[1]);

    printf("%d %d %d %d", fix[2], fix[0], ava[0], fix[1]);
    for(int i=as-1;i>0;--i) printf(" %d", ava[i]);
    printf(" %d\n", fix[3]);
}
