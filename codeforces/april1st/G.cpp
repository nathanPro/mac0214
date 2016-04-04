#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 20;

int n, m, t;
int y[N], ans;
char aux;
int main(){
    scanf(" %d%d%d", &n, &m, &t);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            while(isspace(aux=getchar()));
            y[j] += (aux == 'Y');
        }
    }
    for(int i=0;i<n;i++) ans += (y[i] >= t);
    printf("%d\n", ans);
}
