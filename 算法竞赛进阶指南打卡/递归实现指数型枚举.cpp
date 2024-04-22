// 拿一个全局变量来记录结果
// 也需要学习一下vector的删除操作
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 10, M = 1e5 + 10;
int n, m;
vector<int> choose;
void calc(int x)
{
    if (x == n + 1)
    {
        for (auto x : choose)
        {
            cout << x << ' ';
        }
        cout << endl;
    }
    // 如果不选x
    calc(x + 1);

    // 如果选x
    choose.push_back(x);
    calc(x + 1);
    choose.pop_back(); // 回溯，保留现场！
}
inline void solve()
{
    /* write your code here!! */
    cin >> n;
    // 二进制枚举，但是递归怎么枚举呢？
    // for (int i = 0; i < (1 << n); i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (i >> j & 1)
    //             cout << j + 1 << ' ';
    //     }
    //     cout << endl;
    // }
    calc(1);
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