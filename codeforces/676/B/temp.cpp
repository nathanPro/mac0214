#include <bits/stdc++.h>
#define fill AHERK
using namespace std;
typedef int64_t ll;
const double eps = 1e-9;

double fill[10][10];
int n, t, ans;

void pour(int i, int j, double t){
    if(t < eps || i == n || j > i) return;
    double df = min(1.-fill[i][j], t);
    fill[i][j] += df; t -= df;
    pour(i+1,j,.5*t); pour(i+1,j+1,.5*t);
}

int main(){
    scanf(" %d%d", &n, &t);
    while(t--) pour(0,0,1);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans += (fill[i][j] + eps > 1.);
    printf("%d\n", ans);
}
