// 训练一下倍增求lca的模板
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5e5 + 10, M = 5e5 + 10;
int n, m, s;
// 无向图，边要开节点的两倍！！
int h[N], ne[2 * N], e[2 * N], idx;
int dep[N];    // dep[i]存的是节点i的深度
int fa[N][20]; // fa[u][i]  存的是u点 向上跳2^i层的祖先节点

// 那么就有递推公式  fa[u][i] = fa[fa[u][i-1]][i-1]
// 此公式是采用的倍增的思想
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
void dfs(int u, int father)
{
    dep[u] = dep[father] + 1;
    fa[u][0] = father;

    for (int i = 1; i <= 19; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j != father)
        {
            dfs(j, u);
        }
    }
}
int lca(int x, int y)
{
    // 保证x的层数不小于y的层数
    if (dep[x] < dep[y])
        swap(x, y);

    // 首先跳到同一层
    for (int i = 19; i >= 0; i--)
        if (dep[fa[x][i]] >= dep[y])
            x = fa[x][i];

    if (x == y)
        return y;

    // 再跳到lca的下一层
    for (int i = 19; i >= 0; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];

    return fa[x][0];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(h, -1, sizeof h);
    cin >> n >> m >> s;
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(s, 0);
    // while (m--)
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }
}
