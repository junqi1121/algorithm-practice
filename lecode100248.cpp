#define sz(a) (int)a.size()

class Solution
{
public:
    bool isSubstringPresent(string s)
    {
        string b = s;
        for (int i = s.size() - 1; i >= 0; i--)
            b[i] = s[s.size() - 1 - i];
        for (int i = 0; i <= (int)s.size() - 2; i++)
        {
            string a = s.substr(i, 2);
            for (int j = 0; j <= b.size() - 2; j++)
            {
                string c = b.substr(j, 2);
                if (a == c)
                    return 1;
            }
        }
        return 0;
    }
};

// Path: lecode100248.cpp
// 一定要注意stl中的size返回值是无符号数，如果和有符号数比较，会出现问题！！
