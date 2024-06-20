#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
#define int long long
typedef unsigned long long ull;
const int N = 2e5 + 10, M = 2e5 + 10, NN = 2 * N;
int n, m;
int p[N];
int h[N], e[NN], ne[NN], xx[NN], yy[NN], idx;
bool st[N];
struct POINT
{
    int x, y;
} point[N];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
void add(int a, int b, int x, int y)
{
    e[idx] = b;
    ne[idx] = h[a];
    xx[idx] = x;
    yy[idx] = y;
    h[a] = idx++;
}
void dfs(int u, int fa, int x, int y)
{
    // 通过fa确定u的坐标
    int f_x = point[fa].x, f_y = point[fa].y;
    point[u].x = f_x + x;
    point[u].y = f_y + y;
    st[u] = 1;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        if (e[i] != fa && !st[e[i]])
        {
            dfs(e[i], u, xx[i], yy[i]);
        }
    }
}
inline void solve()
{
    /* write your code here!! */
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i++)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        int pa = find(a), pb = find(b);
        if (a < b)
            p[pb] = pa;
        else
            p[pa] = pb;
        add(a, b, x, y);
        add(b, a, -x, -y);
    }
    for (int i = h[1]; i != -1; i = ne[i])
    {
        int j = e[i];
        dfs(j, 1, xx[i], yy[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        int pi = find(i);
        if (pi != 1)
        {
            cout << "undecidable\n";
        }
        else
        {
            cout << point[i].x << ' ' << point[i].y << endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        solve();
    }
}