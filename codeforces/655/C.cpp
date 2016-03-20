#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5;
int i, k, n, ans;
int in[N], pref[N], suff[N];

int main(){
    scanf(" %d%d", &n, &k);
    for(i=1;i<n+1;i++){
        scanf(" %c", in+i);
        in[i] -= '0';
        in[i] ^= 1;
        pref[i] = suff[i] = in[i];
    }
    for(i=1;  i<=n;i++) pref[i] += pref[i-1];
    for(i=n-1;i>=0;i--) suff[i] += suff[i+1];
    ans = n;
    for(int p=1;p<n;p++)
        if(in[p]){
            int lk = 0, hk = k;
            int rs, ls;
            while(lk < hk){
                int mk = (1+lk+hk)/2;
                if(pref[p] < k-mk) lk = mk;
                else if(suff[p] < mk) hk = mk-1;
                else {
                    int lo, hi, mid;
                    lo = p+1, hi = n;
                    while(lo < hi){
                        mid = (lo+hi)/2;
                        if(pref[mid]-pref[p] >= mk) hi = mid;
                        else lo = mid+1;
                    }
                    rs = lo;
                    lo = 1, hi = p-1;
                    while(lo < hi){
                        mid = (1+lo+hi)/2;
                        if(suff[p-1]-suff[mid-1] >= k-mk) lo = mid;
                        else hi = mid-1;
                    }
                    ls = lo;

                    ans = min(ans, max(abs(ls-p), abs(rs-p)));
                    if(rs-p <= ls-p) lk = mk;
                    else hk = mk-1;
                }
            }
            ans = min(ans,max(abs(ls-p), abs(rs-p)));
        }
    printf("%d\n", ans);
}
