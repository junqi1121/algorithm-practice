#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e3 + 10, M = 1e3 + 10;
int n, m;
int dp[N][N];
int a[N];
inline void solve()
{
    /* write your code here!! */
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1));

        int ans = n - 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (a[i - j] <= a[i])
                    dp[i][j] = dp[i - j][j] + 1;
                ans = min(ans, n - dp[i][j]);
            }
        }
        cout << ans << endl;
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