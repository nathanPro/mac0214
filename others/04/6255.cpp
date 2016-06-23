#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 20;
const int S = 1<<N;

int n;
int d[N][N], ans[N], as;
int sol[S];

int i, j, s, t, tc;
int main(){
    scanf(" %d", &tc);
    for(t=1;t<tc+1;t++){
        scanf(" %d", &n);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++) scanf(" %d", &d[i][j]);

        sol[(1<<n)-1] = t;
        for(s = (1<<n)-1;s;--s)
            if(sol[s] == t){
                for(i=0;i<n;i++)
                    if(s&(1<<i)){
                        int dbt = 0;
                        for(j=0;j<n;j++) if(s&(1<<j)) dbt += d[i][j];
                        if(dbt > 0) sol[s-(1<<i)] = t;
                    }
            }
        as = 0;
        for(i=0;i<n;i++) if(sol[1<<i] == t) ans[as++] = i;
        if(as){
            for(i=0;i<as;i++) printf("%d%c", ans[i]+1, " \n"[i+1==as]);
        } else printf("%d\n", as);
    }
}
