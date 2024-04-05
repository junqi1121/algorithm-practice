#include <iostream>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int N = 1e5 + 10, M = 1e5 + 10, MOD = 998244353;
int n, m;
int s[N], e[N];
// 纯暴力枚举……  复杂度也很极限！
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> s[i] >> e[i];
    int ans = 0;
    for (int i = 1; i <= (1 << m); i++)
    {
        int a[N] = {0};
        // cout << i << '$' << endl;
        int num = 1;
        int ii = i;
        while (ii)
        {
            if (ii & 1)
                a[s[num]]++, a[e[num] + 1]--;
            num++;
            ii /= 2;
        }
        int flag = 1;
        for (int j = 1; j <= n; j++)
        {
            a[j] += a[j - 1];
            if (a[j] < 2)
            {
                flag = 0;
                break;
            }
        }
        ans += flag;
        ans %= MOD;
    }
    cout << ans;
}
int main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}