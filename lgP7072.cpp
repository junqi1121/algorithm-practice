#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int n, w;
int a[N];
int main()
{
    cin >> n >> w;
    // 对顶堆，一个小根，一个大根   也就是优先队列 priority_queue
    priority_queue<int, vector<int>, greater<int>> small;
    priority_queue<int> big;
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int now = max(1, i * w / 100);

        // 小根堆的数量应该满足的条件   now<= c1 <= 某个数字
        // 但是我只输出分数线。所以我就维护到now那个位置！
        // 我需要保证 small.top()>=big.top() 且小根堆的个数是now

        if (c1 < now)
        {
            if (c2 != 0 && big.top() > a[i])
            {
                small.push(big.top());
                c1++;
                big.pop();
                big.push(a[i]);
            }
        }
        else
        {
            // c1=now
            if (a[i] > small.top())
            {
                big.push(small.top());
                c2++;
                small.pop();
                small.push(a[i]);
            }
        }
        while (c1 < now)
        {
            small.push(big.top());
            big.pop();
            c1++;
            c2--;
        }
        cout << small.top() << ' ' << endl;
    }
    return 0;
}

// 另外此题真正想要训练的思维是，依据数据范围选取最佳的算法，一定要仔细地观察他的数据范围
// 数据的个数，每个数据的范围
// 有时候这些范围会给出很好的遍历方式！！

// 常见的优化思想！需要训练！！