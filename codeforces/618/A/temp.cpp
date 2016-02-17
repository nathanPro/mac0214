#include<bits/stdc++.h>
using namespace std;
typedef long long num;
const int N = 2e5;

int n;
int ans[N], as;

int main()
{
    scanf(" %d", &n);
    for(int i=1;i<n+1;i++)
    {
        int loc = 1;
        while(as > 0 && loc == ans[as-1])
            --as, loc++;
        ans[as++] = loc;
    }
    for(int i=0;i<as;i++)
        printf("%d%c", ans[i], " \n"[i+1==as]);
}
