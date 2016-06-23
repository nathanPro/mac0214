#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

int n, in, bad;
ll ice, d;

int main(){
        scanf(" %d%d", &n, &in);
        ice = ll(in);

        for(int i=0;i<n;i++){
            char op;
            scanf(" %c%d", &op, &in);
            d = ll(in);
            if(op == '+') ice += d;
            else {
                if(d > ice) bad++;
                else ice -= d;
            }
        }

        cout << ice << " " << bad << endl;
}
