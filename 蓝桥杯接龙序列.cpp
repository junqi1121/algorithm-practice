#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <cmath>
#define gkd ios::sync_with_stdio(0), cin.tie(0)
#define inf 0x3f3f3f3f
#define fi first
#define se second
#define sz(a) (int)a.size()
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 1e5 + 10, M = 1e5 + 10;
int n, m;
vector<PII> a;
int h[N], ne[N], e[N], idx;
unordered_map<int, int> ha;
int dp[N];

struct NODE
{
    int x, y;
} node[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int main()
{
    gkd;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        string y = to_string(x);
        node[i].x = y[0];
        node[i].y = y[sz(y) - 1];
    }
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = ha[node[i].x] + 1;
        if (dp[i] > ha[node[i].y])
            ha[node[i].y] = dp[i];
        ans = max(ans, dp[i]);
    }
    cout << n - ans;

    return 0;
}