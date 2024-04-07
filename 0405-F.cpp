#include <iostream>
#include <cstring>
#include <cstring>
#include <string>
using namespace std;
const int N = 2e5 + 10;
string s;
int l[N], e[N], t[N], c[N], o[N], d[N];
int ans[N];
int main()
{
    cin >> s;
    s += ' ';
    for (int i = 1; i <= s.size() - 1; i++)
    {
        l[i] = l[i - 1];
        e[i] = e[i - 1];
        t[i] = t[i - 1];
        c[i] = c[i - 1];
        o[i] = o[i - 1];
        d[i] = d[i - 1];
        if (s[i] == 'l')
        {
            l[i]++;
        }
        if (s[i] == 't')
        {
            t[i]++;
        }
        if (s[i] == 'c')
        {
            c[i]++;
        }
        if (s[i] == 'o')
        {
            o[i]++;
        }
        if (s[i] == 'd')
        {
            d[i]++;
        }
        if (s[i] == 'e')
        {
            int tem = 0x3f3f3f3f;
            tem = min(tem, l[i]);
            tem = min(tem, e[i] / 2);
            tem = min(tem, t[i]);
            tem = min(tem, c[i]);
            tem = min(tem, o[i]);
            tem = min(tem, d[i]);
            ans[i] = tem;
            e[i]++;
        }
    }
    int num = 0;
    for (int i = 1; i < s.size(); i++)
    {
        while (ans[i])
        {
            cout << i << ' ';
            ans[i]--;
            num++;
        }
    }
    while (num <= s.size() - 1)
    {
        cout << "0 ";
        num++;
    }
    return 0;
}