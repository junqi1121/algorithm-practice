#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10, K = 1e6 + 10;
int n, k;
ll a[N];
int q[N], hh, tt = -1;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // 第一行输出最小值，第二行输出最大值
    for (int i = 1; i <= n; i++)
    {
        // 首先判断队头是否划出窗口
        while (hh <= tt && q[hh] < i - k + 1)
            hh++;

        // 判断单调队列最后插入的几个数字是否符合！
        while (hh <= tt && a[q[tt]] >= a[i])
            tt--;

        q[++tt] = i;
        if (i >= k)
            cout << a[q[hh]] << ' ';
    }

    cout << endl;
    hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
    {
        // 首先判断队头是否划出窗口
        while (hh <= tt && q[hh] < i - k + 1)
            hh++;

        // 判断单调队列最后插入的几个数字是否符合！ 队尾进行判断！
        while (hh <= tt && a[q[tt]] <= a[i])
            tt--;

        q[++tt] = i;
        if (i >= k)
            cout << a[q[hh]] << ' ';
    }

    return 0;
}