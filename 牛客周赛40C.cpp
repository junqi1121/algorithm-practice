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
const int N = 1e5 + 10, M = 1e5 + 10;
int n, m;
int h[N], ne[N], e[N], idx;
int p[N];
int dx[] = {0, -1, 0, 1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
int a[N];
int st[N];
int ans1[N];
int ans2[N];
bool st1[N], st2[N];
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
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        st[a[i]]++;
        if (st[a[i]] == 3)
        {
            puts("-1");
            return;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (st[a[i]] == 3)
            ans2[i] = a[i], st2[a[i]]++;
        if (st[a[i]] == 1)
            ans1[i] = a[i], st1[a[i]]++;
        if (st[a[i]] == 2)
            ans1[i] = a[i], st[a[i]]++, st1[a[i]]++;
    }
    int p1 = 1, p2 = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!ans1[i])
        {
            while (!st1[p1])
                p1++;
            ans1[i] = p1;
        }
        if (!ans2[i])
        {
            while (!st2[p2])
                p2++;
            ans1[i] = p2;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans1[i] << ' ';
    puts("");
    for (int i = 1; i <= n; i++)
        cout << ans2[i] << ' ';
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
