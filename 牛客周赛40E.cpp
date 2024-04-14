#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int dp[N];
int n, x, y;
int main()
{
    cin >> n >> x >> y;
    if (x * 4 <= y * 3)
    {
        cout << n * n / 4 * y;
        return 0;
    }
    return 0;
}