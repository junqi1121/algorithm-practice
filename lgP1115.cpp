#include <iostream>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N = 2e5 + 10;
int n;
long long a[N];
long long dp[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = a[i];
    }
    long long ans = -inf;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(a[i], dp[i - 1] + a[i]);
        ans = max(dp[i], ans);
    }
    cout << ans;
    return 0;
}