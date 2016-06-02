#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

const int N = 1+1e5;
char s[N];
int n, k, qf, qb;

int solve(char f){
    qf = qb = 0;
    int j = ::k, ans = 0;
    while(qb < n && (j || s[qb] == f)) j -= (s[qb++] != f);
    ans = qb-qf;
    while(qf < n){
        if(qb < n && s[qf] != f) qb++;
        qf++;
        while(qb < n && s[qb] == f) qb++;
        ans = max(ans,qb-qf);
    }
    return ans;
}

int main(){
    scanf(" %d%d", &n, &k);
    scanf(" %s", s);
    int ans = solve('a');
    ans = max(ans, solve('b'));
    printf("%d\n", ans);
}
