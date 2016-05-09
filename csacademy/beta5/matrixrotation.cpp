#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 101;

int A[N][N], B[N][N], n;

int main(){
    scanf(" %d", &n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) scanf(" %d", &A[i][j]);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) {
            B[i][j] |= A[i][j];
            B[i][j] |= A[n-1-i][n-1-j];
            B[i][j] |= A[j][n-1-i];
            B[i][j] |= A[n-1-j][i];
        }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            printf("%d%c", B[i][j], " \n"[j+1==n]);
}
