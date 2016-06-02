#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

const int S = 101;
char a[S], b[S];

int main(){
    scanf(" %s %s", a, b);
    int cmp = strcmp(a,b);
    if(cmp) printf("1\n");
    else    printf("%s\n", a);
}
