#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 5e5 + 20, M = 1e5 + 10;
int h[N], ne[N], e[N], idx;
int dep[N];
int fa[N][30];
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
int lca(int x, int y)
{
    // 默写模板的时候，注意小于号和大于等于号！！！   刚才就默写错了！

    // 首先换位
    if (dep[x] < dep[y])
        swap(x, y);

    // 接着跳到同一层
    for (int i = 29; i >= 0; i--)
    {
        if (dep[fa[x][i]] >= dep[y])
            x = fa[x][i];
    }
    if (x == y)
        return x;

    // 接着跳到lca的下一层
    for (int i = 29; i >= 0; i--)
    {
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    }
    return fa[x][0];
}
int main()
{
    int q;
    cin >> q;
    int num = 4;
    dep[1] = 1;
    dep[2] = dep[3] = dep[4] = 2;
    fa[2][0] = fa[3][0] = fa[4][0] = 1;
    add(1, 2);
    add(1, 3);
    add(1, 4);
    int x = 2, y = 3, len = 2;
    while (q--)
    {
        int a;
        cin >> a;
        add(a, ++num);

        dep[num] = dep[a] + 1;
        fa[num][0] = a;
        for (int i = 1; i < 30; i++)
        {
            fa[num][i] = fa[fa[num][i - 1]][i - 1];
        }
        add(a, ++num);

        dep[num] = dep[a] + 1;
        fa[num][0] = a;
        for (int i = 1; i < 30; i++)
        {
            fa[num][i] = fa[fa[num][i - 1]][i - 1];
        }

        int px = lca(num, x), py = lca(num, y);
        cout << "PX  PY " << px << ' ' << py << endl;
        int dx = dep[x] + dep[num] - 2 * dep[px], dy = dep[y] + dep[num] - 2 * dep[py];
        cout << "DX DY " << dx << ' ' << dy << endl;
        if (dx >= dy && dx > len)
        {
            len = dx;
            y = num;
        }
        else if (dy >= dx && dy > len)
        {
            len = dy;
            x = num;
        }
        cout << len << endl;
    }
    return 0;
}