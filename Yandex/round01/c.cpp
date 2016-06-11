#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

int pts[] = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20,
      18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
int a[10];
set<int> aval;

int main(){
    for(int i=0;i<10;i++) scanf(" %d", a+i);
    reverse(a,a+10);
    for(int i=0;i<31;i++){
        int cnt = 0; aval.clear();
        for(int j=0;j<31;j++) if(i != j) aval.insert(pts[j]);;
        for(int j=0;j<10;j++){
            auto lb = aval.lower_bound(pts[i]-a[j]);
            if(lb == aval.end()) continue;
            cnt++;
            aval.erase(lb);
        }
        if(cnt >= 10) {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("1000");
}
