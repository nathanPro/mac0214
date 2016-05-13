#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T> void _max(T& a, T b) { a = max(a,b); }
template<typename T> void _min(T& a, T b) { a = min(a,b); }

const int S = 4e5;
char s[S];
int ans;

int main(){
    scanf(" %s", 1+s);
    for(int a=1;s[a];){
        char c = s[a];
        int i = 0;
        for(;s[a+i] == c;i++);

        if(i > 1){
            char n = 'a';
            for(;n == s[a-1] || n == c || n == s[a+i];n++);
            for(int j=a+1;j<a+i;j+=2) s[j] = n;
        }

        a += i;
    }
    printf("%s\n", 1+s);
}
