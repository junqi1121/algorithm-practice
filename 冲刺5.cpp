#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e3+10;
int n;
int a[N];
int dp[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i] = a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j]<a[i])
			{
				dp[i] = max(dp[i],dp[j]+a[i]);
			} 
		}
	}
	int ans=-1;
	for(int i=1;i<=n;i++) ans = max(ans,dp[i]);
	cout<<ans;
	return 0;
}
