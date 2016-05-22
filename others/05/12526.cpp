#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef uint64_t ull;

const int N = 1e6 + 2;
const int Z = 'z'-'a'+1;
const int M = N*Z;

int n;
int _T[M], *T[N], sol[N], ts, tree;
bool f[N];
double ans;

int create(int t){
    sol[t] = f[t] = 0;
    for(char i='a';i<'a'+Z;i++) T[t][i] = 0;
    return t;
}
void solve(int t, int s){
    if(!t) return;
    int cnt = 0;
    for(int i='a';i<'a'+Z;i++) cnt += !!T[t][i];
    sol[t] = s + (t == 1 || cnt > 1 || f[t]);
    ans += sol[t]*f[t];
    for(int i='a';i<'a'+Z;i++) solve(T[t][i], sol[t]);
}

char in[100], *s;
int main(){
    for(int i=0;i<N;i++) T[i] = _T + i*Z - 'a';
    while(scanf(" %d", &n) != EOF){
        ans = 0; ts = 1;
        tree = create(ts++);
        for(int i=0;i<n;i++){
            scanf(" %s", in);
            int t = tree;
            for(s=in;*s;s++){
                if(!T[t][*s]) T[t][*s] = create(ts++);
                t = T[t][*s];
            }
            f[t] |= 1;
        }
        solve(tree, 0);
        printf("%.2lf\n", double(ans)/n - 1.);
    }
}
