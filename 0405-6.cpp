#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>

const int N = 203, mod = 998244353;
ll dp[N][N][N];
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> inter(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> inter[i][0] >> inter[i][1];
    }
    sort(inter.begin() + 1, inter.end());
    // ×ó¶ËµãÅÅÐò
    for (int i = 1; i <= m; i++)
    {
    }
    // dp i j k ±íÊ¾¿¼ÂÇÍêiÕâ¸öÇø¼ä£¬ j×ó±ßµÄ¸ã¶¨£¬ k×ó±ßµÄ¸ã¶¨1µÄ·½°¸Êý£¨ÓÒ±ß½ç£©¡¢
    dp[0][0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (dp[i][j][k] == 0)
                    continue;
                assert(inter[j][1] <= inter[k][1]);
                int l = inter[i + 1][0], r = inter[i + 1][1];
                dp[i + 1][j][k] += dp[i][j][k], dp[i + 1][j][k] %= mod;

                if (l > inter[j][1] + 1)
                    continue;
                if (r <= inter[j][1])
                {
                    dp[i + 1][j][k] += dp[i][j][k], dp[i + 1][j][k] %= mod;
                }
                else if (r <= inter[k][1])
                {
                    dp[i + 1][i + 1][k] += dp[i][j][k], dp[i + 1][i + 1][k] %= mod;
                }
                else
                {
                    dp[i + 1][k][i + 1] += dp[i][j][k], dp[i + 1][k][i + 1] %= mod;
                }
            }
        }
    }
    //	for(int i = 1; i <= m; i++) {
    //		for(int j = 0; j <= i; j++) {
    //			for(int k = 0; k <= i; k++) {
    //				cout << " i = " << i << " j = " << j << " k = " << k << " dp = " << dp[i][j][k] << '\n';
    //			}
    //		}
    //	}
    ll res = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (inter[i][1] == n)
                res += dp[m][i][j];
            res %= mod;
        }
    }
    cout << res << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    //    pre();
    int t = 1;
    //    cin >> t;
    while (t--)
        solve();
    return 0;
}