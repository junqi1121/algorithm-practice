#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, x, y, a, b; // 有的钱 体积 价格 姐容量 妹容量
bool check(ll cnt, ll v)
{
    if (cnt * x <= v && cnt * y <= n)
        return true;
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> x >> y >> a >> b;
        // 二分求妹妹，left记录答案
        ll left = 0, right = min(n / y, b / x);
        while (left < right)
        {
            ll mid = (right - left + 1) / 2 + left;
            if (check(mid, b))
                left = mid;
            else
                right = mid - 1;
        }
        // 判断能不能买
        if (left == 0)
        {
            cout << "-1" << endl;
            continue;
        }
        // 姐姐
        n -= left * y; // 减去妹妹的钱，剩下的给姐姐买
        ll res = min(n / y, a / x);
        if (res >= left)
            res = left - 1;
        cout << left + res << endl;
    }
    return 0;
}