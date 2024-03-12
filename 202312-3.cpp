// �ڶ������⣬�ȵ�60�֣��ٸĳ������֣��ѵ�58������ڵ��w�Ƶ���ѭ���ⲿ���������֡� 
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
    //ѭ������ʣ���ÿ�����
    long long wthe_min = 2e10+10,query;
    long long w_root=cal_weight(root);
    for(long long i=1;i<=n;i++)
    {
        long long wei1,wei2;
        long long wthe;
        if(!st[i])
        {

            // ��������Ȩ��֮�ͣ�wei1
            wei1 = cal_weight(i);
            // ����ȫ�����֮�ͣ�wei2
            wei2 = w_root-wei1;
            wthe = abs(wei1-wei2);
            // ѡ����С���Ǹ���
            if(wthe<wthe_min)
            {
                wthe_min = wthe;
                query = i;
            }
        }
    }
    //�ж�a��query�ĺ����
    bool flag = check(query,a);

    // ��� �������
    //	�ѳ�������������ȫ��ȥ�� ,���Ȱ����ĺ����st����Ϊ2��Ȼ������з�2���1���ٰ�2���0
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
        //	������������
        //  ȥ���������ĺ��
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
        // ����p��i�ĸ��ڵ�
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

