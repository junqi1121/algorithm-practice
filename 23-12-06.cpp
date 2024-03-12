//https://www.luogu.com.cn/problem/P1352
//注意判断上司节点
//递归出口设了之后似乎会错？为啥 

#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
using namespace std;
const int N = 6e3 + 10;
int n;
int happy[N];
int h[N], ne[N], e[N], idx;
bool has_fa[N];
void add(int l, int k)
{
    e[idx] = k;
    ne[idx] = h[l];
    h[l] = idx++;
}

pair<int, int> dfs(int x)
{
	if(h[x]==-1)
	{
		return {happy[x],0};
	 } 
    int x_s = happy[x], x_not_s = 0;
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        int j_s, j_not_s;
        auto result =  dfs(j);
        j_s = result.first, j_not_s = result.second; 
        x_s += j_not_s;
        x_not_s += max(j_s, j_not_s);
    }
    return {x_s, x_not_s};
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> happy[i];
    for (int i = 1; i < n; i++)
    {
        int l, k;
        cin >> l >> k;
        has_fa[l] = 1;
        add(k, l);
    }
    int root_s, root_not_s;
    int root=1; 
    while (has_fa[root])root++;//找到没有上司的节点，即为根节点<公司大boss> 
    auto result = dfs(root);
	root_s = result.first, root_not_s = result.second;
    cout << max(root_s, root_not_s);
    return 0;
}

