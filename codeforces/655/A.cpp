#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i, j, k, n, id, t;

char grid[2][2][2];
char w[2][20];

int main(){
    for(k=0;k<2;k++)
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                scanf(" %c", &grid[k][i][j]);
    for(k=0;k<2;k++){
        i = 0;
        if(grid[k][0][0] != 'X') w[k][i++] = grid[k][0][0];
        if(grid[k][0][1] != 'X') w[k][i++] = grid[k][0][1];
        if(grid[k][1][1] != 'X') w[k][i++] = grid[k][1][1];
        if(grid[k][1][0] != 'X') w[k][i++] = grid[k][1][0];
    }
    for(k=0;k<2;k++)
        for(i=0;i<3;i++) w[k][i+3] = w[k][i];
    for(i=0;w[0][i] != 'A';i++);
    for(j=0;w[1][j] != 'A';j++);
    int ok = 1;
    for(k=0;k<3;k++) ok &= (w[0][i+k] == w[1][j+k]);
    if(ok) printf("YES\n");
    else   printf("NO\n");
}
