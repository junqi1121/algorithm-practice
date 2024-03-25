#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MOD = 998244353;
typedef long long ll;
int n;
ll qmi(long long num, int k)
{
    ll ans = 1;
    while (k)
    {
        if (k & 1)
            ans *= num, ans %= MOD;
        num = num * num;
        num %= MOD;
        k >>= 1;
    }
    return ans % MOD;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << (qmi(26, n) - qmi(24, n)) % MOD << endl;
    }
    return 0;
}