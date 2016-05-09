#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T> void _max(T& a, T b) { a = max(a,b); }
template<typename T> void _min(T& a, T b) { a = min(a,b); }

int ok[100];
int t, n, in;
int main(){
    scanf(" %d", &n);
    ok[0] = 15;
    for(int i=0;i<n;i++){
        scanf(" %d", &in);
        ok[in] = 15;
    }
    for(int i=1;i<=90;i++)
    {
        ok[i] = max(ok[i-1]-1,ok[i]);
        if(ok[i] == 0){
            printf("%d\n", i);
            return 0;
        }
    }
    printf("90\n");
}
