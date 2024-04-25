#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e2 + 10, M = 1e5 + 10;
int n, m;
struct EDGE
{
    int a, b, c;
    bool operator<(const EDGE &t) const
    {
        return c < t.c;
    }
} edges[N * N];
int p[N];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
inline void solve()
{
    /* write your code here!! */
    // while (scanf("%d%d",&n,&m)!=-1)
    while (cin >> n >> m)
    {
        for (int i = 1; i <= m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            edges[i] = {a, b, c};
        }
        sort(edges + 1, edges + 1 + m);

        for (int i = 1; i <= n; i++)
            p[i] = i;

        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            int a = edges[i].a, b = edges[i].b, c = edges[i].c;
            int pa = find(a), pb = find(b);
            if (pa != pb)
            {
                ans += c;
                p[pa] = pb;
            }
        }

        bool flag = 1;
        for (int i = 2; i <= n; i++)
        {
            if (find(i) != find(1))
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << ans << endl;
        else
            puts("?");
    }
}
int main()
{
    int T = 1;
    // cin>>T;
    while (T--)
    {
        solve();
    }
    return 0;
}