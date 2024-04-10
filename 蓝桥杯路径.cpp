#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;
const int N = 2021 + 10, M = N * N;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], st[N];
typedef pair<int, int> PII;
void add(int a, int b, int ww)
{
    e[idx] = b;
    w[idx] = ww;
    ne[idx] = h[a];
    h[a] = idx++;
}
void dijskra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    while (!heap.empty())
    {
        auto t = heap.top();
        heap.pop();
        int nex = t.second, d = t.first;
        if (st[nex])
            continue;
        st[nex] = 1;
        for (int i = h[nex]; i != -1; i = ne[i])
        {
            int xia = e[i], weight = w[i];
            if (!st[xia])
            {
                dist[xia] = min(dist[xia], dist[nex] + weight);
                heap.push({dist[xia], xia});
            }
        }
    }

    // // st[1] = 0;
    // for (int i = 1; i <= 2021; i++)
    // {
    //     int t = -1;
    //     for (int j = 1; j <= 2021; j++)
    //     {
    //         if (!st[j] && (t == -1 || dist[t] > dist[j]))
    //         {
    //             t = j;
    //         }
    //     }
    //     st[t] = 1;
    //     for (int j = h[t]; j != -1; j = ne[j])
    //     {
    //         int xia = e[j], weight = w[j];
    //         dist[xia] = min(dist[xia], dist[t] + weight);
    //     }
    // }
}
int main()
{
    memset(h, -1, sizeof h);
    for (int i = 1; i <= 2021; i++)
    {
        for (int j = 1; j <= 2021; j++)
        {
            if (abs(i - j) > 21 || i == j)
                continue;
            int lcm = i / __gcd(i, j) * j;
            add(i, j, lcm);
        }
    }
    dijskra();
    cout << dist[2021] << endl;
    // cout << 0x3f3f3f3f;
    return 0;
}