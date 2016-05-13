#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
template<typename T> void _max(T& a, T b) { a = max(a,b); }
template<typename T> void _min(T& a, T b) { a = min(a,b); }

const int N = 1e3;
const int Z = 5*60;
int f[2], d[2], qf, qb;
int q[N];
int dep, ans, aux;

bool inRange(int l, int x, int r){ return l < x && x < r; }

int main(){
    for(int i=0;i<2;i++) scanf(" %d%d", f+i, d+i);
    scanf(" %d:", &aux); dep = 60*aux;
    scanf("  %d", &aux); dep += aux;
    for(int t=Z;t<24*60;t+=f[1]){
        ans += ((t+d[1]-dep)*(dep+d[0]-t) > 0);
    }
    printf("%d\n", ans);
}
