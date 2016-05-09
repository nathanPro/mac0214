#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T> void _max(T& a, T b) { a = max(a,b); }
template<typename T> void _min(T& a, T b) { a = min(a,b); }

const int N = 3e5+7;
const int K = 60; // Uma boa ideia
const double eps = 1e-9;

double S[N][K];
int t[N], n, k;
double T[N], U[N], H[N];

double a[N], b[N];
int lines[N];
int qf, qb, ls;

inline double intercept(int i, int j)
{ return 1.*(b[j]-b[i])/(a[i]-a[j]); }

int main(){
    scanf(" %d%d", &n, &k);
    for(int i=1;i<n+1;i++) scanf(" %d", t+i);
    for(int i=1;i<n+1;i++) T[i] = t[i] + T[i-1];
    for(int i=1;i<n+1;i++) H[i] = 1./double(t[i]) + H[i-1];
    for(int i=1;i<n+1;i++) U[i] = T[i]/double(t[i]) + U[i-1];

    for(int i=1;i<=n;i++) S[i][1] = U[i];
    for(int q=2;q<k+1;q++){
        qb = ls = 0;
        a[ls] = H[1];
        b[ls] = S[q-1][1] - U[1];
        lines[qb++] = ls++;

        S[q][1] = S[q-1][1];
        for(int i=2;i<n+1;i++){
            while(qb > 1 && intercept(lines[qb-2],lines[qf-1]) < T[i] + eps) qb--;
            S[q][i]  = b[lines[qf]] + a[lines[qf]]*T[i];
            S[q][i] += U[i] - T[i]*H[i];

            a[ls] = H[i];
            b[ls] = S[q-1][i] - U[i];
            while(qb > 1 && intercept(lines[qb-1], ls) < intercept(lines[qb-2],lines[qb-1]) + eps) qb--;
            lines[qb++] = ls++;
        }
    }
    printf("%.10lf\n", S[k][n]);
}
