#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 510,M = 510;
int n,m,k;
int a[N][M];
int main()
{
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=m;j++)
		{
			cin>>a[i][j];
			a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		}
	long long ans = 1;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			for(int s=1,t=1;t<=n&&s<=t;t++)
			{
				while(s<=t&&a[t][j]-a[t][i-1]-a[s-1][j]+a[s-1][i-1]>k) s++;
				if(s<=t){
					ans+=(t-s+1);
				}
			}
		}
	}
	 
			
	
}
