#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N = 1e4 + 10;
int n;
long long a, b;
int main()
{
    cin >> n;
    long long v_max = inf, v_min = -1;

    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        v_max = min(v_max, a / b);
        v_min = max(v_min, (a + b) / (b + 1));
    }
    cout << v_min << ' ' << v_max;
    return 0;
}