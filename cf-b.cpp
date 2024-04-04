#include <iostream>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int N = 2e5 + 10;
int n;
int a[N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int tem = n;
    for (int i = n; i >= 1; i--)
    {
        a[i] = tem - a[i];
        tem = min(tem, a[i]);
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
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
}