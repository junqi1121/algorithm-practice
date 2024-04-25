#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int N = 10;
int k;
int a[N];
int f[N][N][N][N][N];
int main()
{
    while (true)
    {
        cin >> k;
        if (k == 0)
            break;
        memset(f, 0, sizeof f);
        f[0][0][0][0][0] = 1;
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i];
        }
        for (int a1 = 1; a1 <= a[1]; a1++)
        {
            for (int a2 = 1; a2 <= a[2]; a2++)
            {
                for (int a3 = 1; a3 <= a[3]; a3++)
                {
                    for (int a4 = 1; a4 <= a[4]; a4++)
                    {
                        for (int a5 = 1; a5 <= a[5]; a5++)
                        {
                        }
                    }
                }
            }
        }
    }
    return 0;
}