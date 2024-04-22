#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 10, M = 1e5 + 10, K = 30;
const ull P = 13331, MOD = 1e9 + 7;
int n, m;
int h[N], ne[N * 2], e[2 * N], idx;
ull mp[N];
int f[N][K], dep[N];
ull p[N], h1[N], h2[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void built(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for (int i = 1; i < K; i++)
    {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j != fa)
        {
            built(j, u);
        }
    }
}
void dfs_hash(int x, int fa, int sum)
{
    h1[x] = sum * P + mp[x];
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j != fa)
        {
            dfs_hash(j, x, h1[x]);
        }
    }
}
void dfs_inv(int x, int fa, int sum)
{
    h2[x] = sum + mp[x] * p[dep[x] - 1];
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j != fa)
        {
            dfs_inv(j, x, h2[x]);
        }
    }
}
int lca(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);

    // 跳到同一层
    for (int i = K - 1; i >= 0; i--)
    {
        if (dep[f[x][i]] >= dep[y])
            x = f[x][i];
    }
    if (x == y)
        return x;

    // 跳到lca的下一层
    for (int i = K - 1; i >= 0; i--)
    {
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    }
    return f[x][0];
}
inline void solve()
{
    /* write your code here!! */
    cin >> n;
    memset(h, -1, sizeof h);

    // 预处理一下 P^i
    p[0] = 1;

    for (int i = 1; i < N; i++)
    {
        p[i] = p[i - 1] * P;
    }
    string tem;
    cin >> tem;
    for (int i = 1; i <= n; i++)
    {
        mp[i] = tem[i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        add(x, i);
        add(i, x);
    }
    built(1, 0);

    // 树中字符串的正向哈希
    dfs_hash(1, 0, 0);

    // 树中字符串的反向哈希
    dfs_inv(1, 0, 0);

    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        int pa = lca(u, v);

        int d1 = dep[u] - dep[pa], d2 = dep[v] - dep[pa];
        // 正向哈希值
        ull ha1 = (h2[u] + MOD - h2[f[pa][0]]) * (p[d2] % MOD) + h1[v] + MOD - ((h1[pa] * p[d2]) % MOD);
        ha1 %= MOD;
        // 反向哈希值
        ull ha2 = (h2[v] + MOD - h2[f[pa][0]]) * (p[d1] % MOD) + h1[u] + MOD - ((h1[pa] * p[d1]) % MOD);
        ha2 %= MOD;
        //         cout<<lca<<"=="<<ha1<<"==="<<ha2<<"==="<<d1<<"==="<<d2<<endl;
        if (ha1 == ha2)
            puts("YES");
        else
            puts("NO");
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        solve();
    }
    return 0;
}