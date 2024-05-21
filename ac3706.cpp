#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 30;
int n;
long long ans;
long long f[N][2];
int main()
{
    cin >> n;
    f[1][1] = 1;
    f[1][0] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i][0] = f[i - 1][1] + f[i - 1][0];
        f[i][1] = f[i - 1][0];
    }
    cout << f[n][1] + f[n][0];
    return 0;
}