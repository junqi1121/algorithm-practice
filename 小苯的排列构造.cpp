#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 10, M = 1e5 + 10;
int n, m;
bool st[N]; // i为合数时，st[i]=1;
inline void solve()
{
    /* write your code here!! */
    cin >> n;
    
}
int main()
{
    for (int i = 2; i < N; i++)
    {
        if (st[i])
            continue;
        for (int j = 2; j * i < N; j++)
        {
            st[j * i] = 1;
        }
    }
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