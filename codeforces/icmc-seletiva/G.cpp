#include <bits/stdc++.h>
#define negate Negate
using namespace std;
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
typedef long long ll;

const int N = 1000;

int n, as;
char in[N], ans[N];

int lc[N], rc[N], es;
char tp[N];

inline int inRange(int l, int x, int u)
{ return l <= x && x <= u; }
inline int nExp(char t, int l, int r, int p)
{ tp[p] = t; lc[p] = l; rc[p] = r; return p; }

char op[N];
int st[N], ss, os;

char neg(char x) {
    if(x == '[') return '(';
    if(x == '(') return '[';
    if(x == '*') return '+';
    if(x == '+') return '*';
    if(x < 'a') return x + 'a'-'A';
    return x - 'a'+'A';
}
void negate(int e) {
    if(!e) return;
    if(tp[e] == '+' || tp[e] == '*'){
        tp[e] = neg(tp[e]);
        negate(lc[e]); negate(rc[e]);
    } else tp[e] = neg(tp[e]);
}
void solve(int e){
    if(!e) return;
    if(tp[e] == '[') {
        tp[e] = '(';
        negate(lc[e]);
    }
    solve(lc[e]); solve(rc[e]);
}
void print(int e) {
    if(!e) return;
    if(tp[e] == '(') {
        ans[as++] = '(';
        print(lc[e]);
        ans[as++] = ')';
    } else {
        print(lc[e]);
        ans[as++] = tp[e];
        print(rc[e]);
    }
}
void relax(char x){
    while(op[os-1] != x) {
        int rhs = st[--ss], lhs = st[--ss];
        st[ss++] = nExp(op[--os], lhs, rhs, es++);
    }
    os--;
    int lhs = st[--ss];
    st[ss++] = nExp(x,lhs,0,es++);
}

int main(){
    es = 1;
    scanf(" %s", 1+in);
    in[0] = '(';
    n = 1 + strlen(1+in);
    in[n++] = ')';

    for(int i=0;i<n;i++) {
        if(in[i] == ')') relax('(');
        else if(in[i] == ']') relax('[');
        else if(inRange('A',in[i],'Z') || inRange('a',in[i],'z'))
            st[ss++] = nExp(in[i], 0, 0, es++);
        else op[os++] = in[i];
    }
    solve(st[0]);
    as = 0; print(st[0]); ans[as-1] = 0;
    printf("%s\n", 1+ans);
}
