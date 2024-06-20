#include <iostream>
#include <algorithm>
#include <cstring>
#include <bitset>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e3 + 50, M = 1e3 + 50, V = N * M;
ll n, m;
int v[N], w[N];
inline void solve()
{
    /* write your code here!! */
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }
    bitset<N> f[2][N];
    f[0][0][0] = 1;
    for (int i = 1, x = 1; i <= n; i++, x ^= 1)
    {
        for (int j = 0; j < 1024; j++)
        {
            f[x][j] = (f[x ^ 1][j ^ w[i]] << v[i]) | f[x ^ 1][j];
        }
    }
    int ans = -1;
    for (int i = 0; i < 1024; i++)
    {
        if (f[n & 1][i][m])
            ans = i;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}