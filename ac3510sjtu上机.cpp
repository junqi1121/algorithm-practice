// 最长公共子序列，转换成最长上升子序列

// 然后最长上升子序列有 n logn 的解法！

#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 10, M = 1e6 + 10;
int n, m;
int a[N], b[N];
int f[N];

inline void solve()
{
    /* write your code here!! */
    cin >> n;
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i++)
        cin >> a[i], f[a[i]] = i;
    for (int i = 1; i <= n; i++)
        cin >> b[i], b[i] = f[b[i]];

    // 现在也就变成了从b中找单增的序列有几个
    // 想到了转换，但是又不会做上升子序列了QAQ          有O(nlogn)的做法，是二分+贪心的做法！
    f[1] = b[1];
    int len = 1;
    for (int i = 2; i <= n; i++)
    {
        if (b[i] == inf)
            continue;
        // 此处代表做的映射，如果没有出现过，那么就不需要去看这个数了！
        if (b[i] > f[len])
        {
            // cout<<i<<' '<<a[i]<<' '<<f[len]<<' '<<len<<endl;
            f[++len] = b[i];
        }
        else
        {
            int l = 0, r = len;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (f[mid] < b[i])
                    l = mid;
                else
                    r = mid - 1;
            }
            f[l + 1] = b[i];
        }
    }
    cout << len;
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