class Solution
{
    struct Node
    {
        int x, y;
        bool operator<(const Node &t) const
        {
            if (x != t.x)
                return x < t.x;
            else
                return y < t.y;
        }
    };

public:
    vector<long long> unmarkedSumArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<long long> ans;
        long long sum = 0;
        for (auto x : nums)
            sum += x;

        bool st[100000] = {0};
        vector<Node> tem;
        for (int i = 0; i < nums.size(); i++)
        {
            tem.push_back({nums[i], i});
        }

        sort(tem.begin(), tem.end());
        int flag = 0;

        for (auto x : queries)
        {
            int idx = x[0], k = x[1];
            if (!st[idx])
            {
                st[idx] = 1;
                sum -= nums[idx];
            }

            for (int i = flag; i < nums.size() && k; i++)
            {
                flag++;
                int iddx = tem[i].y;
                int val = tem[i].x;
                if (st[iddx])
                    continue;

                st[iddx] = 1;
                k--;
                sum -= val;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};

// 需要实现数组的稳定排序，我可以构造一个结构体，然后对结构体进行排序
// 结构体内包含了原来的值和原来的下标

// 需要记忆重载运算符的写法！