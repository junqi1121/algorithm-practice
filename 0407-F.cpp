#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
int n, q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == '1')
        {
            a[i]++;
            a[i + 1]--;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == '1')
        {
            b[i]++;
            b[i + 1]--;
        }
    }
}