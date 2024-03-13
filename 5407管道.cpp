#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10, S = 1e9 + 10, LEN = 1e9 + 10;
int n, len;
int l[N], s[N];
int q[N];
//  超时，因为前缀和下的check函数复杂度太高，为len*（log_len)

// 所以需要用区间合并的方式！

bool check(int x)
{
	memset(q, 0, sizeof q);
	// 前缀和？
	for (int i = 1; i <= n; i++)
	{
		if (x >= s[i])
		{
			int ll = l[i] - (x - s[i]), r = l[i] + x - s[i];
			// 那么第li-(x-si) 到 li+(x-si) 这一段数字全都加一
			q[max((long long)1, (long long)l[i] - (x - s[i]))]++;
			q[min((long long)len + 1, (long long)l[i] + x - s[i] + 1)]--;
		}
	}
	for (int i = 1; i <= len; i++)
	{
		q[i] = q[i] + q[i - 1];
		if (q[i] <= 0)
			return 0;
	}
	return 1;
}
int main()
{
	cin >> n >> len;
	for (int i = 1; i <= n; i++)
		cin >> l[i] >> s[i];
	int l = 0, r = 1e9 + 10;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << r;
	return 0;
}
