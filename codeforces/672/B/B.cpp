#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int Z = 'z'-'a'+1;
const int S = 2e5;
char s[S], f[Z];
int n, ans;

int main(){
    scanf(" %d", &n);
    scanf(" %s", s);
    if(n > Z) printf("-1\n");
    else {
        for(int i=0;i<n;i++)
        {
            ans += f[s[i]-'a'];
            f[s[i]-'a'] |= 1;
        }
        printf("%d\n", ans);
    }
}
