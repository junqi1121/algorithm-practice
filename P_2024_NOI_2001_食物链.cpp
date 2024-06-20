#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5e4 + 10;
int n, k;
int p[3 * N];
int cnt;
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
void unset(int x, int y)
{
    int px = find(x), py = find(y);
    p[py] = px;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= 3 * n; i++)
        p[i] = i;
    // 1-n 是自身的域 n+1-2n是他的食物  2n+1-3n是他的天敌
    while (k--)
    {
        int ty, x, y;
        cin >> ty >> x >> y;

        int px = find(x), sx = find(x + n), ex = find(x + n + n);
        int py = find(y), sy = find(y + n), ey = find(y + n + n);
        if (x > n || y > n)
        {
            cnt++;
        }
        else if (ty == 1)
        {
            // 是同类
            if (sx != py && ex != py && sy != px && ey != px)
            {
                // 已经判断这句话可以为真，那么就分别合并自身域、捕食域、天敌域
                unset(x, y);
                unset(x + n, y + n);
                unset(x + n + n, y + n + n);
            }
            else
            {
                cnt++;
            }
        }
        else
        {
            // x吃y
            if (px != py && ex != py && sy != px)
            {
                // 已经判断这句话为真，那么就可以来合并

                unset(y, x + n);         // x的捕食域和y是一个类别
                unset(x, y + n + n);     // x和y的天敌是一个类别
                unset(x + n + n, y + n); // x的天敌 和y的食物
            }
            else
            {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}