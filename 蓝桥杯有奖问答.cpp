#include <iostream>
#include <algorithm>
using namespace std;
const int N = 30 + 10;
int ans = 0;
void dfs(int i, int fen)
{
	// 已经答了i题，得了 fen 分
	if (fen == 100)
		return;
	if (i >= 31)
		return;

	if (fen == 70)
	{
		ans++;
	}

	dfs(i + 1, 0);
	dfs(i + 1, fen + 10);
}
int main()
{
	// 请在此输入您的代码
	dfs(0, 0);
	cout << ans;
	return 0;
}