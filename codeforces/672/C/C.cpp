#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double cood;

const int N = 2e5;

int n;
int xin, yin, p[N];
double x[N], y[N], T, tot, ans;

inline cood dist(int i, int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}

int main(){
    for(int i=0;i<3;i++) {
        scanf(" %d%d", &xin, &yin);
        x[i] = xin, y[i] = yin;
    }
    scanf(" %d", &n);
    for(int i=3;i<n+3;i++) {
        scanf(" %d%d", &xin, &yin);
        x[i] = xin, y[i] = yin;
        p[i-3] = i;
    }

    if(n == 1){
        printf("%.10lf\n", min(dist(0,3),dist(1,3)) + dist(3,2));
        return 0;
    }

    for(int i=0;i<n;i++) tot += 2*dist(2,p[i]);
    T = tot;

    sort(p,p+n, [&](int i, int j){
        return dist(2,i) - dist(1,i) < dist(2,j) - dist(1,j);
    });
    tot -= dist(2,p[n-1]) - dist(1,p[n-1]);
    n--;
    sort(p,p+n, [&](int i, int j){
        return dist(2,i) - dist(0,i) < dist(2,j) - dist(0,j);
    });
    tot -= max(dist(2,p[n-1]) - dist(0,p[n-1]),0.);
    ans = tot;

    n++;
    tot = T;

    sort(p,p+n, [&](int i, int j){
        return dist(2,i) - dist(0,i) < dist(2,j) - dist(0,j);
    });
    tot -= dist(2,p[n-1]) - dist(0,p[n-1]);
    n--;
    sort(p,p+n, [&](int i, int j){
        return dist(2,i) - dist(1,i) < dist(2,j) - dist(1,j);
    });
    tot -= max(dist(2,p[n-1]) - dist(1,p[n-1]),0.);
    ans = min(ans,tot);

    printf("%.10lf\n", ans);
}
