#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 6e3;
const int M = 2*5e3 + 2;

int n, m;
int G[N], H[N]; 
int q[N], qf, qb;
int dG[N][N], bG[N][3], szG[N];
int dH[N][N], bH[N][3], szH[N];
int ansv[4], aux[6], as;
int to[M], nx[M], es;

void calculate(int * ad, int d[][N], int b[][3], int sz[N]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) d[i][j] = n<<1;
        d[i][n] = -N;
        d[i][i] = 0;
        qf = qb = 0; q[qb++] = i;
        while(qb - qf > 0){
            int j = q[qf++];
            for(int e=ad[j];e;e=nx[e])
                if(d[i][to[e]] > d[i][j] + 1){
                    d[i][to[e]] = d[i][j] + 1;
                    q[qb++] = to[e];
                }
        }
        int k = 0;
        for(int j=qf-1;j && k<3;--j) b[i][k++] = q[j];
        sz[i] = k;
    }
}

int main(){
    scanf(" %d%d", &n, &m);
    for(int i=0;i<m;i++){
        int j, k;
        scanf(" %d%d", &j, &k); --j; --k;
        dG[j][k] = 1;
    }
    es = 1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(dG[i][j]) {
                to[es] = j; nx[es] = G[i]; G[i] = es++;
                to[es] = i; nx[es] = H[j]; H[j] = es++;
            }
    calculate(G,dG,bG,szG); calculate(H,dH,bH,szH);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) {
            if(dG[i][j] == (n<<1)) dG[i][j] = -N;
            if(dH[i][j] == (n<<1)) dH[i][j] = -N;
        }

    int ans = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i != j) {
                for(int _i=0;_i<szH[i];_i++)
                    for(int _j=0;_j<szG[j];_j++){
                        int k = bH[i][_i], l = bG[j][_j];
                        if(k == l || k == j || i == l) continue;
                        if(dH[i][k]+dG[i][j]+dG[j][l] > ans){
                            ans = dH[i][k] + dG[i][j] + dG[j][l];
                            ansv[0] = k, ansv[1] = i, ansv[2] = j, ansv[3] = l;
                        }
                    }
            }
    for(int i=0;i<4;i++) printf("%d%c", 1+ansv[i], " \n"[i==3]);
}
