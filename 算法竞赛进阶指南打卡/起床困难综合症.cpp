// 一开始wa了半天，是因为位数枚举小了，应该枚举到30，我只枚举到20 QAQ
// 另一个原因，位运算一般情况下没有交换律，就需要按顺序计算
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 10, M = 1e9 + 10;
int n, m;
int t[N], ty[N];
inline void solve()
{
    /* write your code here!! */
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string a;
        cin >> a >> t[i];
        if (a == "AND")
            ty[i] = 1;
        if (a == "OR")
            ty[i] = 2;
        if (a == "XOR")
            ty[i] = 3;
    }
    int ans = 0, init = 0;
    for (int i = 30; i >= 0; i--)
    {
        int one = 1;
        int zero = 0;
        for (int j = 1; j <= n; j++)
        {
            int bb = (t[j] >> i & 1);
            if (ty[j] == 1)
            {
                one &= bb;
                zero &= bb;
            }
            if (ty[j] == 2)
            {
                one |= bb;
                zero |= bb;
            }
            if (ty[j] == 3)
            {
                one ^= bb;
                zero ^= bb;
            }
        }
        if (one > zero && init + (1 << i) <= m)
        {
            init += (1 << i);
            ans = ans + (one << i);
        }
        else
        {
            ans = ans + (zero << i);
        }
    }
    cout << ans;
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