#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
int n;

// 文件树的保存 树形结构
int h[N], ne[N], e[N], idx;
struct FILEE
{
    string name; // 名字
    int type;    // 类型 1-目录文件 2-普通文件
    ll lr = 0;
    ll ld = 0; // 目录配额：ld，后代配额 lr 初始化为0，表示先不做限制
    ll now_r = 0;
    ll now_d = 0;

    // 默认构造函数
    FILEE() : name(""), type(1), lr(0), ld(0), now_r(0), now_d(0) {}

    // 添加构造函数
    FILEE(string name, int type, ll lr, ll ld, ll now_r, ll now_d) : name(name), type(type), lr(lr), ld(ld), now_r(now_r), now_d(now_d) {}

} file[N];

int f_i = 1;

vector<string> my_spilt(string path)
{
    path += "/";
    vector<string> ans;
    for (int i = 0, j = 0; i < path.size(); i++)
    {
        if (path[i] == '/' && i != j)
        {
            ans.push_back(path.substr(j + 1, i - j - 1));
            j = i;
        }
    }
    return ans;
}

void solve_create(string path, ll sz)
{
    // 创建命令！
    auto p_vec = my_spilt(path);
    int ii = 0, len = p_vec.size();

    int now_file = 0;
    if (file[0].lr && file[0].now_d + sz > file[0].ld)
    {
        // 根目录的后代配额
        puts("N");
        return;
    }
    // 首先检查路径是否合法
    if (len == 1)
    {
        // 直接在根目录下建普通文件
        if (file[0].lr && file[0].now_d + sz > file[0].ld)
        {
            puts("N");
            return;
        }

        // 在根目录下创建文件
        for (int i = h[now_file]; i != -1; i = ne[i])
        {
            int file_idx = e[i];
            if (file[file_idx].name == p_vec[0] && file[file_idx].type == 1)
            {
                puts("N");
                return;
            }
        }
    }

    while (ii < len - 1)
    {
        int flag = 1;
        for (int i = h[now_file]; i != -1; i = ne[i])
        {
            int file_idx = e[i];
            if (file[file_idx].name == p_vec[ii])
            {
                flag = 0;
                // i!=len-1  表示我需要的是目录字符串
                // 有一个同名的普通文件在这个目录下
                if (file[file_idx].type == 2)
                {
                    puts("N");
                    return;
                }
                //                if (file[file_idx].ld != 0 && file[file_idx].now_d + sz > file[file_idx].ld) {
                //                    // 目录配额ld 且会超！  孩子文件中的普通文件！！！
                //                    puts("N");
                //                    return;
                //                }
                if (file[file_idx].lr && file[file_idx].now_r + sz > file[file_idx].lr)
                {
                    // 配置过lr，且会超所有后代中的文件！！  后代配额！！
                    puts("N");
                    return;
                }

                if (ii == len - 2 && file[file_idx].ld && file[file_idx].now_d + sz > file[file_idx].ld)
                {
                    //  如果是最后一级，还需要检测目录配额
                    puts("N");
                    return;
                }

                ii++;
                now_file = file_idx;
                break;
            }
        }
        if (flag)
            break; // 表示这个目录下面没有所需要的目录，后面的路径都需要自己创建。
    }

    int fflag = 0;
    // 查看最后一级的目录上面是否已经有这个目录名字！
    if (ii == len - 1)
        for (int i = h[now_file]; i != -1; i = ne[i])
        {
            int file_idx = e[i];
            if (file[file_idx].name == p_vec[ii] && file[file_idx].type == 1)
            {
                puts("N");
                return;
            }
            if(file[file_idx].name == p_vec[ii] && file[file_idx].type == 2)
            {
                fflag = 1;
                break;
            }
        }
    
    // 上方边检测沿路的已存在的路径是否合法，边检测这些目录的配额是否能够满足
    // 下面就需要创建文件了，由于不合法的全都返回了，下面的逻辑都是一定能够创建的！
    puts("Y");
    // 真的去创建文件   边创建边维护 now_r now_d
    int i;
    // 首先是已经存在目录的部分
    for (i = 0, now_file = 0; i < ii; i++)
    {
        for (int j = h[now_file]; j != -1; j = ne[j])
        {
            int file_idx = e[j];
            if (file[file_idx].name == p_vec[i])
            {
                file[file_idx].now_r += sz;
                if (i == len - 2)
                {
                    // 最后一级目录需要加上孩子配额。
                    file[file_idx].now_d += sz;
                }
                now_file = file_idx;
                break;
            }
        }
    }

    // 需要新创建的目录的部分
    while (ii < len - 1)
    {
        // file[f_i] = {name : p_vec[ii], type : 1, lr : 0, ld : 0, now_r : sz, now_d : 0};
        file[f_i] = FILEE(p_vec[ii], 1, 0, 0, sz, 0);

        if (ii == len - 2)
        {
            file[f_i].now_d = sz;
        }
        e[idx] = f_i;
        ne[idx] = h[now_file];
        h[now_file] = idx++;
        ii++;
        now_file = f_i++;
    }


    file[f_i] = FILEE(p_vec[ii], 2, 0, 0, sz, 0);

    e[idx] = f_i++;
    ne[idx] = h[now_file];
    h[now_file] = idx++;

    // 如果这里已经有这个文件，那么需要替换，并且更新前方的now_ld now_lr
    // 此处向上递归更新文件？
    
}

void solve_rmove(string path)
{
    // 删除命令！
    puts("Y"); // 这个指令认为始终能够执行成功！

    // 移除链表的操作！
    auto p_vec = my_spilt(path);
    int ii = 0, len = p_vec.size();
    int now_file = 0;
    while (ii < len - 1)
    {
        int flag = 1;
        for (int i = h[now_file]; i != -1; i = ne[i])
        {
            int file_idx = e[i];
            if (file[file_idx].name == p_vec[ii] && file[file_idx].type == 1)
            {
                flag = 0;
                ii++;
                now_file = file_idx;
                break;
            }
        }
        if (flag) // 压根没有这个目录
            return;
    }

    // 最后一层了 查看有没有这个文件
    for (int i = h[now_file], pre = now_file; i != -1; i = ne[i])
    {
        int file_idx = e[i];
        if (file[file_idx].name == p_vec[ii])
        {
            // 这个文件同名的普通文件
            if (file[file_idx].type == 2)
            {
                // 是普通文件
                // 删除这个链表，然后就break；
                ne[pre] = ne[i];
                break;
            }
        }
        pre = i;
    }
}

void solve_qua(string path, ll ld, ll lr)
{
    // 设置配额命令！
    puts("Y");
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n;
    while (n--)
    {
        char ty;
        cin >> ty;
        if (ty == 'C')
        {
            string path;
            ll sz;
            cin >> path >> sz;
            solve_create(path, sz);
        }
        else if (ty == 'R')
        {
            string path;
            cin >> path;
            solve_rmove(path);
        }
        else if (ty == 'Q')
        {
            string path;
            ll ld, lr;
            cin >> path >> ld >> lr;
            solve_qua(path, ld, lr);
        }
    }
    return 0;
}
