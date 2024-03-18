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
int ans = INF;
// '.'代表道路，'*'代表蘑菇，'#'代表障碍物 遇见蘑菇转向，遇见障碍物无法通过
void dfs(int x, int y, int x1, int y1, int i, int j, int step)
{
    if (x < 1 || x > n || y < 1 || y > m || step > ans)
        return;
    if (x == x1 && y == y1)
    {
        ans = min(ans, step);
        return;
    }
    int nx = x + i, ny = y + j;
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && map[nx][ny] == '#')
    {
        // 障碍物
        // 直接return
        return;
    }
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && map[nx][ny] == '*')
    {
        for (int k = 0; k < 4; k++)
        {
            // 不能转向
            if (dx[k] == -i && dy[k] == -j)
                continue;
            dfs(nx, ny, x1, y1, dx[k], dy[k], step + 1);
        }
    }
    else
    {
        dfs(nx, ny, x1, y1, i, j, step + 1);
    }
}
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
    for (int i = 0; i < 4; i++)
    {
        dfs(x0, y0, x1, y1, dx[i], dy[i], 0);
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