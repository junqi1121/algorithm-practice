#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 10, M = 1e5 + 10;
ll n, m;
unordered_map<int, ll> cnt;
inline void solve()
{
    /* write your code here!! */
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        cnt[a] += i;
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        cout << cnt[x] * cnt[y] << endl;
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