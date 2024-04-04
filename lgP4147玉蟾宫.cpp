// https://www.luogu.com.cn/problem/P4147
// 有点想不到优化的方法……

#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
const int N = 1e3 + 10, M = 1e3 + 10;
int n, m;
bool map[N][M];
int up[M], left[M], right[M];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char aa;
            cin >> aa;
            map[i][j] = aa == 'F';
            if (map[i][j])
            {
                up[j]++;
            }
            else
            {
                up[j] = 0;
            }
                }
    }

    return 0;
}
