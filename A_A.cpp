#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 10, M = 1e5 + 10, MOD = 1e9 + 7;
ll x, y;
ll mi[N];
ll qmi(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
            ans = ans * x, ans %= MOD;
        y >>= 1;
        x = x * x, x %= MOD;
    }
    return ans;
}

ll inv(ll x)
{
    return qmi(x, MOD - 2);
}

ll c(ll x, ll y)
{
    ll ans = 1;
    for (ll i = y + 1; i <= x; i++)
        ans = 1ll * ans * i % MOD;
    return ans * inv(mi[x - y]) % MOD;
}

inline void solve()
{
    /* write your code here!! */
    cin >> x >> y;
    cout << qmi(x, y) + qmi(y, x) << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    mi[0] = 1;
    for (int i = 1; i < N; i++)
    {
        mi[i] = mi[i - 1] * i, mi[i] %= MOD;
    }
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}