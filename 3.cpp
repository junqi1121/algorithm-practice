#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<utility>
#include<unordered_map>
#include<unordered_set>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2010, M = 110;

int n, m;
ull w[N];
int h[N], ne[N], e[N], idx;
int st[N];  // 状态数组
ull wt[N];  // 以其为根的树的权值
ull ssum = 0, sum = 0;  // 总和、函数中每次迭代后剩余的总和

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int x) {
    // 获取x为根的树的权值之和
    wt[x] = w[x];
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        dfs(j);

        if (!st[j])  //被排除的子节点不加
            wt[x] += wt[j];
    }
}

void ddfs(int t, int x) {
    // 给以节点t为根的树，状态数组st赋值为x
    
    st[t] = x;
    for (int i = h[t]; i != -1; i = ne[i]) {
        int j = e[i];

        if (!st[j])  // 被排除的节点，就不再继续往下了
            ddfs(j, x);
    }
}


ull my_abs(ull a, ull b) {
    return a > b ? a - b : b - a;
}



bool check(int tem, int t) {
    // 检查tem是否是t的后代
    if (tem == t)
        return 1;
    else {
        for (int i = h[t]; i != -1; i = ne[i]) {
            // 依次检查其是否是t的儿子的后代，如果是，就直接返回
            int j = e[i];
            int a = check(tem, j);
            if (a)
                return 1;
        }
    }
    return 0;
}

void solve(int t) {
    memset(st, 0, sizeof st);
    memset(wt, 0, sizeof wt);
    sum = ssum;
    
    int root = 1;
    for (int ii = 1; ii <= n; ii++) {
        //wt  按照算法计算出值
        dfs(1);
        // 选出最小的那个 tem
        int tem = 0;
        ull wm = INF;
        for (int i = 1; i <= n; i++) {
            if (st[i]) continue;
            ull wtt = my_abs(sum - wt[i], wt[i]);
            if (wm > wtt) {
                wm = wtt;
                tem = i;
            }
        }

        cout << tem << ' ';
        
        // tem == t 回答为是 保留tem及其后代
        // 判断 t是否是tem的后代
        int flag = check(t, tem);

        if (flag) {
            //将t及其后代的状态至为2
            ddfs(tem, 2);
            for (int i = 1; i <= n; i++) {
                if (st[i] == 2) st[i] = 0;
                else if (st[i] == 0) st[i] = 1;
            }
            sum = wt[tem];
            root = tem; 
        }


        // tem！=t 回答为否 去掉tem 及其后代
        else {
            //将tem及其后代的状态至为1
            ddfs(tem, 1);
            sum -= wt[tem];
        }

        //检测 现在剩余的数量是否为 1    break；
        int num = 0;
        for (int i = 1; i <= n; i++) {
            if (!st[i]) num++;
        }

        if (num == 1) break;
    }
    cout << endl;
}


int main() {
	cin >> n >> m;
//n = 2000;
//m = 1;
    memset(h, -1, sizeof h);
    idx = 0;

    for (int i = 1; i <= n; i++) {
		cin >> w[i];
//w[i] = 10000000;
        ssum += w[i];
    }
    for (int i = 2; i <= n; i++) {
        int p;
		cin >> p;
//p = i-1;
        add(p, i);
    }

    for (int i = 1; i <= m; i++) {
        int t;
//        t = 1999;
		cin >> t;
        solve(t);
    }
    return 0;
}
