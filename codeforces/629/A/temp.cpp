#include <bits/stdc++.h>
using namespace std;
typedef long long num;

const int N = 101;
int n, k, ans;
char in[N][N];

int main()
{
    scanf(" %d", &n);
    for(int i=0;i<n;i++)
    {
        k = 0;
        for(int j=0;j<n;j++)
        {
            scanf(" %c", &in[i][j]);
            k += (in[i][j] == 'C');
        }
        ans += k*(k-1)/2;
    }
    for(int j=0;j<n;j++)
    {
        k = 0;
        for(int i=0;i<n;i++)
            k += (in[i][j] == 'C');
        ans += k*(k-1)/2;
    }
    printf("%d\n", ans);
}
