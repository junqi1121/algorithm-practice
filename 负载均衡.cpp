// 首先推导拆分的范围,再进行暴力dfs
// 要学习一下dfs的写法
// 学习一下寻找最大值和次大值的写法！   变量索引的定义，然后for循环是从1开始，注意体会

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define sz(a) (int)a.size()
using namespace std;
const int N = 210;
int n;
int mm = -1, dd = 300;
vector<int> now;
int get()
{
    int ma = -1, mi = 0x3f3f3f3f;
    for (auto x : now)
    {
        ma = max(x, ma);
        mi = min(x, mi);
    }
    return ma - mi;
}
void dfs()
{
    if (sz(now) > mm)
        mm = sz(now), dd = get();
    if (sz(now) == mm)
        dd = min(dd, get());

    if (sz(now) == 1)
    {
        int a = now[0];
        for (int i = a / 3 + 1; i <= a / 2; i++)
        {
            now[0] = i;
            now.push_back(a - i);
            dfs();
            now.pop_back();
            now[0] = a;
        }
    }
    else
    {
        int ii = 0, jj = -1;
        for (int i = 1; i < sz(now); i++)
        {
            if (now[i] >= now[ii])
                jj = ii, ii = i;
            else if (jj == -1 || now[i] > now[jj])
                jj = i;
        }
        int a = now[ii], b = now[jj];
        if (a > b)
        {
            for (int i = max(a / 3, b / 2) + 1; i <= a / 2; i++)
            {
                now[ii] = i;
                now.push_back(a - i);
                dfs();
                now.pop_back();
                now[ii] = a;
            }
        }
    }
}
int main()
{
    cin >> n;
    now.push_back(n);
    dfs();
    cout << mm << ' ' << dd;
    return 0;
}