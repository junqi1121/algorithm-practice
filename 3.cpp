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
int st[N];  // ״̬����
ull wt[N];  // ����Ϊ��������Ȩֵ
ull ssum = 0, sum = 0;  // �ܺ͡�������ÿ�ε�����ʣ����ܺ�

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int x) {
    // ��ȡxΪ��������Ȩֵ֮��
    wt[x] = w[x];
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        dfs(j);

        if (!st[j])  //���ų����ӽڵ㲻��
            wt[x] += wt[j];
    }
}

void ddfs(int t, int x) {
    // ���Խڵ�tΪ��������״̬����st��ֵΪx
    
    st[t] = x;
    for (int i = h[t]; i != -1; i = ne[i]) {
        int j = e[i];

        if (!st[j])  // ���ų��Ľڵ㣬�Ͳ��ټ���������
            ddfs(j, x);
    }
}


ull my_abs(ull a, ull b) {
    return a > b ? a - b : b - a;
}



bool check(int tem, int t) {
    // ���tem�Ƿ���t�ĺ��
    if (tem == t)
        return 1;
    else {
        for (int i = h[t]; i != -1; i = ne[i]) {
            // ���μ�����Ƿ���t�Ķ��ӵĺ��������ǣ���ֱ�ӷ���
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
        //wt  �����㷨�����ֵ
        dfs(1);
        // ѡ����С���Ǹ� tem
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
        
        // tem == t �ش�Ϊ�� ����tem������
        // �ж� t�Ƿ���tem�ĺ��
        int flag = check(t, tem);

        if (flag) {
            //��t��������״̬��Ϊ2
            ddfs(tem, 2);
            for (int i = 1; i <= n; i++) {
                if (st[i] == 2) st[i] = 0;
                else if (st[i] == 0) st[i] = 1;
            }
            sum = wt[tem];
            root = tem; 
        }


        // tem��=t �ش�Ϊ�� ȥ��tem ������
        else {
            //��tem��������״̬��Ϊ1
            ddfs(tem, 1);
            sum -= wt[tem];
        }

        //��� ����ʣ��������Ƿ�Ϊ 1    break��
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
