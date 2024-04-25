#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int n, ma;
int main()
{
    cin >> n >> ma;
    bool ff = 0;
    for (int i = 0; i * i <= ma * 1000 + 1000; i++)
    {
        int a = -1;
        bool flag = 1;
        for (int j = 0; j < n; j++)
        {
            if (a == -1)
            {
                a = (i + j) * (i + j) / 1000 - j;
            }
            else
            {
                if (a != (i + j) * (i + j) / 1000 - j)
                    flag = 0;
            }
        }
        if (flag)
            cout << a << ' ' << i << endl, ff = 1;
    }
    if (!ff)
        puts("No Solution.");
    return 0;
}