#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int node;
typedef int edge;

int a, b, ans;
int sol[256][256];

int main()
{
    scanf(" %d%d", &a, &b);
    sol[0][0] = sol[0][1] = sol[1][0] = 0;
    sol[1][1] = 0;
    for(int s=3;s<=a+b+1;s++)
    {
        sol[0][s] = 0;
        sol[s][0] = 0;
        for(int i=1;i<s;i++)
        {
            int j = s-i;
            if(j>1) sol[i][j] = max(sol[i][j], 1 + sol[i+1][j-2]);
            if(i>1) sol[i][j] = max(sol[i][j], 1 + sol[i-2][j+1]);
        }
    }
    printf("%d\n", sol[a][b]);
}
