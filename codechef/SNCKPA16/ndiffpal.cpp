#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

const int S = 4e4;
char ans[S], f;
int n, mid, t, s;

int main(){
    scanf(" %d", &t);
    while(t--){
        fill(ans,ans+S,0);
        scanf(" %d", &n);

        if(n < 3){
            if(n == 1) puts("a");
            else if(n == 2) puts("ab");
            continue;
        }

        for(s=0;s+s/2<=n;s++); s--;
        for(int i=0;i<s/2;i++) ans[i] = ans[i+s/2+s%2] = 'a' + i%3;
        if(s&1) ans[s/2] = 'd';
        reverse(ans,ans+s/2);
        n -= s + s/2;
        for(f='e';n;n--) ans[s++] = f++;
        printf("%s\n", ans);
    }
}
