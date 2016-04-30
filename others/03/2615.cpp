#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
const int N = 103;
const int B = 53;
const ll inf = 1e18;

int x[N], y[N];
ll sol[B][N<<1][N<<1];
int n, b;
int p[N<<1], h[N], hs;

ll cross(int i, int j, int k)
{ return (x[k]-x[j])*(y[i]-y[j]) - (y[k]-y[j])*(x[i]-x[j]);}
ll sgn(ll x){ return (x>0)-(x<0); }
bool angLess(int i, int j){
    if(sgn(cross(0,1,i))*sgn(cross(0,1,j)) > 0) return sgn(cross(0,i,j)) == 1;
    return sgn(cross(0,1,i)) == 1;
}

int main(){
    while(scanf(" %d%d", &b, &n) && n){
        for(int i=0;i<n;i++) scanf(" %d%d", x+i, y+i);

        for(int i=0;i<n;i++) p[i] = i;
        sort(p+2,p+n,angLess);
        for(int i=0;i<n-1;i++) p[i] = p[i+1];
        n--;
        for(int i=n;i<2*n;i++) p[i] = p[i-n];

        for(int i=0;i<(n<<1);i++)
            for(int j=i+1;j<min(i+n,n<<1)+1;j++){
                if(j-i < 2) sol[1][i][j] = inf;
                else{
                    hs = 0;
                    for(int k=i;k<j;k++){
                        while(hs > 1 && sgn(cross(h[hs-2],h[hs-1],p[k])) < 1) hs--;
                        h[hs++] = p[k];
                    }
                    if(sgn(cross(h[hs-2],h[hs-1],0)) == 1){
                        h[hs++] = 0;
                        sol[1][i][j] = 0;
                        for(int k=1;k<hs-1;k++)
                            sol[1][i][j] += abs(cross(h[0],h[k],h[k+1]));
                    } else sol[1][i][j] = inf;
                }
                if(j+n <= (n<<1)) sol[1][i+n][j+n] = sol[1][i][j];
            }
        for(int k=2;k<=b;k++)
            for(int t=1;t<=n;t++)
                for(int i=0;i+t<=(n<<1);i++){
                    sol[k][i][i+t] = inf;
                    for(int j=i+1;j<i+t;j++)
                        sol[k][i][i+t] = min(sol[k][i][i+t], sol[1][i][j] + sol[k-1][j][i+t]);
                }
        ll ans = inf;
        for(int i=0;i<n;i++) ans = min(ans,sol[b][i][i+n]);
        printf("%.2lf\n", .5*ans);
    }
}
