// 第二遍做题，先得60分，再改成了满分，把第58行算根节点的w移到了循环外部，得了满分。 
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const long long N = 2010,M = 110;
long long n,m;
long long w[N],p;
long long h[N],ne[N],e[N],idx;
long long st[N];

void add(long long a,long long b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

long long cal_weight(long long root)
{
    long long res = w[root];
    for(long long i = h[root]; i!=-1 ;i = ne[i])
    {
        long long j = e[i];
        if(!st[j])
        res += cal_weight(j);
    }
    return res;
}


bool check(long long query,long long a)
{
    if(a==query) return 1;
    for(long long i = h[query];i!=-1;i=ne[i])
    {
        long long j = e[i];
        if(check(j,a)) return 1;
    }
    return 0;
}
void set(long long query,long long x)
{
    st[query] = x;
    for(long long i = h[query];i!=-1;i=ne[i])
    {
        long long j = e[i];
        if(!st[j])
        set(j,x);
    }
}

void solve(long long root,long long a)
{
    //循环遍历剩余的每个类别
    long long wthe_min = 2e10+10,query;
    long long w_root=cal_weight(root);
    for(long long i=1;i<=n;i++)
    {
        long long wei1,wei2;
        long long wthe;
        if(!st[i])
        {

            // 计算其后代权重之和，wei1
            wei1 = cal_weight(i);
            // 其余全部类别之和，wei2
            wei2 = w_root-wei1;
            wthe = abs(wei1-wei2);
            // 选出最小的那个类
            if(wthe<wthe_min)
            {
                wthe_min = wthe;
                query = i;
            }
        }
    }
    //判断a是query的后代否？
    bool flag = check(query,a);

    // 如果 是这个类
    //	把除了其后代的子类全部去掉 ,首先把他的后代的st设置为2，然后把所有非2设成1，再把2设成0
    if(flag)
    {
        set(query,2);
        for(long long i=1;i<=n;i++)
        {
            if(st[i]!=2) st[i] = 1;
            else st[i] = 0;
        }
    }
    else{
        //	如果不是这个类
        //  去掉它和它的后代
        set(query,1);
    }

    cout<<query<<' ';
    long long sum = 0;
    for(long long i = 1;i<=n;i++)
    {
        sum+=st[i];
    }

    if(sum!=n-1)
    {
        if(flag)
            solve(query,a);
        else
            solve(root,a);
    }

}

int main()
{
    cin>>n>>m;
//	n=2000,m=100;
    for(long long i=1;i<=n;i++)
    {
        cin>>w[i];
//		w[i] = 10000000;
    }

    memset(h,-1,sizeof h);

    for(long long i = 2;i <= n;i++)
    {
        cin>>p;
//		p = i-1;
        // 读到p是i的父节点
        add(p,i);
    }
    for(long long i = 1;i<=m;i++)
    {
        long long a;
        cin>>a;
//		a = i;
        solve(1,a);
        cout<<endl;
        memset(st,0,sizeof st);
    }
    return 0;
}

