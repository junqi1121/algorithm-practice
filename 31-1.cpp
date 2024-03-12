#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 10, M = 1e5 + 10;

int n, m;
double s_x[N][2], s_y[N][2];s
double i_x[N][2], i_y[N][2];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	s_x[0][0] = 1, s_x[0][1] = 0;
	s_y[0][0] = 0, s_y[0][1] = 1;

	i_x[0][0] = 1, i_x[0][1] = 0;
	i_y[0][0] = 0, i_y[0][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		int a;
		double b;
		cin >> a >> b;
		if (a == 1)
		{
			// lashen
			s_x[i][0] = b * s_x[i - 1][0];
			s_x[i][1] = b * s_x[i - 1][1];

			s_y[i][0] = b * s_y[i - 1][0];
			s_y[i][1] = b * s_y[i - 1][1];

			b = 1 / b;

			i_x[i][0] = b * i_x[i - 1][0];
			i_x[i][1] = b * i_x[i - 1][1];

			i_y[i][0] = b * i_y[i - 1][0];
			i_y[i][1] = b * i_y[i - 1][1];
		}
		else if (a == 2)
		{

			// xuanzhan
			s_x[i][0] = cos(b) * s_x[i - 1][0] - sin(b) * s_y[i - 1][0];
			s_x[i][1] = cos(b) * s_x[i - 1][1] - sin(b) * s_y[i - 1][1];

			s_y[i][0] = sin(b) * s_x[i - 1][0] + cos(b) * s_y[i - 1][0];
			s_y[i][1] = sin(b) * s_x[i - 1][1] + cos(b) * s_y[i - 1][1];

			b *= (-1);

			i_x[i][0] = cos(b) * i_x[i - 1][0] - sin(b) * i_y[i - 1][0];
			i_x[i][1] = cos(b) * i_x[i - 1][1] - sin(b) * i_y[i - 1][1];

			i_y[i][0] = sin(b) * i_x[i - 1][0] + cos(b) * i_y[i - 1][0];
			i_y[i][1] = sin(b) * i_x[i - 1][1] + cos(b) * i_y[i - 1][1];
		}
	}

	for (int i = 1; i <= m; i++)
	{
		int ii, jj, x, y;
		cin >> ii >> jj >> x >> y;
		if (ii > 1)
		{
			printf("%f %f\n", (x * s_x[jj][0] + y * s_x[jj][1]) * i_x[ii - 1][0] + (x * s_y[jj][0] + y * s_y[jj][1]) * i_x[ii - 1][1], (x * s_x[jj][0] + y * s_x[jj][1]) * i_y[ii - 1][0] + (x * s_y[jj][0] + y * s_y[jj][1]) * i_y[ii - 1][1]);
		}
		else
		{
			printf("%f %f\n", x * s_x[jj][0] + y * s_x[jj][1], x * s_y[jj][0] + y * s_y[jj][1]);
		}
	}
	return 0;
}
