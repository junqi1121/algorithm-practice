#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 10, M = 1e5 + 10;
int n, m;
int a[N];
int b[N];
inline void solve()
{
    /* write your code here!! */
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != b[i])
        {
            cout << n << endl;
            return;
        }
    }
    cout << 0;
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