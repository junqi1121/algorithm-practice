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
inline void solve()
{
    /* write your code here!! */
    vector<ll> num1, num2;
    for (ll i = 0; i <= 1e6 + 2; i++)
    {
        if (i & 1)
        {
            num1.push_back(i * i);
        }
        else
        {
            num2.push_back(i * i);
        }
    }
    ll x;
    cin >> x;
    if (x & 1)
    {
        // 需要找到第一个大于等于x的
        auto y = upper_bound(num1.begin(), num1.end(), x);
        int l = 0, r = num1.size() - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (num1[mid] <= x)
                l = mid;
            else
            {
                r = mid - 1;
            }
        }
        cout << min((*y - x) / 2, (x - num1[l]) / 2);
    }
    else
    {
        // 需要找到第一个大于等于x的
        auto y = upper_bound(num2.begin(), num2.end(), x);
        int l = 0, r = num1.size() - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (num2[mid] <= x)
                l = mid;
            else
            {
                r = mid - 1;
            }
        }
        cout << min((*y - x) / 2, (x - num2[l]) / 2);
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