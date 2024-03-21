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
    for (int i = 1; i <= n; i++)
    {
        small.push(i);
        big.push(i);
        cout << "small: " << small.top() << endl;
        cout << "big: " << big.top() << endl;
    }
    small.pop();
    cout << small.top();
    small.push(-1);
    cout << small.top();
    return 0;
}
