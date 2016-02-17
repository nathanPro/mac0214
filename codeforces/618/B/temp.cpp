#include<bits/stdc++.h>
using namespace std;
typedef long long num;
const int N = 50;

int n;
int in[N][N], out[N], ans[N];

int main()
{
    scanf(" %d", &n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf(" %d", &in[i][j]);

    for(int k=1;k<n+1;k++)
    {
        int p;
        for(p=0;p<n;p++)
        {
            int ok = 1;
            for(int i=0;i<n;i++)
                ok &= (i == p || out[i] || in[i][p] == k);
            for(int j=0;j<n;j++)
                ok &= (j == p || out[j] || in[p][j] == k);
            if(ok)
            {
                out[p] = 1;
                ans[p] = k;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
        printf("%d%c", ans[i], " \n"[i+1==n]);
}
