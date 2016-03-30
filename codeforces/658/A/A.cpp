#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e3;

int n, c;
int p[N], t[N];
int ct, l, r;

int main(){
    scanf(" %d%d", &n, &c);
    for(int i=0;i<n;i++) scanf(" %d", p+i);
    for(int i=0;i<n;i++) scanf(" %d", t+i);

    for(int i=0;i<n;i++){
        ct += t[i];
        l += max(p[i]-c*ct, 0);
    }
    ct = 0;
    for(int i=n-1;i>=0;--i){
        ct += t[i];
        r += max(p[i]-c*ct, 0);
    }
    if(l > r) printf("Limak");
    else if(l < r) printf("Radewoosh");
    else printf("Tie");
    putchar('\n');
}
