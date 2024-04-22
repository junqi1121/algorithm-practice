// 状压dp！
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20, M = 1 << N;
int n, d[N][N], dp[M][N]; // dp[i][j]，从点0到点j，走的路程的状态压缩的数值为i，，，存下的最短距离

//	状态压缩dp
//	0--n-1的不同排列 共有n的阶乘种方式
//	用状态压缩dp来优化到2^n
//   0-2^n-1  一共2^n个数，其中为一的位代表目前的路径选择了该位对应的点；

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> d[i][j];

    memset(dp, 0x3f, sizeof dp);

    dp[1][0] = 0;

    for (int i = 0; i < 1 << n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >> j & 1)
            {
                // 这里是要更新dp[i][j]
                // 这个判定进来后就代表  被经过的点的二进制状态数为i， 此时处于点j
                for (int k = 0; k < n; k++)
                {
                    // 枚举上一时刻可能经过的点
                    // 上一时刻的二进制状态  : i^(1<<j) 或者 i-(1<<j)
                    if ((i ^ (1 << j)) >> k & 1)
                    {
                        // 上一个时刻可能经过k点
                        dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + d[k][j]);
                    }
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1];
    return 0;
}