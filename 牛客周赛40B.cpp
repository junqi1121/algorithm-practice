#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define endl '\n'
#define gkd ios::sync_with_stdio(0), cin.tie(0)
#define int_inf 0x3f3f3f3f
#define fi first
#define se second
#define sz(a) (int)a.size()
#define lowbit(x) x & -x
#define all(x) x.begin(), x.end()
#define gcd(a, b) __gcd(a, b)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int N = 1e3 + 10, M = 1e3 + 10;
int n, m;
int h[N], ne[N], e[N], idx;
int p[N];
int dx[] = {0, -1, 0, 1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
char mp[N][M];
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
void solve()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    int x, y;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == 'W' || mp[i][j] == 'S' || mp[i][j] == 'A' || mp[i][j] == 'D')
                x = i, y = j;
        }
    }
    int ans = 0;
    if (mp[x][y] == 'W')
    {
        for (int i = 1; i <= x; i++)
            if (mp[i][y] == '*')
                ans++;
    }
    if (mp[x][y] == 'S')
    {
        for (int i = x; i <= n; i++)
            if (mp[i][y] == '*')
                ans++;
    }
    if (mp[x][y] == 'A')
    {
        for (int i = 1; i <= y; i++)
            if (mp[x][i] == '*')
                ans++;
    }
    if (mp[x][y] == 'D')
    {
        for (int i = y; i <= m; i++)
            if (mp[x][i] == '*')
                ans++;
    }
    cout << ans;
}
int main()
{
    gkd;
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
