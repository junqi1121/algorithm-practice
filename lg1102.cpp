// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <unordered_map>
// using namespace std;
// const int N = 2e5 + 10;
// typedef long long ll;
// ll n, c;
// ll a[N];
// unordered_map<ll, ll> ha;
// int main()
// {
//     cin >> n >> c;
//     ll ans = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//     }
//     sort(a + 1, a + 1 + n);
//     for (int i = 1; i <= n; i++)
//     {
//         ans += ha[a[i] - c];
//         ha[a[i]]++;
//     }
//     cout << ans;
//     return 0;
// }

//  粗暴却有效的哈希做法，但是记得要用long long！！  不开long long 见祖宗QAQ ！！

// 但是这个双指针算法真的好酷  题解链接！！！https://www.luogu.com.cn/article/8lshu0t9
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
ll n, c;
ll a[N];

int main()
{
    cin >> n >> c;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int i = 1, j = n;
    while (i < j)
    {
        if (a[j] - a[i] < c)
        {
            break;
        }
        if (a[j] - a[i] == c)
        {
            ans++;
            i++;
        }
    }
    cout << ans;
    return 0;
}