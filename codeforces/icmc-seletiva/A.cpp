#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
typedef long long ll;

typedef double cood;
typedef complex<cood> point;
cood x(point a) { return real(a); }
cood y(point a) { return imag(a); }
cood inner(point a, point b) { return real(conj(a)*b); }
cood cross(point a, point b) { return imag(conj(a)*b); }
const cood pi = acos(-1.0);

int n;
cood r, R, ans;
int main(){
    cin >> n >> r >> R;
    ans = n*fabs(cross(point(r,0), polar(R,pi/n)));
    printf("%.20lf\n", ans);
}
