#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
const int N = 50;
const int W = N*1e4+7;

int i, j, w, n, d;
int seen[N*W], c[N];
int ans, sum;

int main(){
    scanf(" %d%d", &n, &d);
    for(i=0;i<n;i++) scanf(" %d", c+i);
    seen[0] = 1;
    for(i=0;i<n;i++)
        for(w=W-c[i]-1;w>=0;--w)
            seen[w+c[i]] |= seen[w];
    while(42){
        for(i=sum+d;i>=sum && !seen[i];i--);
        if(i <= sum) break;
        else ans++, sum = i;
    }
    printf("%d %d\n", sum, ans);
}
