#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first >> v[i].second;
        v[i].first -= i + 1;
        v[i].second = i + 1 - v[i].second;
    }
    sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b)
         {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first; });

    vector<int> maxn(n), minx(n);
    maxn[n - 1] = v[n - 1].second;
    for (int i = n - 2; i >= 0; --i)
        maxn[i] = max(maxn[i + 1], v[i].second);
    minx[0] = v[0].second;
    for (int i = 1; i < n; ++i)
        minx[i] = min(minx[i - 1], v[i].second);

    int ans = 1;
    for (int i = 1; i < n; ++i)
    {
        if (minx[i - 1] > maxn[i])
            ++ans;
    }

    cout << ans;
}