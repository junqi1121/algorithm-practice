#include <iostream>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int N = 1e5 + 10, M = 1e5 + 10;
typedef long long ll;
int n, q;
ll a[N], b[N];
struct C
{
    ll time;
    int idx;
    bool operator<(const C &t) const
    {
        return time < t.time;
    }
} c[N];
void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        c[i].time = c[i - 1].time - b[i - 1] + a[i] + b[i];
        c[i].idx = i;
    }
    sort(c + 1, c + 1 + n);
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