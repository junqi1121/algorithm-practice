#include <iostream>
#include <cstdio>
#include<cmath>

using namespace std;
const int N=20;
int main() {
    int n, m;
    int x1[N], x2[N], y1[N], y2[N], x3[N], y3[N], rank[N], g[N];
    cin >> n >> m;
 
    for (int i = 1; i <= n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        rank[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> x3[i] >> y3[i];
        int t = 0;
        for (int q = 1; q <= n; q++) {
            if (x3[i] >= x1[q] && x3[i] <= x2[q] && y3[i] >= y1[q] && y3[i] <= y2[q] && rank[q] > rank[t])
                t = q;
        }
        if(t!=0)
            rank[t] = i + n;
        g[i] = t;
    }
    for (int i = 1; i <= m; i++) {
        if (g[i] == 0) {
            cout << "IGNORED" << endl;
        } else {
            cout << g[i] << endl;
        }
    }
    return 0;

}
