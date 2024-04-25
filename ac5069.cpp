#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 10, M = 1e5 + 10;
int n, m;
int a[N], b[N];
int q[N], h = 0, t = -1;
inline void solve()
{
    /* write your code here!! */
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    while (m--)
    {
        h = 0, t = -1;
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        int i = 1, j = 1;
        bool flag = 1;
        while (j < n + 1)
        {
            // 如果队列为空  那么只能插入
            if (t < h)
            {
                if (i == n + 1)
                {
                    flag = 0;
                    break;
                }
                q[++t] = a[i++];
            }
            else
            {
                if (b[j] != q[h] && b[j] != q[t])
                {
                    if (i == n + 1)
                    {
                        flag = 0;
                        break;
                    }
                    q[++t] = a[i++];
                }
                else if (b[j] == q[t])
                {
                    t--;
                    j++;
                }
                else
                {
                    h++;
                    j++;
                }
            }
        }
        if (flag)
            puts("yes");
        else
            puts("no");
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