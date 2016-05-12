#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int as, n;
char ans[2000];

int main(){
    scanf(" %d", &n);
    for(int i=1;as<=n;i++){
        int j = i, k = 0, cnt = 0;
        for(;j;j/=10,cnt++) k = k*10 + j%10;
        for(;cnt;k/=10,cnt--) ans[as++] = '0' + k%10;
    }
    printf("%c\n", ans[n-1]);
}
