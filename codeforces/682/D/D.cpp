#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

const int N = 1003;
const int K = 13;

int n, m, k;
int S[N][N][K][2];
char seen[N][N][K][2], A[N], B[N];

int solve(int i, int j, int k, int f){
    if(seen[i][j][k][f]) return S[i][j][k][f];
    seen[i][j][k][f] = 1;

    if(i == n || j == m || k == 0) return (S[i][j][k][f] = 0);

    if(f){
        if(A[i] == B[j]) S[i][j][k][f] = 1 + solve(1+i,1+j,k,1);
        else S[i][j][k][f] = solve(i,j,k-1,0);
    } else {
        S[i][j][k][f] = max(solve(1+i,j,k,0),solve(i,1+j,k,0));
        if(A[i] == B[j]) _max(S[i][j][k][f], 1 + solve(1+i,1+j,k,1));
    }

    return S[i][j][k][f];
}

int main(){
    scanf(" %d%d%d", &n, &m, &k);
    scanf(" %s %s", A, B);
    printf("%d\n", solve(0,0,k,0));
}
