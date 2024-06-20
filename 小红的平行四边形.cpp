#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e3 + 10, M = 1e5 + 10;
int n, m;
bool st[N];
double ans = -1;
struct POINT
{
    ll x, y;
} point[N];
vector<POINT> ret;
void dfs(int i, int num)
{
    if (i > n)
        return;
    if (num == 4)
    {
        // 检测是否是平行四边形
        // 现在在ret中有四组点，需要检测其是否构成四边形

        // 如果是就更新答案
    }

    ret.push_back(point[i]);
    dfs(i + 1, num++);

    ret.pop_back();
    dfs(i + 1, num);
}
inline void solve()
{
    /* write your code here!! */
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> point[i].x >> point[i].y;
    }
    // 选出这些点中最大的平行四边形
    // 1000 选 4
    // 暴力 dfs 组合数
    dfs(1, 0);
    printf("%.1f\n", ans);
}
int main()
{
    int T = 1;
    // cin>>T;
    while (T--)
    {
        solve();
    }
    return 0;
}