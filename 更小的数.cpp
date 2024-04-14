#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int N = 5000+10;
int a[N];
int dp[N][N];
string s;
int main()
{
	cin>>s;
	int i=1;
	for(auto x:s)
		a[i++] = x-'0'; 
	int n = s.size();
	for(int i=n;i>=1;i--)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(i==j) dp[i][j] = 0;
			if(a[j]<a[i]) dp[i][j] = 1;
			if(a[i]==a[j]) dp[i][j] = dp[i+1][j-1];
		}
	}
	
	int ans = 0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans+=dp[i][j];
	
	cout<<ans;
	return 0;
} 
