#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 5e4 + 10, M = 1e5 + 10;
int n, m;
int a[N], b[N];
unordered_map<int, int> ha1, ha2;
inline void solve()
{
    /* write your code here!! */
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], ha1[a[i]] = i;
    for (int i = 1; i <= n; i++)
        cin >> b[i], ha2[b[i]] = i;
    int i = 1, j = n, left = 1, right = n;
    while (i != j)
    {
        int x = ha2[a[j]]; // 根的位置
        if (x < right)
        {
            // 右树存在
            int len = right - x;
            i = j - len;
            j--;
            left = x + 1;
        }
        else if (x > left)
        {
            // 右树不存在，但是左树存在，所以在左树上搜索
            j--;
            right--;
        }
        else
        {
            // 两个树都不存在，所以就直接输出根节点
            cout << b[x];
            return;
        }
    }
    cout << a[i];
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