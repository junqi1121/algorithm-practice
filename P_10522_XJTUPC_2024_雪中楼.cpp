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
struct Point
{
    int x, y, z;
    bool operator<(const Point &t) const
    {
        return x < t.x;
    }
} point[N];
inline void solve()
{
    /* write your code here!! */
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // 通过关系生成高度
    int tem = N;
    for (int i = 0; i <= n; i++)
    {
        if (a[i] == 0)
        {
            point[i].x = tem - 1;
        }
        else
        {
            point[a[i]].z++;
            point[i].x = point[a[i]].x + point[a[i]].z;
        }
        point[i].z = 0;
        tem = min(tem, point[i].x);
        point[i].y = i;
    }

    sort(point + 1, point + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        cout << point[i].y << ' ';
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