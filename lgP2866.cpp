#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 8e4 + 10;
int n;
int a[N];
int st[N], idx = -1;
ll ans = 0;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        while (idx != -1 && a[st[idx]] <= a[i])
        {
            idx--;
        }
        ans += (idx + 1);
        st[++idx] = i;
    }
    cout << ans;
    return 0;
}