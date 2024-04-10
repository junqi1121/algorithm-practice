#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
long long n, k;
long long a[N];
int main()
{
    cin >> n >> k;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans += a[i];
    }
    ans = ans % k;
    sort(a + 1, a + 1 + n);
    long long ret = 0;
    for (int i = n; i >= 1; i--)
    {

        if (ans && ans >= a[i])
        {
            ret++;
            ans -= a[i];
        }
    }
    cout << ret;
    return 0;
}