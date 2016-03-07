#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int node;
typedef int edge;
const int N = 1e3;

int freq[N], in;
int c, n, ans, lst;

int main()
{
    scanf(" %d", &n);
    for(int i=0;i<n;i++)
    {
        scanf(" %d", &in);
        freq[--in]++;
    }
    lst = INT_MAX;
    while(n)
    {
        while(!freq[c]) c = (c+1)%N;
        n--;
        if(c > lst) ans++;
        freq[c]--;
        lst = c++;
    }
    printf("%d\n", ans);
}
