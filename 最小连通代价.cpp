#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 10, M = 1e5 + 10;
int n, a, b;
inline void solve()
{
    /* write your code here!! */
    int m1 = 0, m2 = 0;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x & 1)
            m1++;
        else
            m2++;
    }
    if (m1 < m2)
        swap(m1, m2);
    if (a < b)
    {
        if (m1 > 0 && m2 > 0)
        {
            cout << (n - 2) * a + b << endl;
        }
        else
        {
            cout << (n - 1) * a << endl;
        }
    }
    else
    {
        if (m1 > 0 && m2 > 0)
            cout << (n - 1) * b << endl;
        else
            cout << (n - 1) * a << endl;
    }
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