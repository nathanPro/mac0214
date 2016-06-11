#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

const int S = 1+1e5;
const int Z = 'z'-'a'+1;

char s[S];
int  f[Z];
int ans, t, k, n;

int main(){
    scanf(" %d", &t);
    while(t--){
        ans = 0;
        fill(f,f+Z,0);

        scanf(" %s%d", s, &k);
        for(int i=0;s[i];i++) f[s[i]-'a']++;

        int i,j;
        while(42){
            j = max_element(f,f+Z) - f;
            for(i=0;!f[i];i++); for(int l=1+i;l<Z;l++) if(f[l] && f[l] < f[i]) i = l;
            if(f[j]-f[i] <= k) break;
            ans++; f[j]--; f[i]++;
        }
        printf("%d\n", ans);
    }
}
