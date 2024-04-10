#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
const int N = 2010, P = 2010;
int n, p;
int a[N];

unordered_set<int> all;
vector<int> tem;
int dp[P][P];
int main()
{
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= p;
        if (!all.count(a[i]))
        {
            all.insert(a[i]);
            tem.push_back(a[i]);
        }
    }
    tem.push_back(-1);
    sort(tem.begin(), tem.end());
    // dp[i][j] 表示从前i个数中选，倍数是j最少选几个，初始化均为inf  dp[i-1][j]   1+dp[i-1][j-1]
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i < P; i++)
    {
        dp[i][1] = 1;
    }
    for (int i = 1; i < tem.size(); i++)
    {
        for (int j = 2; j <= p; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j > tem[i])
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - tem[i]] + 1);
            }
        }
    }
    cout << dp[tem.size()][p];

    return 0;
}