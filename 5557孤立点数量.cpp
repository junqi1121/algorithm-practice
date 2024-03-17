// https://www.acwing.com/problem/content/description/5560/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5 + 10, M = 1e5 + 10;

int n, m;
int p[N];
bool st[N];

int find(int x)
{
    // 并查集的路径压缩
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;

    // 并查集的初始化
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        int pa = find(a), pb = find(b);
        if (pa == pb)
        {
            st[pa] = 1;
        }
        else
        {
            p[pa] = pb;
            st[pb] = st[pa] | st[pb];
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int pi = find(i);
        if (pi == i && !st[pi])
        {
            res++;
        }
    }
    cout << res;
    return 0;
}
