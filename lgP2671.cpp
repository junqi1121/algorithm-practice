#include <cstdio>
using namespace std;
int sum[2][100001] = {0}, g[2][100001] = {0}, num[100001], col[100001], n, c;
long long maxx = 0;
int main()
{
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
        num[i] = num[i] % 10007; // 先模一次
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &col[i]);
        sum[i % 2][col[i]] = (sum[i % 2][col[i]] + num[i]) % 10007; // 颜色相同且奇偶性相同的一堆中加入现在这一个，然后再模一遍
        g[i % 2][col[i]]++;                                         // 里面的数个数++
    }
    for (int i = 1; i <= n; i++)
    {
        maxx = maxx + (i % 10007 * ((sum[i % 2][col[i]] + (g[i % 2][col[i]] - 2) % 10007 * num[i] + 10007) % 10007)) % 10007; // 这个就是在用楼下说过的那个公式了，把所有放到一起之后直接求和，还得边乘边模……
    }
    printf("%d", maxx % 10007); // 最后模一遍
    return 0;
}