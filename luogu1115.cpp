#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int dp[N];
int n;
int main()
{
    cin >> n;
    int ans = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        // 如果包含第i个数
        if (dp[i - 1] >= 0)
            dp[i] = dp[i - 1] + a[i];
        else
            dp[i] = a[i];
        // cout << dp[i] << ' ';
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}

// 我之前写的代码  现在有些不理解了
// #include<iostream>
// #include<algorithm>
// using namespace std;
// int b[2],ret=-2147483467;
// int main()
// {
// 	int n = 0,a;
// 	cin >> n;
// 	for (int i = 0; i < n; i++)
// 	{
// 		cin >> a;
// 		if (i == 0)
// 			b[i] = a;
// 		else
// 		{
// 			b[i%2] = max(a, b[(i - 1)%2] + a);
// 			ret = max(b[i%2], ret);
// 		}
// 	}
// 	cout << ret;
// 	return 0;
// }