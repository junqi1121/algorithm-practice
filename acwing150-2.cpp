#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1000 + 10, M = 1000 + 10;
int n, m;
int map[N][M];
int p[N * M];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i < N * M; i++)
        p[i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            map[i][j] = (c == 'B') ? 1 : 0;
            if (!map[i][j])
                continue;
            if (i - 1 >= 1 && map[i - 1][j])
            {
                int ps = find((i - 1) * m + j - m), pn = find(i * m + j - m);
                p[ps] = pn;
            }
            if (j - 1 >= 1 && map[i][j - 1])
            {
                int ps = find(i * m + j - 1 - m), pn = find(i * m + j - m);
                p[ps] = pn;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (map[i][j])
            {
                int pa = find(i * m + j - m);
                if (pa == i * m + j - m)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans;

    return 0;
}