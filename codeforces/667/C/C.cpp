#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int A = 30;
const int S = 2e4;
int n;
char s[S], b[S], t[S], p[S];
set<string> found;

int main(){
    scanf(" %s", s);
    n = strlen(s);

    b[n-2] = t[n-3] = 1;
    p[n-2] = p[n-3] = p[n] = 1;
    for(int i=n-4;i+1;--i){
        b[i] = t[i+2];
        if(s[i] != s[i+2] || s[i+1] != s[i+3]) b[i] |= b[i+2];

        t[i] = b[i+3];
        if(s[i] != s[i+3] || s[i+1] != s[i+4] || s[i+2] != s[i+5]) t[i] |= t[i+3];

        p[i] = b[i] || t[i];
    }

    for(int i=5;i<n;i++){
        if(b[i] && p[i+2]) found.insert(string(s+i,s+i+2));
        if(t[i] && p[i+3]) found.insert(string(s+i,s+i+3));
    }
    printf("%d\n", found.size());
    for(string ans : found) cout << ans << endl;
}
