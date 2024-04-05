#include <iostream>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int N = 1e5 + 10, M = 1e5 + 10;
int n, m;
int a[N];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int b;
        cin >> b;
        ans += a[b];
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