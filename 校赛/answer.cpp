#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 10, M = 1e5 + 10, MOD = 1e9 + 7;
int n, m;
string s;
ll ans, carry;
int qmi(int x, int y)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
            ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return (int)ans;
}
inline void solve()
{
    /* write your code here!! */
    cin >> s;
    n = s.size();

    for (int i = 0; i < n; i++)
    {
        ans *= 2;
        ans += carry;
        if (s[i] == '1')
        {
            ans += 2;
            carry++;
        }
        else
        {
            ans += 1;
        }
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