#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N = 510, M = 5010;
int n, m;
int h[N], ne[M], e[M], idx;
int d[N]; // 记录一下入度
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void topsort()
{
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 1; i <= n; i++)
    {
        if (!d[i])
            heap.push(i);
    }
    while (heap.size())
    {
        auto t = heap.top();
        cout << t << ' ';
        heap.pop();
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j]--;
            if (!d[j])
            {
                heap.push(j);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        d[b]++;
        add(a, b);
    }
    topsort();
    return 0;
}