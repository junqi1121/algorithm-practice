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
vector<int> choose;
void calc(int x)
{
    if (x > n + 1)
        return;
    if (choose.size() > m)
        return;
    if (choose.size() == m && x == n + 1)
    {
        for (auto x : choose)
            cout << x << ' ';
        cout << endl;
        return;
    }

    // 选x
    choose.push_back(x);
    calc(x + 1);
    choose.pop_back();

    // 不选x
    calc(x + 1);
}
inline void solve()
{
    /* write your code here!! */
    cin >> n >> m;
    calc(1);
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