#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 10, M = 1e5 + 10;
int n, k;
int a[N];
inline void solve()
{
    /* write your code here!! */
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // 就是个滑动窗口
    unordered_map<int, int> ha;
    int cnt = 0;
    for (int i = 1; i <= k; i++)
    {
        if (a[i] < 1 || a[i] > k)
            continue;
        if (ha.count(a[i]) == 0)
            cnt++;
        ha[a[i]]++;
    }
    int ans = cnt == k;
    for (int i = k + 1; i <= n; i++)
    {
        if (a[i - k] >= 1 && a[i - k] <= k)
        {
            ha[a[i - k]]--;
            if (ha[a[i - k]] == 0)
                cnt--;
        }
        if (a[i] >= 1 && a[i] <= k)
        {
            if (ha[a[i]] == 0)
                cnt++;
            ha[a[i]]++;
        }
        ans += cnt == k;
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