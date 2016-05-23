#include <bits/stdc++.h>
#define mt make_tuple
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b) { a = max(a,b); }
template<typename T> inline void _min(T& a, T b) { a = min(a,b); }

const int N = 6e5;
int a[N], bst, ans, n, k;
int qf, qb;

int main(){
    scanf(" %d%d", &n, &k);
    for(int i=0;i<n;i++) scanf(" %d", a+i);

    while(qb < n && k) k -= !a[qb++];
    while(qb < n && a[qb]) qb++;
    ans = qb-qf;
    while(qf < n){
        k += !a[qf++];
        while(qb < n && k) k -= !a[qb++];
        while(qb < n && a[qb]) qb++;
        if(qb-qf > ans){
            bst = qf;
            ans = qb-qf;
        }
    }
    printf("%d\n", ans);
    for(int i=0;i<bst;i++) printf("%d ", a[i]);
    for(int i=bst;i<bst+ans;i++) printf("1%c", " \n"[i+1==n]);
    for(int i=bst+ans;i<n;i++) printf("%d%c", a[i], " \n"[i+1==n]);
}
