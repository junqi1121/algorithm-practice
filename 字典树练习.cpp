#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e5 + 10, M = 1e5 + 10;
int n, m;
long long a;
int son[32 * N][2], idx;
int main()
{
    cin >> n;
    long long ans = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        // 先找最大的值
        long long tem = 0;
        int p = 0;
        for (int j = 31; j >= 0; j--)
        {
            int u = (a >> j) & 1;
            if (son[p][!u])
            {
                tem = tem * 2 + 1;
                p = son[p][!u];
            }
            else
            {
                tem = tem * 2;
                p = son[p][u];
            }
        }
        ans = max(tem, ans);

        // 插入！
        p = 0;
        for (int j = 31; j >= 0; j--)
        {
            int u = (a >> j) & 1;
            if (!son[p][u])
                son[p][u] = ++idx;
            p = son[p][u];
        }
    }
    cout << ans;
    return 0;
}