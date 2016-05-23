#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

const int S = 7+1e5;
const int M = 2+2e6;
const int Z = '~' - ' ' + 1;

int n;
char in[S], s[2016], K[M];
int _T[M*Z], *T[M], A[M], P[M], Q[M], ts, tree;
bool seen[M];
int F[1001];

int main(){
    for(int i=0;i<M;i++) T[i] = _T + i*Z + ' ';
    tree = ts++;
    scanf(" %s%d", in, &n);
    for(int i=0;i<n;i++){
        scanf(" %s", s);
        int t = tree;
        for(char *c=s;*c;c++){
            if(!T[t][*c]) A[T[t][*c] = ts++] = t, K[T[t][*c]] = *c;
            t = T[t][*c];
        }
        F[i] = t;
    }
    P[tree] = 0; A[tree] = tree; K[tree] = '$';
    int qf = 0, qb = 0;
    Q[qb++] = tree;
    while(qb > qf){
        int i = Q[qf++], k = P[A[i]];
        while(k && !T[k][K[i]]) k = P[k];
        if(T[k][K[i]] != i) P[i] = T[k][K[i]];
        for(char j=' ';j<' '+Z;j++) if(T[i][j]) Q[qb++] = T[i][j];
    }

    int k = tree;
    for(int i=0;in[i];i++){
        while(k > 1 && !T[k][in[i]]) k = P[k];
        k = T[k][in[i]];
        seen[k] |= 1;
    }
    for(int i=0;i<n;i++) printf("%c\n", seen[F[i]]?'Y':'N');
}
