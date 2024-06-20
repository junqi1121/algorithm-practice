#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 10, M = 1e5 + 10;
int n, m, x;
int a[N];
inline void solve()
{
    /* write your code here!! */
    cin >> n >> m >> x;
    // cout << n << ' ' << m << ' ' << x << endl;
    int cnt = 0;
    int flag = 1;
    if (m > n)
        flag = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
        if (a[i] < x)
        {
            flag = 0;
        }
        else
        {
            cnt += (a[i] / x);
        }
    }
    // cout << cnt << ' ' << n << endl;
    if (cnt >= n && flag)
    {
        puts("Yes");
    }
    else
    {
        puts("No");
    }
}
int main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}