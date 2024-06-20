#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 10, M = 1e5 + 10;
int n, m;
ll a[N];
ll sum = 0;
ll ans = -1;
ll sum1 = 0;
inline void solve()
{
    /* write your code here!! */
    cin >> n;
    ll mi = inf;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ll right = sum - sum1 - a[i];
        ans = max(ans, abs(right - a[i]));
        ans = max(ans, abs(sum1 - a[i]));
        sum1 += a[i];
    }
    cout << ans;
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