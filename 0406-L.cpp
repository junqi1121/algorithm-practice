#include <iostream>
#include <cstring>
#include <cstring>
#include <string>

using namespace std;
string s;
int lian(int n)
{
    if (n < 2)
        return 0;
    if (n >= 2 && n <= 6)
        return n - 1;
    if (n > 6)
        return 5;
    return 1;
}
int main()
{
    cin >> s;
    int n = 0;
    long long ans = 0;
    for (auto x : s)
    {
        if (x == '1')
        {
            n++;
            ans = ans + 3 + lian(n);
        }
        else
        {
            n = 0;
            ans -= 12;
        }
    }
    cout << ans;
    return 0;
}