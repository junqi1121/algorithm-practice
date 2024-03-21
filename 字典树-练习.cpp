// https: // www.luogu.com.cn/problem/P8306
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;
const int N = 1e5 + 10, M = 3e6 + 10;
int son[M][100], cnt[M], idx;
// 此处son[i][j] 表示从节点i，沿着j这条边走，能够到达的节点标号
// cnt[i] 表示以i节点结尾的字符串的个数
// idx 表示使用到的节点的标号
// 字典树，节点是编号，边表示的是字符！

// 建议看b站董晓算法 【F06 字典树(Trie)】 https://www.bilibili.com/video/BV1yA4y1Z74t/?share_source=copy_web&vd_source=c75bd7ab7f1140cd5c514a9da8ebd00b
int n, q;
string s;
int T;
// int dfs(int p)
// {
//     int ans = cnt[p];
//     for (int i = 0; i < 100; i++)
//     {
//         if (son[p][i])
//             ans += dfs(son[p][i]);
//     }
//     return ans;
// }
void insert(string s)
{
    int p = 0;
    for (auto x : s)
    {
        int u;
        if (x >= 'a' && x <= 'z')
        {
            u = x - 'a';
        }
        else if (x >= 'A' && x <= 'Z')
        {
            u = 27 + x - 'A';
        }
        else
        {
            u = x - '0' + 56;
        }
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
        cnt[p]++;
    }
}
int query(string s)
{
    int p = 0;
    for (auto x : s)
    {
        int u;
        if (x >= 'a' && x <= 'z')
        {
            u = x - 'a';
        }
        else if (x >= 'A' && x <= 'Z')
        {
            u = 27 + x - 'A';
        }
        else
        {
            u = x - '0' + 56;
        }

        if (!son[p][u])
            return 0;
        p = son[p][u];
    }

    return cnt[p];
}
void solve()
{
    memset(son, 0, sizeof son);
    memset(cnt, 0, sizeof cnt);
    idx = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        insert(s);
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> s;
        cout << query(s) << endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}