#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 30+5,A = 1e4+10;
int n,x;
int a[N];
int dp[N*A];  // dp[i][j]  ��ʾ��ǰi������ѡ��Ԥ��Ϊj������£���໨����Ǯ�� 
//����Ҫ ���dp[n][sum-x] 
int main()
{
	cin>>n>>x;
	int sum = 0;
	for(int i = 1;i<=n;i++) 
	{
		cin>>a[i];
		sum+=a[i];
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = sum-x; j>=a[i] ;j--)
		{
			dp[j] = max(dp[j],dp[j-a[i]]+a[i]); 
		}
	}
	cout<<sum-dp[sum-x];
	return 0; 
}
