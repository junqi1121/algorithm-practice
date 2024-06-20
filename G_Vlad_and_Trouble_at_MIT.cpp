// https:// codeforces.com/contest/1926/problem/G
// 很好的树形dp训练！
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define inf 100001
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 10, M = 1e5 + 10;
int n, m;
int h[N], ne[2 * N], e[2 * N], idx;
int ans;
string s;
ll dp[N][2];
void add(int x, int y)
{
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx++;
}
void dfs(int u, int fa)
{
    if (s[u] == 'P')
        dp[u][0] = inf;
    if (s[u] == 'S')
        dp[u][1] = inf;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        if (e[i] != fa)
        {
            dfs(e[i], u);
            dp[u][0] += min(dp[e[i]][0], dp[e[i]][1] + 1);
            dp[u][1] += min(dp[e[i]][1], dp[e[i]][0] + 1);
        }
    }
    // cout << dp[u][0] << ' ' << dp[u][1] << endl;
}
inline void solve()
{
    ans = 0;
    idx = 0;
    memset(dp, 0, sizeof dp);
    memset(h, -1, sizeof h);
    memset(ne, 0, sizeof ne);
    memset(e, 0, sizeof e);
    /* write your code here!! */
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        add(a, i);
        add(i, a);
    }
    cin >> s;
    s = " " + s;
    dfs(1, 0);
    // cout << "==========" << endl;
    cout << min(dp[1][0], dp[1][1]) << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}