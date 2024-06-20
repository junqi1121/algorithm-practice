#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 10, M = 2e5 + 10;
int n, m;
ll cnt = 0;
inline void solve()
{
    /* write your code here!! */
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x < y)
            cnt++;
        if (x > y)
            cnt--;
    }

    if (cnt >= 0)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i - 1 << ' ';
        }
    }
    else
    {
        for (int i = 1; i <= n - 1; i++)
        {
            cout << i + 1 << ' ';
        }
        cout << 0;
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