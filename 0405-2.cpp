#include <iostream>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int N = 1e5 + 10, M = 1e5 + 10;
int n, m;
int a[N];
void solve()
{
    int x, y;
    cin >> x >> y;
    if (x > y)
        swap(x, y);
    if ((x - y) % 3 == 0)
        puts("Yes");
    else
        puts("No");
}
int main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}