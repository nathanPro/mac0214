#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

const int N = 1e4;
int t, n, ans, c;
int A[N], B[N];

int main(){
    scanf(" %d", &t);
    while(t--){
        ans = c = 0;
        scanf(" %d", &n);
        for(int i=0;i<n;i++) scanf(" %d", A+i);
        for(int i=0;i<n;i++) scanf(" %d", B+i);
        for(int i=0;i<n;i++) ans += (A[i]-c >= B[i]), c = A[i];
        printf("%d\n", ans);
    }
}
