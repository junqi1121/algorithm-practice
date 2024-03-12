#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int N=5000+10;
int dp[N][N]; 
string s;
int main()
{
	cin>>s;
	int ans = 0;
	for(int i=s.size()-1;i>=0;i--)
	{
		dp[i][i]=1;
		for(int j = i+1;j<s.size();j++)
		{
			if(s[i] > s[j]) dp[i][j] = 1;
			if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
		}
	}
	for(int i=0;i<s.size();i++)
	{
		for(int j = i+1;j<s.size();j++)
		{
			ans+=dp[i][j];
		}
	}
	cout<<ans;
	return 0;
}
