#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e4 + 10, M = 1e5 + 10;
int n, m;
int p[2 * N];
int ans;
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
void unit(int x, int y)
{
    // 此处的合并，需要将其合并到小于n的标号上面！
    int px = find(x), py = find(y);
    p[py] = px;
}
inline void solve()
{
    /* write your code here!! */
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++)
    {
        p[i] = i;
    }

    while (m--)
    {
        char a;
        int x, y;
        cin >> a >> x >> y;
        if (a == 'E')
        {
            // 敌人
            unit(x, y + n);
            unit(y, x + n);
        }
        else if (a == 'F')
        {
            // 朋友
            unit(x, y);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == i)
            ans++;
    }
    cout << ans << endl;
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