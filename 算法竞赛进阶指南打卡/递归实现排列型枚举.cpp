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
bool st[N];
vector<int> ans;
void pai(int i, int zz)
{
    ans.push_back(i);
    if (zz == n)
    {
        for (auto x : ans)
            cout << x << ' ';
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            st[i] = 1;
            pai(i, zz + 1);
            st[i] = 0;
            ans.pop_back();
        }
    }
}
inline void solve()
{
    /* write your code here!! */
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        st[i] = 1;
        pai(i, 1);
        st[i] = 0;
        ans.pop_back();
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