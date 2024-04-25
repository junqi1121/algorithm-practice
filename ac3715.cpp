#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e3 + 10, M = 1e3 + 10;
int n, m;
int a[N], b[N];
int ans[N];
int ret = 0;
void merge_sort(int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = l + r >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int i = l, j = mid + 1, idx = l;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            b[idx++] = a[i];
        else
        {
            int len = mid - i + 1;
            ret += len;
            ans[a[j]] += len;
            b[idx++] = a[j];
        }
    }
    while (i <= mid)
    {
        b[idx++] = a[i];
    }
    while (j <= r)
    {
        b[idx++] = a[i];
    }
    for (int i = l; i <= r; i++)
    {
        a[i] = b[i];
    }
}
inline void solve()
{
    /* write your code here!! */
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    merge_sort(1, n);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl
         << ret << endl;
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