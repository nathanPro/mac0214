#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int in[N][N];
int i, j, k, n;
int ans;

void loop(int i, int n, void f(int)){ (i == n) ? 42: (f(i), loop(i+1,n,f), 42); }

void readInt(int j) { scanf(" %d", &in[i][j]); }
void readLine(int i){ ::i = i; loop(0,n,&readInt); }

void relaxJ(int j){ in[i][j] = in[j][i] = min(in[i][j], in[i][k] + in[k][j]); }
void relaxI(int i){ ::i = i; loop(i+1,n,&relaxJ); }
void relaxK(int k){ ::k = k; loop(0,n,&relaxI); }

void maxJ(int j){ ans = max(ans, in[i][j]); }
void maxI(int i){ ::i = i; loop(i+1,n,&maxJ); }

int main(){
    scanf(" %d", &n);
    loop(0,n,&readLine);
    loop(0,n,&relaxK);
    ans = 0;
    loop(0,n,&maxI);
    printf("%d\n", ans);
}
