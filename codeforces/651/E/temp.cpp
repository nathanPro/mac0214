#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef int node;
typedef int edge;

const int N = 2e6;
const int T = N<<1;
int sz, n, m, i, j, x, y, lst, lv;
int p[N];
int ** in;
ll col[T], lin[T];

int query(ll * tree, int l, int r)
{
    ll ans = 0;
    for(l+=sz,r+=sz;l<r;l>>=1, r>>=1)
    {
        if(l&1) ans = max(ans, tree[l++]);
        if(r&1) ans = max(ans, tree[--r]);
    }
    return ans;
}

void update(ll * tree, int p, int val)
{
    for(tree[p+=sz]=val;p>0;p>>=1)
        tree[p>>1] = max(tree[p], tree[p^1]);
}

int main()
{
    scanf(" %d%d", &n, &m);
    sz = n*m;
    in = new int * [n];
    for(i=0;i<n;i++) in[i] = new int [m];

    for(i=0;i<n*m;i++)
        scanf(" %d", &in[i/m][i%m]), p[i] = i;
    sort(p, p+sz, [&](int i, int j){ return mp(in[i/m][i%m],i) < mp(in[j/m][j%m],j); });

    lst = -1;
    lv = -1;
    for(int ii=0;ii<sz;ii++)
    {
        int loc = 0;
        i = p[ii];

        x = i%m, y = i/m;
        loc = max(query(col, x*n, (x+1)*n), query(lin, y*m , (y+1)*m));
        if(loc == 0 || lst != in[i/m][i%m]) loc++;
        update(col, x*n + y, loc);
        update(lin, y*m + x, loc);

        lst = in[i/m][i%m];
        in[i/m][i%m] = lv = loc;
    }

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            printf("%d%c", in[i][j], " \n"[j+1==m]);


    for(i=0;i<n;i++) delete[] in[i];
    delete[] in;
}
