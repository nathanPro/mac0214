#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double pi = acos(-1.);
double d, h, v, e, t, r;

int main(){
    scanf(" %lf%lf%lf%lf", &d, &h, &v, &e);
    r = .5*d;
    if(pi*r*r*e > v) printf("NO\n");
    else
    {
        t = pi*r*r*h;
        t /= v - pi*r*r*e;
        printf("YES\n%.20lf\n", t);
    }
}
