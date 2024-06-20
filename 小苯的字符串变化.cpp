#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 10, M = 1e5 + 10;
int n, m;
int pre[N], net[N];
int ans = inf;
inline void solve()
{
    /* write your code here!! */
    string a;
    cin >> a;
    n = a.size();
    a = ' ' + a;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1];
        if (a[i] >= 'a' && a[i] <= 'z')
            pre[i]++;
    }
    for (int i = n; i >= 1; i--)
    {
        net[i] = net[i + 1];
        if (a[i] >= 'A' && a[i] <= 'Z')
            net[i]++;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        ans = min(ans, net[i + 1] + pre[i]);
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