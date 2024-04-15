#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 10, M = 1e6 + 10;
int n, m;
string s1, s2;
int nt[N];
inline void solve()
{
    /* write your code here!! */
    cin >> s1 >> s2;
    n = s1.size(), m = s2.size();
    // kmp 通常需要从下标1开始！
    s1 = " " + s1;
    s2 = " " + s2;

    // 生成nt数组部分
    for (int i = 2; i <= m; i++)
    {
        int pre = nt[i - 1];
        while (pre && s2[pre + 1] != s2[i])
            pre = nt[pre];
        nt[i] = pre + (s2[pre + 1] == s2[i]);
    }

    // 匹配部分
    for (int i = 1, j = 0; i <= n; i++)
    {
        // j代表已经匹配成功的数目
        while (j && s1[i] != s2[j + 1])
            j = nt[j];

        if (s1[i] == s2[j + 1])
            j++;

        if (j == m)
        {
            // 完全匹配成功！
            j = nt[j];
            cout << i - m + 1 << endl;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cout << nt[i] << ' ';
    }
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