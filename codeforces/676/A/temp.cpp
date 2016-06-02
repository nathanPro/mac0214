#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

const int N = 200;
int a[N], n, lo, hi;

int main(){
    scanf(" %d", &n);
    for(int i=1;i<1+n;i++) {
        scanf(" %d", a+i);
        if(a[i] == 1) lo = i;
        if(a[i] == n) hi = i;
    }
    printf("%d\n", max(max(lo-1,n-lo),max(hi-1,n-hi)));
}
