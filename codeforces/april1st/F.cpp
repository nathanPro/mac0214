#include <bits/stdc++.h>
using namespace std;
int ans;
char aux;

int main(){
    ans = 1;
    while(!feof(stdin)){
        aux = getchar();
        if(isdigit(aux)){
            if(aux == '1'){
                aux = getchar();
                ans += 10 + (aux-'0');
            }
            else ans += (aux-'0');
        }
    }
    printf("%d\n", ans);
}
