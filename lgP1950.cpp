// https : // www.luogu.com.cn/problem/P1950
// 单调栈的二维情况？
// 悬线法？
//
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10, M = 1e3 + 10;
int n, m;
char map[N][M];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];

    return 0;
}
