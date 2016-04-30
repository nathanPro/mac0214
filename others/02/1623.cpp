#include <bits/stdc++.h>
using namespace std;
const int N = 1.1e6;

int n, m, tc, as;
int last[N], in[N], ans[N];
set<int> aval;

int main()
{
    scanf(" %d", &tc);
    while(tc--)
    {
        as = 0;
        aval.clear();
        scanf(" %d%d", &n, &m);

        for(int i=1;i<n+1;i++) last[i] = -1;
        for(int i=0;i<m;i++)
            scanf(" %d", in+i), ans[i] = 0;

        for(int i=0;as != -1 && i<m;i++)
            if(in[i])
            {
                auto it = aval.upper_bound(last[in[i]]);
                if(it == aval.end())
                    as = -1;
                else
                {
                    ans[*it] = in[i];
                    aval.erase(it);
                }
                last[in[i]] = i;
            }
            else aval.insert(i);
        if(as == -1) printf("NO\n");
        else
        {
            int fst = 1;
            printf("YES\n");
            for(int i=0;i<m;i++)
                if(!in[i])
                {
                    if(fst) fst = 0;
                    else putchar(' ');
                    printf("%d", ans[i]);
                }
            putchar('\n');
        }
    }
}
