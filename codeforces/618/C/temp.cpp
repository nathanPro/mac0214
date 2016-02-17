#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long num;
typedef double cood;


const int N = 2e5;
const cood eps = 1e-9;
int n;
int x[N], y[N], p[N];

int main()
{
    scanf(" %d", &n);
    for(int i=0;i<n;i++)
    {
        scanf(" %d%d", x+i, y+i);
        p[i] = i;
    }
    sort(p, p+n, [&](int i, int j){ return mp(x[i], y[i]) < mp(x[j], y[j]); });
    for(int i=2;i<n;i++)
        if(fabs(cood(x[p[1]]-x[p[0]])*cood(y[p[i]]-y[p[1]]) - cood(y[p[1]]-y[p[0]])*cood(x[p[i]]-x[p[1]])) > eps)
        {
            printf("%d %d %d\n", p[0]+1, p[1]+1, p[i]+1);
            return 0;
        }
}
