#include <bits/stdc++.h>
#define mt make_tuple
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

const int N = 1e4;
const int Z = 'z'-'a'+1;
const int S = 1e6+7;

int n, ans;
int _T[S*Z];
int *T[S], D[S], P[S], ts, tree;
int sol[S];
bool F[S];
tuple<int,int,char> Q[S];
string in[N];
int p[N];

int create(){
    int t=ts++;
    for(char i='a';i<'a'+Z;i++) T[t][i] = 0;
    P[t] = D[t] = F[t] = sol[t] = 0;
    return t;
}

int main(){
    for(int i=0;i<S;i++) T[i] = _T + i*Z - 'a';
    ios::sync_with_stdio(false);
    while(cin >> n && n){
        ans = ts = 0; tree = create();
        for(int i=0;i<n;i++) {
            cin >> in[i];
            p[i] = i;
            int t = tree;
            for(int j=0;j<in[i].size();j++){
                if(!T[t][in[i][j]]) T[t][in[i][j]] = create();
                t = T[t][in[i][j]];
            }
            F[t] = 1;
        }

        int qf = 0, qb = 0;
        Q[qb++] = mt(tree, tree, '$');
        while(qb>qf){
            int i, a, k; char c;
            tie(i,a,c) = Q[qf++];
            for(k=P[a];k && !T[k][c];k=P[k]);
            if(T[k][c] != i) P[i] = T[k][c];
            D[i] = F[P[i]] ? P[i] : D[P[i]];
            for(char j='a';j<'a'+Z;j++) if(T[i][j]) Q[qb++] = mt(T[i][j],i,j);
        }

        sort(p,p+n,[&](int i, int j){ return in[i].size() < in[j].size(); });
        for(int _i=0;_i<n;_i++){
            int i = p[_i], loc = 0;

            int k = tree;
            for(int j=0;j<in[i].size();j++){
                while(k && !T[k][in[i][j]]) k = P[k];
                k = T[k][in[i][j]];
                for(int _k=k;_k;_k=D[_k]) _max(loc, sol[_k]);
            }
            _max(ans, sol[k] = 1 + loc);
        }
        printf("%d\n", ans);
    }
}
