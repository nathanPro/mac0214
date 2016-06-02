#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

const int N = 110;

int pos, neg, goal, aux, n;
int ans[N];
char op[N], in;

int range(int l, int x, int r)
{ return (l <= x && x <= r); }

int main(){
    pos = 1;
    op[n++] = '+';

    while(in != '='){
        scanf(" %*c %c", &in);
        op[n] = in;
        pos += (in == '+');
        neg += (in == '-');
        n += (op[n] != '=');
    }
    scanf(" %d", &goal);
    if(!range(pos-neg*goal,goal,pos*goal-neg)) printf("Impossible\n");
    else {
        aux = goal - (pos-neg);
        for(int i=0;i<n;i++) ans[i] = 1;

        while(aux != 0){
            for(int i=0;i<n;i++)
                if(aux > 0 && op[i] == '+' && ans[i] == 1)
                {
                    ans[i] = min(1+aux, goal);
                    aux -= ans[i]-1;
                    break;
                } else 
                if(aux < 0 && op[i] == '-' && ans[i] == 1)
                {
                    ans[i] = min(1-aux, goal);
                    aux += ans[i]-1;
                    break;
                }
        }

        printf("Possible\n");
        for(int i=0;i<n;i++){
            if(i) printf(" %c ", op[i]);
            printf("%d", ans[i]);
        }
        printf(" = %d\n", goal);
    }
}
