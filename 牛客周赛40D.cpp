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
const int N = 300 + 10, M = 1e5 + 10;
int n, x;
int h[N], ne[N], e[N], idx;
int p[N];
int dx[] = {0, -1, 0, 1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
struct ZB
{
    int s, pri, cost, up, lvm;
} zb[N];

int dp[N];

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
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> zb[i].s >> zb[i].pri >> zb[i].cost >> zb[i].up >> zb[i].lvm;
    }
    // dp[i][j]  // 前i件装备中，花j块钱达到的战力

    for (int i = 1; i <= n; i++)
    {
        for (int j = x; j <= 1; j++)
        {
            for (int k = 0; zb[i].pri + k * zb[i].cost <= j && k <= zb[i].lvm; k++)
            {
                dp[j] = max(dp[j], dp[j - zb[i].pri + k * zb[i].cost] + zb[i].s + k * zb[i].up);
            }
        }
    }
    cout << dp[x];
    return;
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
