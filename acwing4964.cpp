// https://www.acwing.com/problem/content/description/4967/
// 单调队列滑动窗口扫描两遍！
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <cmath>
#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 1e5 + 10, M = 1e5 + 10;
int n, m;
int h[N], ne[N], e[N], idx;
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int main()
{
    cin >> n >> m;
    cout << n + m;
    return 0;
}