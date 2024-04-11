#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1000 + 10, M = 10000 + 10;
int n, m;
struct LUN
{
    int u, v, x, y;
} lun[N];
int p[N];
bool st[N];
void solve(int Case)
{
    cout << "Case #" << Case << ":";
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    memset(st, 0, sizeof st);
    for (int i = 1; i <= m; i++)
    {
        cin >> lun[i].u >> lun[i].v >> lun[i].x >> lun[i].y;
    }
}
int main()
{
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve(i);
    }
    return 0;
}