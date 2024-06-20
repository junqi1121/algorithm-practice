#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5e5 + 10, M = 2 * N, K = 35;
int n, m;
int x, y, z;
int h[N], ne[M], e[M], idx;
int d[N];
int f[N][K];
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
void dfs(int u, int fa)
{
    d[u] = d[fa] + 1;
    f[u][0] = fa;
    for (int i = 1; i < K; i++)
    {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (int i = h[u]; i != -1; i = ne[i])
    {
        if (e[i] != fa)
        {
            dfs(e[i], u);
        }
    }
}
int lca(int x, int y)
{
    if (d[x] < d[y])
        swap(x, y);
    // 跳到同一层
    for (int i = K - 1; i >= 0; i--)
    {
        if (d[f[x][i]] >= d[y])
            x = f[x][i];
    }
    if (x == y)
        return x;
    // 跳到lca下一层
    for (int i = K - 1; i >= 0; i--)
    {
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    }
    return f[x][0];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
        d[u]++;
        d[v]++;
    }
    int root;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 1)
        {
            root = i;
        }
        d[i] = 0;
    }
    dfs(root, 0);
    while (m--)
    {
        cin >> x >> y >> z;
    }
    return 0;
}