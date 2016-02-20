#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long num;

const int N = 1e5;
int n;
num v[N], tree[2*N];
int p[N], l[N], r[N];

void insert(int p, num x)
{
    for(tree[p+=n]=x;p>1;p>>=1)
        tree[p>>1] = max(tree[p], tree[p^1]);
}
num query(int l, int r)
{
    num ans = 0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1) ans = max(ans, tree[l++]);
        if(r&1) ans = max(ans, tree[--r]);
    }
    return ans;
}

int main()
{
    scanf(" %d", &n);
    for(int i=0;i<n;i++)
    {
        scanf(" %d%d", r+i, l+i);
        v[i] = num(r[i]*r[i])*num(l[i]);
        p[i] = i;
    }
    sort(p, p+n, [&](int i, int j){ return mp(v[i], -i) < mp(v[j], -j); });
    for(int ii=0;ii<n;ii++)
    {
        int i = p[ii];
        insert(i, v[i] + query(0, i));
    }
    printf("%.20lf\n", acos(-1.0)*query(0,n));
}
