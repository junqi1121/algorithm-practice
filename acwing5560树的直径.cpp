#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int Q = 5e5 + 10;
int q, v;
int n = 4;
int p[Q], d[Q];
int ma[5] = {1, 1, 1, 1, 1};

void solve()
{
    vector<int> a;
    for (int i = 2; i <= 4; i++)
    {
        a.push_back(ma[i]);
    }
    sort(a.begin(), a.end());
    cout << a[2] + a[1] << endl;
}
int find(int x)
{
    if (p[x] != x)
    {
        int u = find(p[x]);
        //        d[x] += d[p[x]];
        p[x] = u;
    }
    return p[x];
}
int main()
{
    cin >> q;
    for (int i = 1; i <= Q - 1; i++)
    {
        p[i] = i;
        d[i] = 0;
    }
    d[2] = 1;
    d[3] = 1;
    d[4] = 1;

    while (q--)
    {
        cin >> v;
        p[++n] = find(v);
        d[n] = d[v] + 1;
        p[++n] = find(v);
        d[n] = d[v] + 1;
        cout << d[n] << "***" << p[n] << ' ' << n << endl;
        ma[find(p[v])] = max(ma[find(p[v])], d[n]);
        solve();
    }
    return 0;
}
