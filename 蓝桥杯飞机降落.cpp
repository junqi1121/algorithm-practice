#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10 + 10;
int n;
int t[N], d[N], l[N];
bool st[N];
bool dfs(int x, int y, int tt)
{
    // 这架飞机序号为x，第y架降落，可以从t后开始降落
    if (y == n)
    {
        return tt <= t[x] + d[x];
    }
    if (tt <= t[x] + d[x])
    {
        // st[x] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (!st[i])
            {
                st[i] = 1;
                int start = max(tt, t[i]);

                if (dfs(i, y + 1, start + l[x]))
                    return true;

                st[i] = 0;
            }
        }
        }
    return false;
}
void solve()
{
    cin >> n;
    memset(st, 0, sizeof st);
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> d[i] >> l[i];
    for (int i = 1; i <= n; i++)
    {
        st[i] = 1;
        if (dfs(i, 1, t[i]))
        {
            puts("YES");
            return;
        }
        st[i] = 0;
    }
    puts("NO");
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}