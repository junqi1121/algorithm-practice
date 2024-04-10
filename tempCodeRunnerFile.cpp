#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 10, M = 2 * N, K = 1e5 + 10;
int n, k;
int a[N];
int tem[K];
int h[N], e[M], ne[M], w[M], idx;
int son[N][32], dep[N], dist[N];

void dfs(int u, int fa)
{
    son[u][0] = fa;
    dep[u] = dep[fa] + 1;
    for (int i = 30; i >= 1; i--)
    {
        son[u][i] = son[son[u][i - 1]][i - 1];
    }
    for (int i = h[u]; i != -1; i = ne[i])
    {
        if (e[i] != fa)
        {
            dist[e[i]] = dist[u] + w[i];
            // cout << e[i] << ' ' << w[i] << ' ' << dist[e[i]] << endl;
            dfs(e[i], u);
        }
    }
}

void add(int a, int b, int ww)
{
    e[idx] = b;
    w[idx] = ww;
    ne[idx] = h[a];
    h[a] = idx++;
}
int get_lca(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);

    // 首先跳到同一层
    for (int i = 30; i >= 0; i--)
    {
        if (dep[son[x][i]] >= dep[y])
            x = son[x][i];
    }
    if (x == y)
        return x;

    // 跳到lca的下一层
    for (int i = 30; i >= 0; i--)
    {
        if (dep[son[x][i]] != dep[son[y][i]])
            x = son[x][i], y = son[y][i];
    }
    return son[x][0];
}
int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> k;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        add(u, v, t);
        add(v, u, t);
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    dfs(1, 0); // 建表

    ll sum = 0;
    // 这里算出原先的总长度
    int pre = a[1];
    for (int i = 2; i <= k; i++)
    {
        int lca = get_lca(pre, a[i]);
        // cout << lca << ' ' << dist[pre] << endl;
        tem[i] = dist[pre] + dist[a[i]] - 2 * dist[lca];
        sum += tem[i];
        pre = a[i];
    }
    //  1-2-3 ....i-i+1....
    for (int i = 1; i <= k; i++)
    {
        if (i == 1)
        {
            cout << sum - tem[2] << ' ';
            continue;
        }
        if (i == k)
        {
            cout << sum - tem[k];
            continue;
        }
        int lca = get_lca(a[i - 1], a[i + 1]);
        cout << sum - tem[i] - tem[i + 1] + dist[a[i - 1]] + dist[a[i + 1]] - 2 * dist[lca] << ' ';
    }

    return 0;
}
