#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10, K = 1e3 + 10;
int n, k;
void solve()
{
    cin >> n >> k;
    if (n == k)
    {
        for (int i = 1; i <= n; i++)
            cout << 1 << ' ';
    }
    else if (n != 1 && k == 1)
    {
        for (int i = 1; i <= n; i++)
            cout << i << ' ';
    }
    else
    {
        cout << "-1";
    }
    cout << endl;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}