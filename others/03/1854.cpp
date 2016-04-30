#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e3+7;
const int K = 1e7+2e3;
const int MOD = 1e9+7;

struct mod
{
    int x;
    mod() : x(0) {}
    mod(int a) : x(a) {};
    mod operator+(const mod & b) { return (ll(x)+ll(b.x))%MOD ; }
    mod operator*(const mod & b) { return (ll(x)*ll(b.x))%MOD ; }
};

char in[200];
mod fac[K], inv[K];
int bit[N][N];
int i, n, m, dc;

void insert(int x, int _y, int v){
    for(x++;x<N;x+=(x&-x))
        for(int y=_y+1;y<N;y+=(y&-y))
            bit[x][y] += v;
}
int get(int x, int _y){
    int ans = 0;
    for(x++;x;x-=(x&-x))
        for(int y=_y+1;y;y-=(y&-y))
            ans += bit[x][y];
    return ans;
}
inline int get(int x, int y, int _x, int _y)
{ return get(_x,_y) - get(_x,y-1) + get(x-1,y-1) - get(x-1,_y); }
void clear(int x, int y)
{ insert(x,y,-get(x,y,x,y)); }

inline mod comb(int a, int b){
    if(min(a,b) < 0 || b > a) return 0;
    return fac[a]*inv[b]*inv[a-b];
}

int main(){
    fac[0] = 1;
    for(i=1;i<K;i++) fac[i] = mod(i)*fac[i-1];
    inv[K-1] = 1; mod a = fac[K-1];
    for(int e=MOD-2;e;e>>=1, a = a*a)
        if(e&1) inv[K-1] = inv[K-1]*a;
    for(i=K-2;i>=0;--i) inv[i] = mod(i+1)*inv[i+1];

    scanf(" %d%d", &n, &m);
    while(!feof(stdin)) {
        int a, b, c, d, e, r;
        scanf(" %[^\n]", in);
        if(feof(stdin)) break;
        r = sscanf(in, " %d%d%d%d%d", &a, &b, &c, &d, &e);
        if(r == 5)
            printf("Day #%d: %d\n", ++dc, comb(get(a,b,c,d)+e-1,e));
        else if(r == 3)
            insert(a,b,c);
        else if(r == 2)
            clear(a,b);
    }
}
