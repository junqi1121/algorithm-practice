#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e6 + 10, M = 2e3 + 10;
int n, m;
int a[N];
int flag[N];

// 二分解法+滑动窗口 此时的滑动窗口类似与单调队列的写法！！
bool check(int x)
{
    memset(flag, 0, sizeof flag);
    int i = 1;
    int count = 0;
    for (i = 1; i <= x; i++)
    {
        if (flag[a[i]] == 0)
            count++;
        flag[a[i]]++;
    }
    for (; i <= n; i++)
    {
        if (count == m)
            return true;
        if (flag[a[i - x]] == 1)
            count--;
        flag[a[i - x]]--;
        if (flag[a[i]] == 0)
            count++;
        flag[a[i]]++;
    }
    return count == m;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 1, r = n + 1;
    while (l < r)
    {
        int mid = r + l >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    int count = 0;
    memset(flag, 0, sizeof flag);
    int i;
    for (i = 1; i <= l; i++)
    {
        if (flag[a[i]] == 0)
            count++;
        flag[a[i]]++;
    }
    for (; i <= n; i++)
    {
        if (count == m)
        {
            cout << i - l << ' ' << i - 1 << endl;
            return 0;
        }
        if (flag[a[i - l]] == 1)
            count--;
        flag[a[i - l]]--;
        if (flag[a[i]] == 0)
            count++;
        flag[a[i]]++;
    }
    if (count == m)
    {
        cout << i - l << ' ' << i - 1 << endl;
    }
    return 0;
}