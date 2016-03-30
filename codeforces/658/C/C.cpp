#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5;

int n, h, d;
int u, v;
int f[N], s[N], es;

int main(){
    scanf(" %d%d%d", &n, &d, &h);
    if((d+1)/2 > h) printf("%d\n", -1);
    else{
        u = v = 1;
        for(int i=0;i<h;i++){
            f[es] = u; s[es++] = ++v;
            u = v;
        }
        u = 1;
        for(int i=0;i<d-h;i++){
            f[es] = u; s[es++] = ++v;
            u = v;
        }
        u = 1;
        if(h == d){
            if(h > 1) u++;
            else{
                if(n == 2) printf("%d %d\n", 1, 2);
                else printf("%d\n", -1);
                return 0;
            }
        }
        for(v++;v<=n;v++){
            f[es] = u;
            s[es++] = v;
        }
        for(int i=0;i<es;i++) printf("%d %d\n", f[i], s[i]);
    }
}
