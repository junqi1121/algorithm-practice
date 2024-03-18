#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#define INF 0x3f3f3f3f
#define sz(a) (int)a.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e3 + 10, M = 1e3 + 10;
int T;
int n, m;
char map[N][M];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
bool st[N][M];
int ans = INF;
struct node_st
{
    int x, y, dx, dy, step;
};

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> map[i] + 1;
    int x0, y0, x1, y1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (map[i][j] == 'S')
            {
                x0 = i;
                y0 = j;
            }
            if (map[i][j] == 'T')
            {
                x1 = i;
                y1 = j;
            }
        }
    }
    cout << x0 << " " << y0 << " " << x1 << " " << y1 << endl;
    memset(st, 0, sizeof st);
    ans = INF;
    queue<node_st> que;
    st[x0][y0] = true;
    for (int i = 0; i < 4; i++)
        que.push({x0, y0, dx[i], dy[i], 0});
    while (!que.empty())
    {
        auto t = que.front();
        que.pop();
        if (x0 == x1 && y0 == y1)
        {
            ans = min(t.step, ans);
            break;
        }
        if (t.x >= 1 && t.x <= n && t.y >= 1 && t.y <= m && map[t.x][t.y] != '#')
        {
            st[t.x][t.y] = 1;
            // 坐标合法，且不是墙，可以继续往下走
            if (map[t.x][t.y] == '*')
            {
                // 蘑菇
                for (int ii = 0; ii < 4; ii++)
                {
                    if (dx[ii] == -t.dx && dy[ii] == -t.dy) // 掉头的方向！
                        continue;
                    if (!st[t.x + dx[ii]][t.y + dy[ii]])
                        que.push({t.x + dx[ii], t.y + dy[ii], dx[ii], dy[ii], t.step + 1});
                }
            }
            else if (!st[t.x + t.dx][t.y + t.dy])
                que.push({t.x + t.dx, t.y + t.dy, t.dx, t.dy, t.step + 1});
        }
    }

    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
int main()
{
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}