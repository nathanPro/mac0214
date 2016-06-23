#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

const int N = 200;
int n, j, A[N];

int main(){
    scanf(" %d", &n);
    for(int i=0;i<n;i++) scanf(" %d", A+i);
    for(int i=1;i<n;i++){
        for(j=i;j>0 && A[j] < A[j-1];j--){
            swap(A[j], A[j-1]);
            printf("%d %d\n", j, 1+j);
        }
        if(A[1] < A[0]) {
            swap(A[1], A[0]);
            printf("%d %d\n", 1, 2);
        }
    }
}
