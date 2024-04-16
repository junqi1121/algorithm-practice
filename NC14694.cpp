#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 10, M = 2e5 + 10;
int n, m, k;
int a[N], b[M];
// kmp思想的应用！
inline void solve()
{
    /* write your code here!! */
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] %= k;
    for (int i = 1; i <= m; i++)
        cin >> b[i], b[i] %= k;
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