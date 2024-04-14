#include<iostream>
#include<cstring>
#include<algorithm>
#define endl '\n'
using namespace std;
const int N=1e5+10,MOD=1e9+7,A=1e6+10;
int n;
int a[N];
int st[A];
int main()
{
	
	cin>>n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long ans=n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	st[a[1]]++;
	int i=1,j=2;
	for(;i<=n&&j<=n&&i<=j;j++)
	{
		st[a[j]]++;
		if(st[a[j]]==1)
			ans++,ans%=MOD;
		int flag=0;
		while(st[a[j]]>1&&i<=j)
		{
			st[a[i]]--;
			i++;
			flag=1;
		}
		if(flag&&j>i)
			ans++,ans%=MOD;
	}
	while(i<n)
	{
		if(a[i]==1)
		{
			ans++,ans%=MOD;
		}
		i++;
	}
	cout<<ans;
	return 0;
} 
