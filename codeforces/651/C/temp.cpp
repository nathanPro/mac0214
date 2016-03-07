#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef int node;
typedef int edge;

const int N = 2e5;
int n, xin, yin;
map<int, ll> yfreq, xfreq;
map<pair<int,int>, ll> freq;
ll ans;

int main()
{
    scanf(" %d", &n);
    for(int i=0;i<n;i++)
    {
        scanf(" %d%d", &xin, &yin);
        freq[mp(xin, yin)]++;
        xfreq[xin]++;
        yfreq[yin]++;
    }
    for(auto it: xfreq)
    {
        ll k = it.second;
        ans += k*(k-1ll)/2ll;
    }
    for(auto it: yfreq)
    {
        ll k = it.second;
        ans += k*(k-1ll)/2ll;
    }
    for(auto it: freq)
    {
        if(it.second == 1) continue;
        pair<int, int> pt = it.first;
        ll fx = xfreq[pt.first], fy = yfreq[pt.second], k = it.second;
        if(min(fx,fy) > 1ll) ans -= k*(k-1ll)/2ll;
    }
    cout << ans << endl;
}
