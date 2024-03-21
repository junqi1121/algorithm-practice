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
#include <stack>
#include <queue>
#include <set>
#include <map>
#define endl '\n'
#define gkd ios::sync_with_stdio(0), cin.tie(0)
#define inf 0x3f3f3f3f
#define fi first
#define se second
#define sz(a) (int)a.size()
#define lowbit(x) x & -x
#define all(x) x.begin(), x.end()
#define gcd(a, b) __gcd(a, b)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int N = 1e5 + 10, M = 1e5 + 10;
int n, m;

int h[N], ne[N], e[N], idx;                                                 // 链式前向星
int p[N];                                                                   // 并查集的数组
int dx[] = {0, -1, 0, 1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, 1, -1}; // 方向数组
int primes[N], cnt;
int euler[N];
bool st[N];
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    gkd;
    cin >> n;
    euler[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;

            if (i % primes[j] == 0)
            {
                euler[i * primes[j]] = euler[i] * primes[j];
                break;
            }
            euler[i * primes[j]] = euler[i] * (primes[j] - 1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << euler[i] << endl;
    }
    return 0;
}