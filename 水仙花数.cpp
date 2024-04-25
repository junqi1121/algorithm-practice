// 题是简单题，但是需要学习一下多组数据输入的处理！！
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int N = 999;

int n, m;
bool check(int x)
{
    string a = to_string(x);
    int ret = 0;
    for (auto y : a)
    {
        ret += ((y - '0') * (y - '0') * (y - '0'));
    }
    return ret == x;
}
int main()
{
    while (cin >> n >> m, n != 0 && m != 0)
    {
        vector<int> ans;
        for (int i = n; i <= m; i++)
        {
            if (check(i))
                ans.push_back(i);
        }
        if (!ans.size())
            puts("no");
        else
        {
            for (auto x : ans)
            {
                cout << x << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
