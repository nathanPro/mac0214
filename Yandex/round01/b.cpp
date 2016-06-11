#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template<typename T> inline void _max(T& a, T b){ a = max(a,b); }
template<typename T> inline void _min(T& a, T b){ a = min(a,b); }

char grid[3][4];
int16_t curr[3][3];

int di[] = {-1, 0, 1, 0},
    dj[] = { 0,-1, 0, 1};

bool inRange(int l, int x, int r) { return l <= x && x < r; }
bool isVal(int i, int j) { return inRange(0,i,3) && inRange(0,j,3); }

int brute(int i, int j){
    if(grid[i][j] != '?' && grid[i][j] != curr[i][j] + '0'){
        curr[i][j] = -1;
        return 0;
    }

    int ni, nj, nop = 0;
    for(int k=0;k<4;k++)
        if(isVal(ni=i+di[k],nj=j+dj[k]) && curr[ni][nj] == -1){
            curr[ni][nj] = curr[i][j] + 1;
            if(brute(ni,nj)) return 1;
        } else nop++;

    if(nop == 4 && curr[i][j] == 9) return 1;
    curr[i][j] = -1;
    return 0;
}

int main(){
    for(int i=0;i<3;i++) scanf(" %s", &grid[i]);
    memset(curr, -1, sizeof curr);
    curr[1][1] = 1;
    brute(1,1);
    for(int i=0;i<3;i++, putchar('\n'))
        for(int j=0;j<3;j++)
            printf("%d", curr[i][j]);
}
