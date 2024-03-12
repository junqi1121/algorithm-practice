#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5+10,M = 1e5+10,K = 1e5+10;
int n,k,l,m;
int a[M];
int main()
{
    cin>>n>>k>>l;
    m = k*n;
    for(int i = 1;i <= m;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+m);
    int sum = 0;
    for(int i = 1;i<=m;i++)
    {
        if(a[i] <= a[1]+l) sum++;
    }
    if(sum<n){
        puts("0");
        return 0;
    }
    long long ans = 0;
    int num;
    if(k>1)
        num = (sum-n)/(k-1);
    else
    {
        num = 0;
    }
    for(int i=1;i<=num;i++)
    {
        ans += a[1+i*k-k];
    }
    for(int i = 0; i < n-num; i++)
    {
        ans += a[sum-i];
    }
    cout<<ans;
    return 0;

}

