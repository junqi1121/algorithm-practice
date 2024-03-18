#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#define INF 0x3f3f3f3f
#define sz(a) (int)a.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 10, M = 1e5 + 10;
long long n;
string raw;
string ans;
int flag = 0;
queue<ll> q;
void bfs(int n)
{
    if (flag)
        return;
    for (int i = '0'; i <= '9'; i++)
    {
        string s = to_string(n);
        s += i;
        long long t = stoll(s);
        if (t % 495 != 0)
        {
            q.push(t);
        }
        else
        {
            flag = 1;
            ans = s;
            return;
        }
    }
    while (q.size())
    {
        long long t = q.front();
        q.pop();
        bfs(t);
    }
}

int main()
{
    cin >> n;
    raw = to_string(n);
    if (n % 495 == 0)
    {
        cout << -1;
        return 0;
    }

    bfs(n);
    if (flag)
    {
        cout << ans.substr(sz(raw));
    }
    else
    {
        cout << -1;
    }

    return 0;
}