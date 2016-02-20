#include <bits/stdc++.h>
using namespace std;
typedef long long num;
const int N = 367;

int n;
char aux;
int a, b;
int m[N], f[N], bst;

int main()
{
    scanf(" %d", &n);
    for(int i=0;i<n;i++)
    {
        scanf(" %c%d%d", &aux, &a, &b);
        b++;
        if(aux == 'M')
        {
            for(int j=a;j<b;j++) m[j]++;
        }
        else
        {
            for(int j=a;j<b;j++) f[j]++;
        }
    }

    bst = 0;
    for(int i=0;i<N;i++)
        bst = max(bst, 2*min(m[i], f[i]));
    printf("%d\n", bst);
}
