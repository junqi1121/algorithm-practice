#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e2 + 10, M = 5e3 + 10;
int n, m;
int num[] = {0, 100, 50, 10, 5, 2, 1};
int dp[M];
inline void solve()
{
    /* write your code here!! */

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= 5000; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i - num[j] >= 0)
                dp[i] = min(dp[i], dp[i - num[j]] + 1);
        }
    }
    while (cin >> n)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            ans += dp[x];
        }
        cout << ans;
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