#include <bits/stdc++.h>
#define mt make_tuple
using namespace std;
typedef int64_t ll;

const int S = 7+1e5;
const int M = 2+2e6;
const int Z = '~' - ' ' + 1;

int n;
char in[S], s[2016], K[M];
int _T[M*Z], *T[M], P[M], D[M], ts, tree;
bool F[M], seen[M];
int f[M];

int main(){
    for(int i=0;i<M;i++) T[i] = _T + i*Z + ' ';
    tree = ts++;
    scanf(" %s%d", in, &n);
    for(int i=0;i<n;i++){
        scanf(" %s", s);
        int t = tree;
        for(char *c=s;*c;c++){
            if(!T[t][*c]) T[t][*c] = ts++;
            t = T[t][*c];
        }
        F[f[i] = t] = 1;
    }

    P[tree] = D[tree] = 0;
    int qf = 0, qb = 0;
    queue<tuple<int,int,char>> Q;
    Q.push(mt(tree,tree,'$'));
    while(qb > qf){
        int i, a, k; char c;
        tie(i,a,c) = Q.front(); Q.pop(); k = P[a];
        while(k && !T[k][c]) k = P[k];
        if(T[k][c] != i) P[i] = T[k][c];
        D[i] = F[P[i]] ? P[i] : D[P[i]];
        for(char j=' ';j<' '+Z;j++) if(T[i][j]) Q.push(mt(T[i][j],i,j));
    }

    int k = tree;
    for(int i=0;in[i];i++){
        while(k > 0 && !T[k][in[i]]) k = P[k];
        k = T[k][in[i]];
        for(int j=k;j;j=D[j]) seen[j] |= 1;
    }
    for(int i=0;i<n;i++) printf("%c\n", seen[f[i]]?'Y':'N');
}
