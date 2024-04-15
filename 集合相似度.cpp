#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;
const int N = 50 + 10, M = 1e4 + 10;
int a[N][M];
int k, n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        a[i][0] = m;
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    cin >> k;
    while (k--)
    {
        int l, r;
        cin >> l >> r;
        unordered_set<int> ll, rr, all;
        for (int i = 1; i <= a[l][0]; i++)
        {
            ll.insert(a[l][i]);
            all.insert(a[l][i]);
        }
        for (int i = 1; i <= a[r][0]; i++)
        {
            rr.insert(a[r][i]);
            all.insert(a[r][i]);
        }
        int nt = 0, nc = 0;
        for (auto x : all)
        {
            nt++;
            if (ll.count(x) != 0 && rr.count(x) != 0)
                nc++;
        }
        double ans = 1.0 * nc / nt * 100;
        printf("%.2f", ans);
        cout << "%" << endl;
    }
}