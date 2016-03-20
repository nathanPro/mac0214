#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i, n, k; 
ll ans;

int main(){
    scanf(" %d%d", &n, &k);
    while(n > 1 && k > 0){
        ans += 2*n-3;
        n -= 2;
        k--;
    }
    cout << ans << endl;
}
