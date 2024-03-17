class Solution
{
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
    {
        sort(score.begin(), score.end(), [k](vector<int> &a, vector<int> &b)
             { return a[k] > b[k]; });
        return score;
    }
};

// 此题的可学习点：
// sort函数 自定义 排序方法时，可以使用lambda表达式
//  lambda表达式的使用方法 外边的[]里面可以传入参数，里面的()里面可以传入参数，{}里面是函数体  且[]可以传入多个参数！
// 例子： 后面指定返回值类型
int k1 = 1, k2 = 2;
auto myLambda = [k1, k2](int a, int b) -> bool
{
    // 使用k1和k2进行某种计算
    return a * k1 < b * k2;
};
