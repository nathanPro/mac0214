#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;

const int N = 150007;

int n, k, q;
int t[N];
int cmd;
set<pair<int,int> > online;

int main(){
    scanf(" %d%d%d", &n, &k, &q);
    for(int i=0;i<n;i++) scanf(" %d", t+i);
    while(q--){
        scanf(" %d", &cmd);
        if(cmd == 1){
            int aux;
            scanf(" %d", &aux); --aux;
            online.insert(mp(-t[aux], aux));
        }else {
            int aux;
            int ok = 0;
            int i = 0;
            scanf(" %d", &aux); --aux;
            for(auto it : online){
                if(i == k) break;
                ok |= (it.second == aux);
                i++;
            }
            if(ok) printf("YES\n");
            else printf("NO\n");
        }
    }
}
