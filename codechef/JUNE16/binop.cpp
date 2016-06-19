#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

const int S = 1e6;
char A[1+S], B[1+S];
bool s[2];
int n, ans, t, m[2];

int main(){
    scanf(" %d", &t);
    while(t--){
        s[0] = s[1] = m[0] = m[1] = 0;
        scanf(" %s %s", A, B);
        for(int i=0;A[i];i++){
            s[0] |= (A[i] == '0');
            s[1] |= (A[i] == '1');
            m[A[i]-'0'] += (A[i] != B[i]);
            if(!A[i+1]) n = i+1;
        }
        if(!(s[0] && s[1])) printf("Unlucky Chef\n");
        else {
            puts("Lucky Chef");
            printf("%d\n", m[0] + m[1] - min(m[0],m[1]));
        }
    }
}
