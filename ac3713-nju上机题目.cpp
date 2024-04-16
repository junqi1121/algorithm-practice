// 南京大学考研上机题。
// 注意字符串只包含小写字母
#pragma GCC optimize(2)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e4 + 10, M = 1e4 + 10, MOD = 1000000007;
int n, m;
string s, t;
int dp[M];
inline void solve()
{
    /* write your code here!! */
    cin >> s >> t;
    n = s.size(), m = t.size();
    s = " " + s, t = " " + t;
    // dp[i][j]  从1-i中有多少个子串等于j
    vector<int> ha[26];
    for (int i = 1; i <= m; i++)
    {
        ha[t[i] - 'a'].push_back(i);
    }

    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int x = s[i] - 'a';
        // 我应该反向的遍历set
        // for (auto it = ha[x].end(); it != ha[x].begin(); it--)
        for (auto it = ha[x].rbegin(); it != ha[x].rend(); it++)
        {
            int y = *it;
            dp[y] += dp[y - 1], dp[y] %= MOD;
        }
    }
    cout << dp[m] << endl;
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

// 首先要会dp
//  之后要会滚动数组优化
// 之后要发现全是小写字母，在遍历顺序上面优化
// 一开始使用的set作为哈希优化，还是会超时！！，应该使用vector

// 学会stl的反向遍历，
// 再品味下怎么dp的！！！